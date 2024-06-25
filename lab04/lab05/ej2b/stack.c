#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
  stack_elem data;
  struct _s_stack *next;
  unsigned int len;
};

stack stack_empty() {
    stack s = NULL;
    return s;
}

stack stack_push(stack s, stack_elem e) {	
    stack top = malloc(sizeof(struct _s_stack));
    assert(top != NULL);
    top->data = e;
    top->next = s;
    top->len = s != NULL ? s->len + 1 : 1;
    return top;
}

stack stack_pop(stack s) { 
    assert(!stack_is_empty(s));
    stack delete = s;
    s = s->next;
    free(delete);
    if (s != NULL) {
        s->len--;
    }
    return s;
}

unsigned int stack_size(stack s)
{
    return (s == NULL) ? 0 : s->len;
}

stack_elem stack_top(stack s) {	
    assert(!stack_is_empty(s));
    return s->data;
}

bool stack_is_empty(stack s)
{
    return (s == NULL);
}

stack_elem *stack_to_array(stack s) {
    stack_elem *array = NULL;
    if (stack_is_empty(s))
    {
        return NULL;
    }
    unsigned int array_len = stack_size(s);
    array = calloc(array_len, sizeof(stack_elem));
    
    stack array_item = s;
    for (unsigned int i = array_len; i > 0; i--)
    {
        array[i - 1] = array_item->data;
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
