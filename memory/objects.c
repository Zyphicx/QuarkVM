#include "objects.h"

int isUpcastable(Q_Type *type1, Q_Type *type2){
	Q_Type *t;

	for(t = type1->upcastable[0]; t != type2 && t != NULL; t++) //Walk array until NULL or type is found
		;

	return t != NULL; //If end of array is reached without an element being found, return 0
}