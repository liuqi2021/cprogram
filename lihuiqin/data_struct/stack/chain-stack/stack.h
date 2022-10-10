#ifndef STACK_H__
#define STACK_H__
#include "linklist.h"

typedef  LINKLIST STACK;

int stack_create(STACK **p, int size);
int stack_push(STACK *p, const void *data);
int stack_pop(STACK *p,void *data);
int stack_top(STACK *, int *);
int stack_is_empty(STACK *);
void stack_display(STACK *);
void stack_destory(STACK *);

#endif