#ifndef RUN_H
#define RUN_H

#include "memalloc.h"
#include "objects.h"
#include "opcode.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define STACK_SIZE 4096

extern size_t ip;
extern size_t sp;
extern size_t fp;

void setupStack();
void clearStack();
void Q_Run();

#endif