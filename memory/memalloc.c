#include "memalloc.h"
#include <stdio.h>

struct q_memchunk{
	MemChunk *prev;
	MemChunk *next;
};

/*GARBAGE COLLECTION*/

static MemChunk *gclist = NULL;
int gc = 0; //Set to 1 if garbage collector is running, otherwise 0

/*RAW ALLOC FUNCTIONS*/

void *Q_RawAlloc(size_t size){
	return malloc(size ? size : 1);
}

void Q_RawFree(void *p){
	free(p);
}

void *Q_RawRealloc(void *p, size_t new_size){
	return realloc(p, new_size);
}

void *Q_RawCalloc(size_t num, size_t size){
	return calloc(num, size);
}

/*BIG ALLOC FUNCTIONS*/

//We want to use these bigalloc functions for really large memory allocations, 128k or above

#if HAVE_MMAP

#include <sys/mman.h>

void *Q_BigAlloc(size_t size){
	void *p = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);

	if(p == MAP_FAILED)
		return NULL;

	assert(p != NULL);

	return p;
}

void Q_BigFree(void *p, size_t size){
	munmap(p, size);
}

#elif WINDOWS

void *Q_BigAlloc(size_t size){
	return VirtualAlloc(NULL, size, MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
}

void Q_BigFree(void *p, size_t size){
	VirtualFree(p, size, MEM_RELEASE);
}
	
#else

void *Q_BigAlloc(size_t size){
	return Q_RawAlloc(size);
}

void Q_BigFree(void *p, size_t size){
	return Q_RawFree(p);
}

#endif

void *Q_Alloc(size_t size){
	if(size & BIG_ALLOC_SIZE)
		return Q_BigAlloc(size);
	else
		return Q_RawAlloc(size);
}

void Q_Free(void *p, size_t size){
	if(size & BIG_ALLOC_SIZE)
		Q_BigFree(p, size);
	else
		Q_RawFree(p);
}

//Q_ObjectAlloc also adds the MemChunk header and adds the object onto the garbage collected list
//Objects are automatically added to the end of the list

Q_Object *Q_ObjectAlloc(size_t size){
	MemChunk *memory = Q_Alloc(sizeof(MemChunk) + size);

	memory->prev = NULL;
	memory->next = NULL;

	if(gclist != NULL){
		memory->next = gclist;
		gclist->prev = memory;
	}

	gclist = memory;

	return (Q_Object *)(memory + 1);
}

void Q_ObjectFree(Q_Object *object){
	MemChunk *memory = (MemChunk *)object - 1;

	if(memory->prev != NULL){
		memory->prev->next = memory->next;

		if(memory->next != NULL)
			memory->next->prev = memory->prev;
	}
	else{
		if(memory->next != NULL)
			memory->next->prev = NULL;
		gclist = memory->next;
	}

	Q_Free(memory, (sizeof(MemChunk) + object->type->size));
}

void runGC(){
	gc = 1;

	MemChunk *memory = gclist;

	if(gclist == NULL)
		printf("It's empty\n");

	while(memory != NULL){
		Q_Object *object = (Q_Object *)(memory + 1);

		if(!object->refs){
			memory = memory->next;
			object->type->destructor((Q_Value *)object);
			printf("Removed junk!\n");
		}else{
			memory = memory->next;
		}
	}

	if(memory == NULL) //ADD REFERENCE COUNTING TO REFERENCE SET
		gclist = NULL;

	gc = 0;
}

void clearHeap(){
	MemChunk *memory = gclist;

	while(memory != NULL){
		Q_Object *object = (Q_Object *)(memory + 1);

		memory = memory->next;
		object->type->destructor((Q_Value *)object);
		printf("Removed junk!\n");
	}
}