#include "run.h"

Q_Primitive **stack = NULL;

size_t ip = 0; //Instruction pointer
size_t sp = 0; //Stack pointer
size_t fp = 0; //Frame pointer
uint_8 opcode;

int halt = 0; //Set to 1 when program is halted

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

uint_8 fetch();
void execute();

uint_8 instructions[] = {0x02, 0x00, 0x23, 0x02, 0x00, 0x14, 0x03, 0x04, 0x05};

void Q_Run(){
	setupStack();

	while(!halt){
		fetch();
		execute();
	}

	
}

uint_8 fetch(){
	return opcode = instuctions[ip++];
}

void execute(){
	switch(opcode){
		case PUSH:
			break;

		case POP
			break;

		case ICONST:
			int i = instuctions[ip++] << 8;
			i |= instuctions[ip++];
			PUSH(Q_NewInteger(i));
			break;

		case ADD:
			PUSH(Q_NewInteger(
					Q_IntegerGetValue((Q_Integer *)POP() + 
					Q_IntegerGetValue((Q_Integer *)POP())));
			break;

		case PRINT:
			printf("%d\n", Q_IntegerGetValue((Q_Integer *)POP()));
			break;

		case HALT:
			halt = 1;
			break;
	}
}
