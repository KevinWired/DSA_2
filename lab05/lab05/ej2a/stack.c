#include <stdlib.h>
#include <assert.h>
#include "stack.h"

typedef struct _s_stack
{
  stack_elem data;
  struct _s_stack *next;
} p;


stack stack_empty() {
    stack s = NULL;
    return s;
}

stack stack_push(stack s, stack_elem e) {
	stack top;
	top = (stack) malloc(sizeof(struct _s_stack));
	assert(top != NULL);
	top->data = e;
	top->next = s;
	return top;
}

stack stack_pop(stack s) { 
	assert(!stack_is_empty(s));
	stack delete;
	delete = s;
	s = s->next;
	free(delete);
	return s;
}

unsigned int stack_size(stack s) {
	unsigned int size = 0;
	stack counter = s;
	while(counter != NULL)
	{
		size = size + 1;
		counter = counter->next;
	}
	return size;
}

stack_elem stack_top(stack s) {	
	assert(!stack_is_empty(s));
	return s->data;
}

bool stack_is_empty(stack s) {
	bool is_empty = (s == NULL);
	return is_empty;
}

stack_elem *stack_to_array(stack s) {
	stack_elem *array = NULL;
	if(stack_is_empty(s))
	{
		return NULL;
	}
	unsigned int len = stack_size(s);
	array = calloc(len, sizeof(stack_elem));
	
	stack array_item = s;
	for(stack_elem i = len - 1; i >= 0; i--)
	{
		array[i] = array_item->data;
		array_item = array_item->next;
	}
	return array;
}

stack stack_destroy(stack s) {
	if(s == NULL)
	{
		return NULL;
	}
	stack delete = s;
	s = s->next;
	free(delete);
	stack_destroy(s);
	return s;
}
