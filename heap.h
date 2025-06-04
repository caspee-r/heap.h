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

#define heap_get_root(heap) (heap)->nodes[0]
#define heap_get_child_index(parent, childnum, arity) (arity)*(parent)+(childnum)
#define heap_get_child(heaparr,parent,childnum, arity) (heaparr)[heap_get_child_index((parent),(childnum),(arity))]
#define heap_get_parent_index(i,arity) (size_t)floor(((i)-1)/(arity))
#define heap_get_parent(heaparr,i,arity) (heaparr)[heap_get_parent_index((i),arity)]
#define last(heap) (heap)->nodes[(heap)->size-1]
#define heap_size(heap) (heap)->size
#define heap_is_empty(heap) (heap)->size <= 0

#define heap_get_children(heaparr,parent, arr, arrlen, arity)\
	do {\
		ASSERT(arity <= arrlen);\
		for (size_t i = 1; i <= arity; ++i){\
			(arr)[i-1] = heap_get_child((heaparr),(parent),(i),(arity));\
		}\
	} while (0)\


#define heap_push(heap, item)\
	do {\
		if ((heap)->size >= (heap)->capacity){\
			(heap)->capacity = ((heap)->capacity == 0) ? HEAP_INITIAL_CAP : (heap)->capacity*HEAP_GF;\
			(heap)->nodes = REALLOC((heap)->nodes,(heap)->capacity * sizeof(*(heap)->nodes));\
			ASSERT((heap)->nodes && "NOT ENOUGH MEMORY\n");\
		}\
		(heap)->size++;\
		last(heap) = (item);\
		for (int i = (heap)->size-1 ; i != 0 && (heap)->nodes[i] > heap_get_parent((heap)->nodes,i,(heap)->arity);) {\
			(heap)->nodes[i] = (heap)->nodes[i] ^ (heap)->nodes[heap_get_parent_index(i,(heap)->arity)];\
			(heap)->nodes[heap_get_parent_index(i,(heap)->arity)] =\
			(heap)->nodes[heap_get_parent_index(i,(heap)->arity)] ^ (heap)->nodes[i];\
			(heap)->nodes[i] = (heap)->nodes[i] ^ (heap)->nodes[heap_get_parent_index(i,(heap)->arity)];\
			i = heap_get_parent_index(i,(heap)->arity);\
		}\
	} while (0)\




#endif
