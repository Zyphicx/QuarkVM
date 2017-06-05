#ifndef OBJECTS_H
#define OBJECTS_H

#include <stdlib.h>

#define Q_TYPE_HEAD \
	size_t size; \
	char *name; \
	dstruct destructor; \
	cstruct new; \

	/*ARITHMETIC FUNCTIONS*/
	Q_Value *(*add)(Q_Value *, Q_Value *); \
	Q_Value *(*sub)(Q_Value *, Q_Value *); \
	Q_Value *(*mul)(Q_Value *, Q_Value *); \
	Q_Value *(*div)(Q_Value *, Q_Value *); \
	Q_Value *(*exp)(Q_Value *, Q_Value *); \
	Q_Value *(*mod)(Q_Value *, Q_Value *); \


	Q_Type *upcastable[];


#define Q_VALUE_HEAD \
	Q_Type *type;

#define Q_PRIMITIVE_HEAD \
	Q_VALUE_HEAD

#define Q_OBJECT_HEAD \
	Q_VALUE_HEAD \
	size_t refs;

struct q_type;
typedef struct q_type Q_Type;


struct q_value;
typedef struct q_value Q_Value;


struct q_primitive;
typedef struct q_primitive Q_Primitive;


struct q_object;
typedef struct q_object Q_Object;


typedef void (*dstruct)(Q_Value *);
typedef void (*cstruct)(Q_Value *);


struct q_type{
	Q_TYPE_HEAD
};

struct q_value{
	Q_VALUE_HEAD
};


struct q_primitive{
	Q_PRIMITIVE_HEAD
};


struct q_object{
	Q_OBJECT_HEAD
};

int isUpcastable(Q_Type *type1, Q_Type *type2);
int Q_CastType(Q_Type *type1, Q_Type *type2);

#endif