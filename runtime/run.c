#include "run.h"

/*STACK OPERATIONS*/

#define SETVAL(n, v) (stack[n] = v)
#define PUSH(v) (stack[sp++] = v)
#define POP() (stack[--sp])
#define PEEK() (stack[sp-1])

Q_Primitive **stack = NULL;

size_t ip = 0; //Instruction pointer
size_t sp = 0; //Stack pointer
size_t fp = 0; //Frame pointer
uint8_t opcode;

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

uint8_t fetch();
void execute();

uint8_t instructions[] = {0x02, 0x03, 0x11, 0x02, 0x00, 0x0e, 0x03, 0x04, 0x05};

void Q_Run(){
	setupStack();

	while(!halt){
		fetch();
		execute();
	}

	
}

uint8_t fetch(){
	return opcode = instructions[ip++];
}

void execute(){
	switch(opcode){
		case PUSHVAL:
			break;

		case POPVAL:
			break;

		case ICONST:
			PUSH((Q_Primitive *)Q_NewInteger((instructions[ip++] << 8) | instructions[ip++]));
			break;

		case ADD:
		{
			Q_Integer *i1 = (Q_Integer *)POP();
			Q_Integer *i2 = (Q_Integer *)POP();

			PUSH((Q_Primitive *)Q_NewInteger(i1->value + i2->value));

			i1->type->destructor((Q_Value *)i1);
			i2->type->destructor((Q_Value *)i2);
			break;
		}

		case PRINT:
		{
			Q_Integer *i = (Q_Integer *)POP();

			printf("%d\n", i->value);

			i->type->destructor((Q_Value *)i);
			break;
		}

		case HALT:
			halt = 1;
			break;
	}
}
