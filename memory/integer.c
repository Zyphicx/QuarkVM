#include "float.h"
#include "integer.h"

#include <stdio.h>

Q_Type Q_TypeInt =
{
	sizeof(Q_Integer),
	"integer",
	Q_DestroyInteger,

	/*ARITHMETIC FUNCTIONS*/
	Q_AddInt,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	/*Subtypes*/
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

float Q_IntToFloat(Q_Integer *self){
	return (float)((Q_Integer *)self->value);
}

double Q_IntToDouble(Q_Integer *self){
	return (double)((Q_Integer *)self->value);
}

int Q_ToInt(Q_Value *val){
	/*if(val->type == &Q_TypeInt){
		return Q_IntToFloat((Q_Integer *)val);
	}else{
		fprintf(stderr, "Can't cast type \"%s\" to float.", nuvalm->type->name); Add things to deal with subtypes of int
	}
	*/

	return 0;
}

Q_Value *Q_AddInt(Q_Value *val1, Q_Value *val2){
	int f1, f2;

	f1 = (val1->type == &Q_TypeInt ? ((Q_Integer *)val1)->value : Q_ToInt(val1));
	f2 = (val2->type == &Q_TypeInt ? ((Q_Integer *)val2)->value : Q_ToInt(val2));

	return (Q_Value *)Q_NewInteger(f1 + f2);
}