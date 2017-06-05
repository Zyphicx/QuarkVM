#ifndef INTEGER_H
#define INTEGER_H

#include "memalloc.h"
#include "objects.h"

struct q_integer{
	Q_PRIMITIVE_HEAD
	int value;
};
typedef struct q_integer Q_Integer;

struct q_inttype{
	Q_TYPE_HEAD
};

extern Q_Type Q_TypeInt;

Q_Integer *Q_NewInteger(int value);
void Q_DestroyInteger(Q_Value *self);

float Q_IntToFloat(Q_Primitive *self);
double Q_IntToDouble(Q_Primitive *self);

Q_Value *Q_AddInt(Q_Value *val1, Q_Value *val2);

#endif