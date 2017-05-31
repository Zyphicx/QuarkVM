#include "memalloc.h"
#include "objects.h"

struct q_integer{
	Q_PRIMITIVE_HEAD
	int value;
};
typedef struct q_integer Q_Integer;

struct q_inttype;
typedef struct q_inttype Q_IntType;
extern Q_IntType Q_TypeInt;

Q_Integer *Q_NewInteger();
void Q_DestroyInteger(Q_Value *self);