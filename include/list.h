#include "memalloc.h"
#include "objects.h"

struct q_list{
	Q_OBJECT_HEAD

	Q_Type *elemType;
	size_t elemNum;
	Q_Value **list;
};
typedef struct q_list Q_List;

struct q_listtype;
typedef struct q_listtype Q_ListType;
extern Q_ListType Q_TypeList;

Q_List *Q_NewList(size_t elemNum, Q_Type *elemType);
void Q_DestroyList(Q_Value *self);