#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "stack.h"

struct _s_stack {
  stack_elem *elems; // Arreglo de elementos
  unsigned int size; // Cantidad de elementos en la pila
  unsigned int capacity; // Capacidad actual del arreglo elems
};

static bool invrep(stack s) {
	bool flag_0 = s != NULL;
	bool flag_1 = s->size <= s->capacity;
	bool flag_2 = (s->size == 0 || s->size > 0);
    return flag_0 && flag_1 && flag_2;
}

stack stack_empty()	{
	stack s = malloc(sizeof(struct _s_stack));
	s->size = 0;
	s->capacity = 0;
	s->elems = NULL;
	assert(invrep(s));
	return s;
}

stack stack_push(stack s, stack_elem e) {
	assert(invrep(s));
	if(s->capacity == s->size) {
		size_t new_cpty = s->size == 0 ? 1 : 2*s->size;
		s->elems = realloc(s->elems, new_cpty*sizeof(stack_elem));
		s->capacity = new_cpty;
	}
	(s->elems)[s->size] = e;
	++(s->size);
	assert(invrep(s));
	return s;
}

stack stack_pop(stack s) {
	assert(invrep(s) && !stack_is_empty(s));
	--(s->size);
	assert(invrep(s));
	return s;
}

unsigned int stack_size(stack s) {
	assert(invrep(s));
	return s->size;
}

stack_elem stack_top(stack s) {
	assert(s != NULL);
	assert(s->size > 0);
	assert(s->elems != NULL);
	return s->elems[(s->size)-1];
}

bool stack_is_empty(stack s) {
	assert(invrep(s));
	return s->size == 0;
}

stack_elem *stack_to_array(stack s) {
	assert(invrep(s));
	stack_elem *array = NULL;
	if(s->size) {
		array = calloc(s->size, sizeof(stack_elem));
	for (size_t i = 0; i < s->size; ++i) {
		array[i] = s->elems[i];
	}
  }
	assert(invrep(s));
	return array;
}

stack stack_destroy(stack s) {
	assert(invrep(s));
	free(s->elems);
	free(s);
	return NULL;
}
