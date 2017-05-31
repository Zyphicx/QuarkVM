#ifndef MEMALLOC_H
#define MEMALLOC_H

#include <stdlib.h>
#include "objects.h"

#define POSIX (defined(__unix__) || (defined(__apple__) || defined(__mach__)))
#define WINDOWS (defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__CYGWIN__))

#define BIG_ALLOC_SIZE (~((1 << 20) - 1)) //128k bytes

struct q_memchunk;
typedef struct q_memchunk MemChunk;


void *Q_RawAlloc(size_t size);
void Q_RawFree(void *p);
void *Q_RawRealloc(void *p, size_t new_size);
void *Q_RawCalloc(size_t num, size_t size);


void *Q_BigAlloc(size_t size);
void Q_BigFree(void *p, size_t size);

void *Q_Alloc(size_t size);
void Q_Free(void *p, size_t size);

Q_Object *Q_ObjectAlloc(size_t size);
void Q_ObjectFree(Q_Object *object);
void runGC();

#endif