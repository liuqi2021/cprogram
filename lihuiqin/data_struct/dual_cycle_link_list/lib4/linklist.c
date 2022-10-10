#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linklist.h"

struct link_node{
    struct link_node *pre;
    struct link_node *next;
    char data[1];
};

struct LINK_NODE{
    struct link_node head;
    int size;
    int (*insert)(struct LINK_NODE *, const void *, int);
    int (*delete)(struct LINK_NODE *ptr, const void *data, llist_comp *comp);
    void (*show)(struct LINK_NODE *p, llist_user_show *);
};

int list_insert(LINKLIST *p, const void *data, int mode);




int list_create(LINKLIST **p, int ssize){
    struct LINK_NODE **ptr = p;
    *ptr = malloc(sizeof(**ptr));
    if(*ptr == NULL){
        return -1;
    }
    // (*p)->head.data = NULL;

    (*ptr)->head.pre = &((*ptr)->head);
    (*ptr)->head.next = &((*ptr)->head);
    (*ptr)->size = ssize;
    (*ptr)->insert = list_insert;
    (*ptr)->delete = list_delete;
    (*ptr)->show = list_show;

    return 0;
}

int list_insert(LINKLIST *ptr, const void *data, int mode){
    struct LINK_NODE *p = ptr;
    struct link_node *new_node;
    new_node = malloc(sizeof(*new_node) + p->size - 4);
    if(new_node == NULL){
        return -1;
    }
    // new_node->data = malloc(p->size);
    // if(new_node->data == NULL){
    //     free(new_node);
    //     return -1;
    // }
    memcpy(new_node->data, data, p->size);
    switch(mode){
        case(INSERT_FORWARD):
            new_node->next = p->head.next;
            new_node->pre = &p->head;
            break;
        case(INSERT_BACKUP):
            new_node->next = &p->head;
            new_node->pre = p->head.pre;
            break;
        default:
            return -2;
    }
    new_node->next->pre = new_node;
    new_node->pre->next = new_node;
    return 0;
}

static void *find_(LINKLIST *ptr, const void *data1, llist_comp *comp){
    struct LINK_NODE *p = ptr;
    struct link_node *tmp;
    int ret;
    for(tmp = p->head.next; tmp != &p->head; tmp = tmp->next){
        ret = comp(data1, tmp->data);
        if(ret == 0){
            break;
        }
    }
    if(ret != 0){
        return NULL;
    }
    return tmp;
}

void * list_find(LINKLIST *ptr, const void *data, llist_comp *comp){
    struct LINK_NODE *p = ptr;
    struct link_node *tmp;
    tmp = find_(ptr, data, comp);
    if(tmp == &p->head){
        return NULL;
    }
    return tmp->data;
}
int list_delete(LINKLIST *p, const void *data, llist_comp *comp){
    struct LINK_NODE *ptr = p;
    struct link_node *tmp;
    struct link_node *tmp;
    tmp = find_(ptr, data, comp);
    if(tmp == &ptr->head){
        return -1;
    }
    tmp->pre->next = tmp->next;
    tmp->next->pre = tmp->pre;
    // free(tmp->data);
    free(tmp);
    return 0;
}

void * list_fetech(LINKLIST *p, const void *data, llist_comp *comp, const void *value){
    struct LINK_NODE *ptr = p;
    struct link_node *tmp;
    tmp = find_(ptr, data, comp);
    if(tmp == &ptr->head){
        return NULL;
    }
    tmp->pre->next = tmp->next;
    tmp->next->pre = tmp->pre;
    if(value != NULL){
        // memcpy(value, tmp->data, sizeof(*data));
        memcpy(value, tmp->data, ptr->size);
    }

    // free(tmp->data);
    free(tmp);
    return value;
}

void list_show(LINKLIST *ptr, llist_user_show *print_students){
    struct LINK_NODE *p = ptr;
    struct link_node *tmp = p->head.next;
    do{
        print_students(tmp->data);
        tmp = tmp->next;
    }while(tmp != &p->head);

}
void list_destroy(LINKLIST *ptr){
    struct LINK_NODE *p = ptr;
    struct link_node *tmp;
    struct link_node *next;
    for(tmp = p->head.next; tmp != &p->head; tmp = next){
        next = tmp->next;
        // free(tmp->data);
        free(tmp);
    }
    free(p);
}