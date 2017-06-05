#ifndef FLOAT_H
#define FLOAT_H

#include "memalloc.h"
#include "objects.h"

struct q_float{
	Q_PRIMITIVE_HEAD
	float value;
};
typedef struct q_float Q_Float;

struct q_floattype{
	Q_TYPE_HEAD
};

extern Q_Type Q_TypeFloat;

Q_Float *Q_NewFloat(float value);
void Q_DestroyFloat(Q_Value *self);
float Q_ToFloat(Q_Value *num);
double Q_FloatToDouble(Q_Value *num);

Q_Value *Q_AddFloat(Q_Value *val1, Q_Value *val2);

#endif