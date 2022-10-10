#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#define NAMESIZE 32

typedef struct struct_student{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
}stu_st;

void print_student(const void *ptr){
    const stu_st *p = ptr;
    printf("%d %d %d %s\n",p->id, p->math, p->chinese, p->name);
}

int main(){
    STACK *head = NULL;
    int i, ret;
    stu_st tmp;

    stack_create(&head, sizeof(stu_st));
    
    for(i = 0;i < 5; i++){
        tmp.chinese = rand() % 100;
        tmp.id = i;
        tmp.math = rand() % 100;
        snprintf(tmp.name, NAMESIZE, "stu%d",i);
        stack_push(head, &tmp);
    }
    while(1){
        if(stack_pop(head, &tmp) == NULL)
            break;
        print_student(&tmp);
        
    }
    stack_destory(head);
}