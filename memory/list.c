#include "list.h"
#include <stdio.h>

struct q_listtype{
	Q_TYPE_HEAD
};

Q_ListType Q_TypeList =
{
	sizeof(Q_List),
	"list",
	Q_DestroyList
};

Q_List *Q_NewList(size_t elemNum, Q_Type *elemType){
	Q_List *list = (Q_List *)Q_ObjectAlloc(sizeof(Q_List));
	list->type = (Q_Type *)&Q_TypeList;
	list->refs = 0;

	list->elemNum = elemNum;
	list->elemType = elemType;

	list->list = Q_RawAlloc(elemNum * elemType->size);

	return list;
}

void Q_DestroyList(Q_Value *self){
	Q_List *list = (Q_List *)self;
	printf("Still running!\n");

	/*DESTROY ALL THE ELEMENTSSSSSSSSSSS*/
	/*ONLY STORE PRIMITIVES (INCLUDING REFERENCES)*/
	/*NEVER EVER STORE OBJECTS IN VARIABLES, ONLY REFERENCES TO THOSE OBJECTS*/

	Q_RawFree(list->list);
	Q_ObjectFree((Q_Object *)self);
}