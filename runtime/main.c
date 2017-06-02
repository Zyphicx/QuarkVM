#include "Quark.h"
#include <stdio.h>

#include "reference.h"

void q_close();

int main(int argc, char *argv[]){
	/*setupStack();

	Q_Integer *integer = Q_NewInteger(5);

	printf("%d\n", Q_IntegerGetValue(integer));

	Q_DestroyInteger((Q_Value *)integer);

	Q_List *list = Q_NewList(3, (Q_Type *)&Q_TypeInt);
	Q_List *list2 = Q_NewList(4, (Q_Type *)&Q_TypeInt);

	Q_Reference *ref = Q_NewReference((Q_Object *)list);

	Q_ListAppend(list, (Q_Value *)Q_NewInteger(4));
	Q_ListAppend(list, (Q_Value *)Q_NewInteger(2));

	printf("%d and %d\n", Q_IntegerGetValue((Q_Integer *)Q_ListGet(list, 0)), Q_IntegerGetValue((Q_Integer *)Q_ListGet(list, 1)));

	runGC();

	Q_ReferenceSetValue(ref, NULL);

	printf("Teehee!\n");

	Q_DestroyReference((Q_Value *)ref);*/

	printf("%d\n", isUpcastable(&Q_TypeFloat, &Q_TypeInt));

	Q_Run();

	q_close();

	return 1;
}

void q_close(){
	clearHeap();
	clearStack();
}