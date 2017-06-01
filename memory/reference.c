#include "reference.h"

#include <stdio.h>

struct q_reference{
	Q_PRIMITIVE_HEAD
	Q_Object *value;
};

Q_RefType Q_TypeRef =
{
	sizeof(Q_Reference),
	"reference",
	Q_DestroyReference
};

Q_Reference *Q_NewReference(Q_Object *value){
	Q_Reference *r = Q_RawAlloc(sizeof(Q_Reference));
	r->type = (Q_Type *)&Q_TypeRef;
	r->value = value;

	if(value != NULL)
		++(value->refs);

	return r;
}

void Q_DestroyReference(Q_Value *self){
	Q_RawFree(self);
}

Q_Object *Q_ReferenceGetValue(Q_Reference *self){
	return self->value;
}

void Q_ReferenceSetValue(Q_Reference *self, Q_Object *value){
	if(self->value != NULL)
		if(--(self->value->refs) <= 0)
			self->value->type->destructor((Q_Value *)self->value);

	self->value = value;

	if(value != NULL)
		++(value->refs);
}