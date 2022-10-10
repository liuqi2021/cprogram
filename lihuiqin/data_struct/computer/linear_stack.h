#ifndef LINEAR_STACK_H__
#define LINEAR_STACK_H__

#define MAXSIZE 32
typedef int datatype;
typedef struct stack_st{
    datatype data[MAXSIZE];
    datatype top;
}stack;

stack * stack_init();
int stack_push(stack *, datatype *);
int stack_pop(stack *, datatype *);
int stack_top(stack *ptr, datatype *data);
void stack_display(stack *);
int stack_is_empty(stack *);
void stack_destory(stack*);

#endif