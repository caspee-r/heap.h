// 	Copyright (C) 2025 caspeer
//
// 	Permission is hereby granted, free of charge, to any person obtaining a copy
// 	of this software and associated documentation files (the "Software"), to deal
// 	in the Software without restriction, including without limitation the rights
// 	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// 	copies of the Software, and to permit persons to whom the Software is
// 	furnished to do so, subject to the following conditions:
//
// 	The above copyright notice and this permission notice shall be included in
// 	all copies or substantial portions of the Software.
//
// 	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// 	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// 	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// 	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// 	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// 	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// 	THE SOFTWARE.

#ifndef HEAP
#define HEAP
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define REALLOC realloc
#define ASSERT assert

#define HEAP_MIN <
#define HEAP_MAX >

#define heap_t(type)						\
struct {									\
	type* nodes;							\
	size_t size;							\
	size_t capacity;						\
	unsigned char arity;					\
}

#define HEAP_GF 1.2f
#define HEAP_INITIAL_CAP 100

#define heap_get_root(heap) (heap)->nodes[0]
#define heap_get_child_index(parent, childnum, arity) (arity)*(parent)+(childnum)
#define heap_get_child(heaparr,parent,childnum, arity) (heaparr)[heap_get_child_index((parent),(childnum),(arity))]
#define heap_get_parent_index(child_idx,arity) ((child_idx)-1)/(arity)
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

#define heapify_up(heap,heap_type,index)								\
	do {																\
		if (index <= 0 && index > (heap)->size-1) break;				\
		for (unsigned i = index; i != 0 && (heap)->nodes[i] heap_type heap_get_parent((heap)->nodes,i,(heap)->arity);) \
			{															\
				(heap)->nodes[i] ^= (heap)->nodes[heap_get_parent_index(i,(heap)->arity)]; \
				(heap)->nodes[heap_get_parent_index(i,(heap)->arity)] ^= (heap)->nodes[i]; \
				(heap)->nodes[i] ^= (heap)->nodes[heap_get_parent_index(i,(heap)->arity)]; \
				i = heap_get_parent_index(i,(heap)->arity);				\
			}															\
	} while (0)															\

#define heapify_down(heap, heap_type, index)							\
	do {																\
		if (index < 0 && index > (heap)->size) break;					\
		unsigned idx = index;											\
		for (unsigned best = 1;;){										\
			if (heap_get_child_index(idx, best, (heap)->arity) >= (heap)->size-1) break; \
			for (unsigned child_idx = 2; child_idx <= (heap)->arity; ++child_idx ){ \
				if ( heap_get_child((heap)->nodes,idx,(heap)->arity,child_idx) heap_type (heap)->nodes[best]){ \
					best = child_idx;									\
				}														\
			}															\
			(heap)->nodes[idx] ^= (heap)->nodes[heap_get_child_index(idx, best, (heap)->arity)]; \
			(heap)->nodes[heap_get_child_index(idx, best, (heap)->arity)] ^= (heap)->nodes[idx]; \
			(heap)->nodes[idx] ^= (heap)->nodes[heap_get_child_index(idx, best, (heap)->arity)]; \
			idx = heap_get_child_index(idx, best, (heap)->arity);		\
		}																\
	} while(0)															\



#define heap_push(heap, heap_type, item)									\
	do {																\
		if ((heap)->size >= (heap)->capacity){							\
			(heap)->capacity = ((heap)->capacity == 0) ? HEAP_INITIAL_CAP : (heap)->capacity*HEAP_GF; \
			(heap)->nodes = REALLOC((heap)->nodes,(heap)->capacity * sizeof(*(heap)->nodes)); \
			ASSERT((heap)->nodes && "NOT ENOUGH MEMORY\n");				\
		}																\
		(heap)->size++;													\
		last(heap) = (item);											\
		heapify_up((heap),heap_type,((heap)->size - 1));				\
	} while (0)															\


#define heap_pop(heap, heap_type, poped_value)							\
	do {																\
		if (heap_is_empty((heap))){										\
			break;														\
		}																\
		(poped_value) = heap_get_root((heap));							\
		if ((heap)->size == 1){											\
			(heap)->nodes[0] = 0;										\
			break;														\
		}																\
		(heap)->nodes[0] = last((heap));								\
		(heap)->size--;													\
		heapify_down(heap, heap_type, 0);								\
	} while (0)															\

#endif

#ifdef HEAP_IMPLEMENTATION




#endif
