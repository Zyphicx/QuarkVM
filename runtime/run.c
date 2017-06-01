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

/*STACK OPERATIONS*/

#define SETVAL(n, v) (stack[n] = v)
#define PUSH(v) (stack[sp++] = v)
#define POP() (stack[--sp])
#define PEEK() (stack[sp-1])