#ifndef LIST_H
#define LIST_H

#include "memalloc.h"
#include "objects.h"

struct q_list{
	Q_OBJECT_HEAD

	Q_Type *elemType;
	size_t elemNum; //Amount of elements in total
	Q_Value **list;
	size_t current; //The amount of currently used elements
};
typedef struct q_list Q_List;

struct q_listtype;
typedef struct q_listtype Q_ListType;
extern Q_ListType Q_TypeList;

Q_List *Q_NewList(size_t elemNum, Q_Type *elemType);
void Q_DestroyList(Q_Value *self);

Q_Value *Q_ListGet(Q_List *self, size_t index);
void Q_ListSet(Q_List *self, size_t index, Q_Value *value);
void Q_ListAppend(Q_List *self, Q_Value *value);v
void Q_ListExpand(Q_List *self);

#endif