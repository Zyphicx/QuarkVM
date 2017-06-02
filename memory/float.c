#include "float.h"
#include "integer.h"

#include <stdio.h>

Q_Type Q_TypeFloat =
{
	sizeof(Q_Float),
	"float",
	Q_DestroyFloat,
	{
		//&Q_TypeDouble,
		NULL
	}
};

Q_Float *Q_NewFloat(float value){
	Q_Float *i = Q_RawAlloc(sizeof(Q_Float));
	i->type = &Q_TypeFloat;
	i->value = value;

	return i;
}

void Q_DestroyFloat(Q_Value *self){
	Q_RawFree(self);
}