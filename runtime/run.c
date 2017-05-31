#include "run.h"

Q_Primitive **stack = NULL;

size_t ip = 0; //Instruction pointer
size_t sp; //Stack pointer
size_t fp; //Frame pointer

void setupStack(){
	stack = Q_RawAlloc(STACK_SIZE * sizeof(Q_Value *));

 	sp = 0;
 	fp = 0;
}

void clearStack(){
	--sp; //sp is set to the next free stack element, this sets it to the next used element

	while(sp--){
		stack[sp]->type->destructor((Q_Value *)stack[p]):
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