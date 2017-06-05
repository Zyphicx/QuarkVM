#include "reference.h"

#include <stdio.h>

Q_Type Q_TypeRef =
{
	sizeof(Q_Reference),
	"reference",
	Q_DestroyReference,

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

Q_Reference *Q_NewReference(Q_Object *value){
	Q_Reference *r = Q_RawAlloc(sizeof(Q_Reference));
	r->type = &Q_TypeRef;
	r->value = value;

	if(value != NULL)
		++(value->refs);

	return r;
}

void Q_DestroyReference(Q_Value *self){
	--((Q_Reference *)self)->value->refs;
	Q_RawFree(self);
}

void Q_ReferenceSetValue(Q_Reference *self, Q_Object *value){
	if(self->value != NULL)
		if(--(self->value->refs) <= 0)
			self->value->type->destructor((Q_Value *)self->value);

	self->value = value;

	if(value != NULL)
		++(value->refs);
}