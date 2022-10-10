#ifndef LINEAR_STACK_H__
#define LINEAR_STACK_H__

#define SIZE 32
typedef int type;
typedef struct stack_st{
    type data[SIZE];
    type top;
}stack;

stack * stack_init();
int stack_push(stack *, type *);
int stack_pop(stack *, type *);
int stack_top(stack *ptr, type *data);
void stack_display(stack *);
int stack_is_empty(stack *);
void stack_destory(stack*);

#endif