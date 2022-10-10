#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "linear_stack.h"

stack * stack_init(){
    stack *ptr;
    ptr = malloc(sizeof(*ptr));
    if(ptr == NULL){
        return NULL;
    }
    ptr->top = -1;
    return ptr;

}

int stack_push(stack *ptr, type *data){
    if(ptr->top >= (SIZE -1)){
        return -1;
    }
    ptr->data[++ptr->top] = *data;
    return 0;
}

int stack_pop(stack *ptr, type *data){
    if(ptr->top >= (SIZE -1)){
        return -1;
    }
    *data = ptr->data[ptr->top--];
    return 0;
}

int stack_top(stack *ptr, type *data){
    if(ptr->top >= (SIZE -1)){
    return -1;
    }
    *data = ptr->data[ptr->top];
    return 0;
}

void stack_display(stack *ptr){
    int i = 0;
    for(i = 0; i <= ptr->top; i++){
        printf("  %d",ptr->data[i]);
    }
    printf("\n");
}

int stack_is_empty(stack *ptr){
    return (ptr->top == -1);
}

void stack_destory(stack * ptr){
    free(ptr);
}


