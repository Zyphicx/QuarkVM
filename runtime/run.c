#include "run.h"

Q_Primitive **stack = NULL;

size_t ip = 0; //Instruction pointer
size_t sp = 0; //Stack pointer
size_t fp = 0; //Frame pointer

void setupStack(){
	stack = Q_RawAlloc(STACK_SIZE * sizeof(Q_Primitive *));
}

void clearStack(){
	while(sp--){
		stack[sp]->type->destructor((Q_Value *)stack[sp]);
	}

	Q_RawFree(stack);
}

void push(Q_Primitive *value){
	stack[sp++] = value;
}

Q_Primitive *pop(){
	return (sp > 0) ? stack[--sp] : NULL;
}

Q_Primitive *peek(){
	return stack[sp-1];
}