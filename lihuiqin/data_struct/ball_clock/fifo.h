#ifndef _FIFO_H__
#define _FIFO_H__

typedef int datatype;
#define MAXSIZE 32

typedef struct node_st{
    datatype data[MAXSIZE];
    int head, tail;
}queue;

queue * fifo_create();
int fifo_enqueue(queue *p, datatype *data);
int fifo_dequeue(queue *p, datatype *data);
int fifo_is_empty(queue *);
void fifo_display(queue *);
void fifo_clear(queue *);
void fifo_destroy(queue *);

#endif