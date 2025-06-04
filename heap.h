#ifndef HEAP
#define HEAP
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define REALLOC realloc
#define ASSERT assert

#define HEAP_MIN 0
#define HEAP_MAX 1

#define heap_t(type) struct {\
	type* nodes;\
	size_t size;\
	size_t capacity;\
	size_t arity;\
}


#define HEAP_GF 1.2f
#define HEAP_INITIAL_CAP 100
