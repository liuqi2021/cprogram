#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int stack_create(STACK **p, int size){
    return list_create(p, size);
}
int stack_push(STACK *p, const void *data){
    list_insert(p, data, INSERT_FORWARD);
}

static int always_match(const void *p, const void *q){
    return 0;
}

int stack_pop(STACK *p,void *data){
    const void *p1, *p2;
    return list_fetech(p,(void *)0 ,always_match(p1, p2),data);
}
// int stack_top(STACK *, int *);
// int stack_is_empty(STACK *);
// void stack_display(STACK *p, llist_user_show *show){
//     list_show(p, show);
// }
void stack_destory(STACK *p){
    list_destroy(p);
}