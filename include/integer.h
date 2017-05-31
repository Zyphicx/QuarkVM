#ifndef INTEGER_H
#define INTEGER_H

#include "memalloc.h"
#include "objects.h"

struct q_integer;
typedef struct q_integer Q_Integer;

struct q_inttype{
	Q_TYPE_HEAD
};

typedef struct q_inttype Q_IntType;
extern Q_IntType Q_TypeInt;

Q_Integer *Q_NewInteger(int value);
void Q_DestroyInteger(Q_Value *self);

int Q_IntegerGetValue(Q_Integer *self);
void Q_IntegerSetValue(Q_Integer *self, int value);

#endif