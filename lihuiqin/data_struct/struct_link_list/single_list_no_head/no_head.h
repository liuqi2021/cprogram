#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _NO_HEAD_H_
#define _NO_HEAD_H_
typedef int datatype;

struct student{
    datatype id;
    char name[1024];
    int math;
    int chinese;   
};

typedef struct node_st{
    struct student data;
    struct node_st *next;
}linklist;

int list_insert(linklist **p, struct student *data);
int list_delete(linklist **p);
int list_find(linklist *p, int data);
void list_show(linklist *p);


#endif