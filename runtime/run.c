#include "run.h"

/*STACK OPERATIONS*/

#define SETVAL(n, v) (stack[n] = v)
#define PUSH(v) (stack[sp++] = v)
#define POP() (stack[--sp])
#define PEEK() (stack[sp-1])

Q_Value **stack = NULL;

size_t ip = 0; //Instruction pointer
size_t sp = 0; //Stack pointer
size_t fp = 0; //Frame pointer
uint8_t opcode;

int halt = 0; //Set to 1 when program is halted

void setupStack(){
	stack = Q_RawAlloc(STACK_SIZE * sizeof(Q_Value *));
}

void clearStack(){
	while(sp--){
		stack[sp]->type->destructor(stack[sp]);
	}

	Q_RawFree(stack);
}

uint8_t fetch();
void execute();

uint8_t instructions[] = {0x02, 0x03, 0x11, 0x02, 0x04, 0x05, 0x06};

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
			PUSH(Q_NewInteger((instructions[ip++] << 8) | instructions[ip++]));
			break;

		case FCONST:
			PUSH(Q_NewFloat(3.1415)); //Change this later to actually read in a value
			break;

		case ADD:
		{
			Q_Value *num1 = POP();
			Q_Value *num2 = POP();

			PUSH(Q_Add(num1, num2));

			i1->type->destructor((Q_Value *)i1);
			i2->type->destructor((Q_Value *)i2);
			break;
		}

		case PRINT:
		{
			Q_Float *i = (Q_Float *)POP();

			printf("%d\n", i->value);

			i->type->destructor((Q_Value *)i);
			break;
		}

		case HALT:
			halt = 1;
			break;
	}
}
