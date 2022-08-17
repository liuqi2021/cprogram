#ifndef __SINGLE_STRUCT_H_
#define _SINGLE_STRUCT_H_

typedef int datatype;

typedef struct single_list{
    datatype score;
    struct single_list *next;
}linklist;


linklist * list_create(linklist *p);
void linklist_create1(linklist **p);

int list_insert(linklist *p, int pos, datatype *);
int list_insert_tail(linklist *p, datatype *);
int list_insert_head(linklist *p, datatype *);
int list_order_insert(linklist *p, int *data);
int linklist_delete_pos(linklist *p, int pos);
int linklist_delete_data(linklist *p, datatype *data);
int linklist_is_empty(linklist *);
void linklist_show(linklist *);
void linklist_destroy(linklist *);



#endif