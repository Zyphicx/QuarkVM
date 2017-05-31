#include "integer.h"

#include <stdio.h>

struct q_integer{
	Q_PRIMITIVE_HEAD
	int value;
};

Q_IntType Q_TypeInt =
{
	sizeof(Q_Integer),
	"integer",
	Q_DestroyInteger
};

Q_Integer *Q_NewInteger(int value){
	Q_Integer *i = Q_RawAlloc(sizeof(Q_Integer));
	i->type = (Q_Type *)&Q_TypeInt;
	i->value = value;

	return i;
}

void Q_DestroyInteger(Q_Value *self){
	Q_RawFree(self);
}

int Q_IntegerGetValue(Q_Integer *self){
	return self->value;
}

void Q_IntegerSetValue(Q_Integer *self, int value){
	self->value = value;
}