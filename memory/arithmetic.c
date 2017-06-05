#include "arithmetic.h"
#include <stdio.h>

Q_Value *Q_Add(Q_Value *num1, Q_Value *num2){
	if(isUpcastable(num2->type, num1->type) || num1->type == num2->type){
		return num1->type->add(num1, num2);
	}else if(isUpcastable(num1->type, num2->type)){
		return num2->type->add(num2, num1);
	}else{
		fprintf(stderr, "Cannot add value of type \"%s\" to value of type \"%s\".", num1->type->name, num2->type->name);
		return NULL;
	}
}