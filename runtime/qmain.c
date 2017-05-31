#include "Quark.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	Q_Integer *integer = Q_NewInteger();
	integer->value = 5;

	printf("%d\n", integer->value);

	Q_DestroyInteger((Q_Value *)integer);

	Q_List *list = Q_NewList(3, (Q_Type *)&Q_TypeInt);
	Q_List *list2 = Q_NewList(4, (Q_Type *)&Q_TypeInt);

	runGC();

	return 1;
}