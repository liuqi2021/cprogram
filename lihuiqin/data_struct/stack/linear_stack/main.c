#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "linear_stack.h"

int main(){
    int i;
    int data;
    stack *point = stack_init();
    if(point == NULL){
        exit(1);
    }
    for(i = 0; i < (MAXSIZE); i++){
        data = random() % 100;
        printf("%d  ",data);
        stack_push(point, &data);
    }
    stack_top(point, &data);
    printf("%d\n",data);
    stack_display(point);
    stack_destory(point);
    exit(0);

}