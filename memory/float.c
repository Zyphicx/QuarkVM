#include "float.h"
#include "integer.h"

#include <stdio.h>

Q_Type Q_TypeFloat =
{
	sizeof(Q_Float),
	"float",
	Q_DestroyFloat,

	/*ARITHMETIC FUNCTIONS*/
	Q_AddFloat,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	/*Subtypes*/
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

float Q_ToFloat(Q_Value *val){
	if(val->type == &Q_TypeInt){
		return Q_IntToFloat((Q_Integer *)val);
	}else{
		fprintf(stderr, "Can't cast type \"%s\" to float.", nuvalm->type->name);
	}
}

/*double Q_ToDouble(Q_Primitive *num){
	if(num->type == &Q_TypeInt){
		return Q_IntToDouble((Q_Integer *)num);
	}
	else if(num->type == &Q_TypeFloat){
		return Q_FloatToDouble((Q_Integer *)num);
	}else{
		fprintf(stderr, "Can't cast type \"%s\" to double.", num->type->name);
	}
}*/

Q_Value *Q_AddFloat(Q_Value *val1, Q_Value *val2){
	float f1, f2;

	f1 = (val1->type == &Q_TypeFloat ? ((Q_Float *)val1)->value : Q_ToFloat(val1));
	f2 = (val2->type == &Q_TypeFloat ? ((Q_Float *)val2)->value : Q_ToFloat(val2));

	return (Q_Value *)Q_NewFloat(f1 + f2);
}