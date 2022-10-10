#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fifo.h"

int fifo_create(FIFO **p, int size){
    return list_create(p, size);
}
int fifo_push(FIFO *p, const void *data){
    return list_insert(p, data, INSERT_BACKUP);
}

static int always_match(const void *p, const void *q){
    return 0;
}

int fifo_pop(FIFO *p,void *data){
    const void *p1, *p2;
    return list_fetech(p,(void *)0 ,always_match(p1, p2),data);
}

void fifo_destory(FIFO *p){
    list_destroy(p);
}