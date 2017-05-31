#ifndef REFERENCE_H
#define REFERENCE_H

#include "memalloc.h"
#include "objects.h"

struct q_reference;
typedef struct q_reference Q_Reference;

struct q_reftype{
	Q_TYPE_HEAD
};

typedef struct q_reftype Q_RefType;
extern Q_RefType Q_TypeRef;

Q_Reference *Q_NewReference(Q_Object *value);
void Q_DestroyReference(Q_Value *self);

Q_Object *Q_ReferenceGetValue(Q_Reference *self);
void Q_ReferenceSetValue(Q_Reference *self, Q_Object *value);

#endif