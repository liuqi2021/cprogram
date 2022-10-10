#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<unistd.h>

#include "fifo.h"

queue * fifo_create(){
    queue *tmp;
    tmp = malloc(sizeof(*tmp));
    if(tmp == NULL){
        return NULL;
    }
    tmp->head = 0;
    tmp->tail = 0;
    return tmp;
}

int fifo_is_empty(queue *p){
    if(p->head == p->tail){
        return 0;
    }
    return -1;
}

int fifo_enqueue(queue *p, datatype *data){
    if((p->tail+1) % MAXSIZE == p->head){
        return -1;
    }
    p->tail = (p->tail+1) % MAXSIZE;
    p->data[p->tail] = *data;
    return 0;
}
int fifo_dequeue(queue *p, datatype *data){
    if(fifo_is_empty(p) == 0){
        return -1;
    }
    p->head = (p->head) % MAXSIZE;
    *data = p->head;
    // p->head = p->head+1;
    return 0;
}

void fifo_display(queue *p){
    int i;
    if(fifo_is_empty(p) == 0){
        return;
    }
    i = (p->head + 1) % MAXSIZE;
    while(i != p->tail){
        printf("%d  ",p->data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("%d\n", p->data[i]);
    return;

}
void fifo_clear(queue *q){
    q->head = q->tail;
}
void fifo_destroy(queue *tmp){
    free(tmp);
}
