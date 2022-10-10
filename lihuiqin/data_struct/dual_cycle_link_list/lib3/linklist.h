#ifndef LINKLIST_H__
#define LINKLIST_H__

#define INSERT_FORWARD 0
#define INSERT_BACKUP 1

typedef int llist_comp(const void*, const void *);
typedef void llist_user_show(const void *);


typedef struct link_node{
    struct link_node *pre;
    struct link_node *next;
    char data[1];
}link_list;

typedef struct LINK_NODE{
    link_list head;
    int size;
    int (*insert)(struct LINK_NODE *, const void *, int);
    int (*delete)(struct LINK_NODE *ptr, const void *data, llist_comp *comp);
    void (*show)(struct LINK_NODE *p, llist_user_show *);
}LINKLIST;

// typedef struct user_func{
//     void (*print_student)(const void *);

// }user_function;




int list_create(LINKLIST **p, int size);

void *list_find(LINKLIST *ptr, const void *data, llist_comp *comp);
int list_delete(LINKLIST *ptr, const void *data, llist_comp *comp);
void * list_fetech(LINKLIST *ptr, const void *data, llist_comp *comp, const void *value);
void list_travel(LINKLIST *P);

void list_show(LINKLIST *p, llist_user_show *);
void list_destroy(LINKLIST *p);
#endif