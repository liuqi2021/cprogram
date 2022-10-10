#ifndef FIFO_H__
#define FIFO_H__

#include "linklist.h"

typedef LINKLIST FIFO;

int fifo_create(FIFO **p, int size);
int fifo_push(FIFO *p, const void *data);

static int always_match(const void *p, const void *q);

int fifo_pop(FIFO *p,void *data);
// int fifo_top(FIFO *, int *);
// int fifo_is_empty(FIFO *);
// void fifo_display(FIFO *p, llist_user_show *show){
//     list_show(p, show);
// }
void fifo_destory(FIFO *p);

#endif