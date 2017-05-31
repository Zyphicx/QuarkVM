#ifndef RUN_H
#define RUN_H

#include "objects.h"

#define STACK_SIZE 4096

extern size_t ip;
extern size_t sp;
extern size_t fp;

void setupStack();
void clearStack();

#endif