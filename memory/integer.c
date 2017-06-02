#include "float.h"
#include "integer.h"

#include <stdio.h>

Q_Type Q_TypeInt =
{
	sizeof(Q_Integer),
	"integer",
	Q_DestroyInteger,
	{
		&Q_TypeFloat,
		//(Q_Type *)&Q_TypeDouble,
		NULL
	}
};

Q_Integer *Q_NewInteger(int value){
	Q_Integer *i = Q_RawAlloc(sizeof(Q_Integer));
	i->type = &Q_TypeInt;
	i->value = value;

	return i;
}

void Q_DestroyInteger(Q_Value *self){
	Q_RawFree(self);
}