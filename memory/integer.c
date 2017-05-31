#include "integer.h"

struct q_inttype{
	Q_TYPE_HEAD
};

Q_IntType Q_TypeInt =
{
	sizeof(Q_Integer),
	"integer",
	Q_DestroyInteger
};

Q_Integer *Q_NewInteger(){
	Q_Integer *i = Q_RawAlloc(sizeof(Q_Integer));
	i->type = (Q_Type *)&Q_TypeInt;

	return i;
}

void Q_DestroyInteger(Q_Value *self){
	Q_RawFree(self);
}