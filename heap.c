#include <stdio.h>
#define HEAP_IMPLEMENTATION
#include "heap.h"


// declaring the type of the heap
typedef  heap_t(int) heap_int;

void print_heap(heap_int h)
{
	int i;
	int c = h.arity;
	printf("%d\n",h.nodes[0]);
	for (i = 1; i < h.size; ++i){
		printf("%d\t",h.nodes[i]);
		if (i == c){
			printf("\n");
			c *= 2+i;
		}
	}
	printf("\n");
}

int main()
{
	// initializing
	heap_int heap = {0};
	heap.arity = 2;
	// push a new element to the heap
	// HEAP_MAX and HEAP_MIN are just comparison symbols
	heap_push(&heap,HEAP_MAX,10);
	heap_push(&heap,HEAP_MAX,20);
	heap_push(&heap,HEAP_MAX,28);
	heap_push(&heap,HEAP_MAX,3);
	heap_push(&heap,HEAP_MAX,9);
	heap_push(&heap,HEAP_MAX,69);
	heap_push(&heap,HEAP_MAX,100);
	int root = 0;
	print_heap(heap);
	printf("______________________________________\n");
	// pop the MAX_VALUE and store it in root;
	heap_pop(&heap,HEAP_MAX,root);
	print_heap(heap);
	printf("______________________________________\n");

	heap_pop(&heap,HEAP_MAX,root);
	print_heap(heap);
	printf("______________________________________\n");
	heap_pop(&heap,HEAP_MAX,root);
	print_heap(heap);
	printf("______________________________________\n");

	heap_pop(&heap,HEAP_MAX,root);
	print_heap(heap);
	printf("______________________________________\n");

	heap_pop(&heap,HEAP_MAX,root);
	print_heap(heap);
	printf("______________________________________\n");

	heap_pop(&heap,HEAP_MAX,root);
	print_heap(heap);
	printf("______________________________________\n");

	heap_pop(&heap,HEAP_MAX,root);
	print_heap(heap);
	printf("______________________________________\n");

}
