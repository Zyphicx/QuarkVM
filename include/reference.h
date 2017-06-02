#ifndef REFERENCE_H
#define REFERENCE_H

#include "memalloc.h"
#include "objects.h"

struct q_reference{
	Q_PRIMITIVE_HEAD
	Q_Object *value;
};
typedef struct q_reference Q_Reference;

struct q_reftype{
	Q_TYPE_HEAD
};

extern Q_Type Q_TypeRef;

Q_Reference *Q_NewReference(Q_Object *value);
void Q_DestroyReference(Q_Value *self);

#endif