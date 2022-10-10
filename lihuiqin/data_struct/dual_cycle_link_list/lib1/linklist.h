#ifndef LINKLIST_H__
#define LINKLIST_H__

#define INSERT_FORWARD 0
#define INSERT_BACKUP 1

typedef struct link_node{
    void *data;
    struct link_node *pre;
    struct link_node *next;
}link_list;

typedef struct LINK_NODE{
    link_list head;
    int size;
}LINKLIST;

// typedef struct user_func{
//     void (*print_student)(const void *);

// }user_function;

typedef void llist_user_show(const void *);
typedef int llist_comp(const void*, const void *);

int list_create(LINKLIST **p, int size);
int list_insert(LINKLIST *p, const void *data, int mode);
void *list_find(LINKLIST *ptr, const void *data, llist_comp *comp);
int list_delete(LINKLIST *ptr, const void *data, llist_comp *comp);
void * list_fetech(LINKLIST *ptr, const void *data, llist_comp *comp, const void *value);
void list_travel(LINKLIST *P);

void list_show(LINKLIST *p, llist_user_show *);
void list_destroy(LINKLIST *p);
#endif