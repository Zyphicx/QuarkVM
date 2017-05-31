#include "list.h"
#include <stdio.h>

struct q_listtype{
	Q_TYPE_HEAD

	Q_Value *(*get)(Q_List *, size_t);
	void (*set)(Q_List *, size_t , Q_Value *);
	void (*append)(Q_List *, Q_Value *);
	void (*expand)(Q_List *);
};

Q_ListType Q_TypeList =
{
	sizeof(Q_List),
	"list",
	Q_DestroyList,
	Q_ListGet,
	Q_ListSet,
	Q_ListAppend,
	Q_ListExpand
};

Q_List *Q_NewList(size_t elemNum, Q_Type *elemType){
	Q_List *list = (Q_List *)Q_ObjectAlloc(sizeof(Q_List));
	list->type = (Q_Type *)&Q_TypeList;
	list->refs = 0;

	list->elemNum = elemNum;
	list->elemType = elemType;

	list->list = Q_RawAlloc(elemNum * elemType->size);

	list->current = 0;

	return list;
}

void Q_DestroyList(Q_Value *self){
	Q_List *list = (Q_List *)self;
	printf("Still running!\n");

	/*DESTROY ALL THE ELEMENTSSSSSSSSSSS*/
	/*ONLY STORE PRIMITIVES (INCLUDING REFERENCES)*/
	/*NEVER EVER STORE OBJECTS IN VARIABLES, ONLY REFERENCES TO THOSE OBJECTS*/

	int i;
	while(i = list->current--)
		if(list->list[i] != NULL)
			list->list[i]->destructor(list->list[i]);

	Q_RawFree(list->list);
	Q_ObjectFree((Q_Object *)self);
}

Q_Value *Q_ListGet(Q_List *self, size_t index){
	return self->list[index];
}

void Q_ListSet(Q_List *self, size_t index, Q_Value *value){
	while(index > self->current){
		Q_Integer *i = Q_NewInteger(0);
		self->append(self, i);
	}

	self->list[index] = value;
	++self->current;
}

void Q_ListAppend(Q_List *self, Q_Value *value){
	if(self->current >= self->elemNum)
		self->expand(self);

	self->list[self->current++] = value;
}

void Q_ListExpand(Q_List *self){
	self->elemNum *= 1.5;
	self->list = Q_RawRealloc(self->list, self->elemNum * self->elemType->size);
}