#include "list.h"
#include <stdio.h>

struct q_list{
	Q_OBJECT_HEAD

	Q_Type *elemType;
	size_t elemNum; //Amount of elements in total
	Q_Value **list;
	size_t current; //The amount of currently used elements
};

Q_Type Q_TypeList =
{
	sizeof(Q_List),
	"list",
	Q_DestroyList,

	/*ARITHMETIC FUNCTIONS*/
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	/*Subtypes*/
	{NULL}
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

	/*DESTROY ALL THE ELEMENTSSSSSSSSSSS*/
	/*ONLY STORE PRIMITIVES (INCLUDING REFERENCES)*/
	/*NEVER EVER STORE OBJECTS IN VARIABLES, ONLY REFERENCES TO THOSE OBJECTS*/

	int i;
	while(list->current--){
		i = list->current;
		if(list->list[i] != NULL)
			list->list[i]->type->destructor(list->list[i]);
	}

	Q_RawFree(list->list);
	Q_ObjectFree((Q_Object *)self);
}

Q_Value *Q_ListGet(Q_List *self, size_t index){ //Change this to a macro?
	return self->list[index];
}

void Q_ListSet(Q_List *self, size_t index, Q_Value *value){
	while(index >= self->elemNum)
		Q_ListExpand(self);

	self->list[index] = value;

	if(index >= self->current)
		++(self->current);
}

void Q_ListAppend(Q_List *self, Q_Value *value){
	if(self->current >= self->elemNum)
		Q_ListExpand(self);

	self->list[self->current++] = value;

	printf("After append: %d\n", self->current);
}

void Q_ListExpand(Q_List *self){
	self->elemNum *= 1.5;
	self->list = Q_RawRealloc(self->list, self->elemNum * self->elemType->size);
}