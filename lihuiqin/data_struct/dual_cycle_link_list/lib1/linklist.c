#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linklist.h"

int list_create(LINKLIST **p, int ssize){
    *p = malloc(sizeof(**p));
    if(*p == NULL){
        return -1;
    }
    (*p)->head.data = NULL;

    (*p)->head.pre = &((*p)->head);
    (*p)->head.next = &((*p)->head);
    (*p)->size = ssize;

    return 0;
}

int list_insert(LINKLIST *p, const void *data, int mode){
    link_list *new_node;
    new_node = malloc(sizeof(*new_node));
    if(new_node == NULL){
        return -1;
    }
    new_node->data = malloc(p->size);
    if(new_node->data == NULL){
        free(new_node);
        return -1;
    }
    memcpy(new_node->data, data, p->size);
    switch(mode){
        case(INSERT_FORWARD):
            new_node->next = p->head.next;
            new_node->pre = &p->head;
            // new_node->next->pre = new_node;
            // new_node->pre->next = new_node;
            break;
        case(INSERT_BACKUP):
            new_node->next = &p->head;
            new_node->pre = p->head.pre;
            // new_node->next->pre = new_node;
            // new_node->pre->next = new_node;
            break;
        default:
            return -2;
    }
    new_node->next->pre = new_node;
    new_node->pre->next = new_node;
    return 0;
}

static void *find_(LINKLIST *p, const void *data1, llist_comp *comp){
    link_list *tmp;
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
    link_list *tmp;
    tmp = find_(ptr, data, comp);
    if(tmp == NULL){
        return NULL;
    }
    return tmp->data;
}
int list_delete(LINKLIST *ptr, const void *data, llist_comp *comp){
    link_list *tmp;
    tmp = find_(ptr, data, comp);
    if(tmp == NULL){
        return -1;
    }
    tmp->pre->next = tmp->next;
    tmp->next->pre = tmp->pre;
    free(tmp->data);
    free(tmp);
    return 0;
}

void * list_fetech(LINKLIST *ptr, const void *data, llist_comp *comp, const void *value){
    link_list *tmp;
    tmp = find_(ptr, data, comp);
    if(tmp == NULL){
        return NULL;
    }
    tmp->pre->next = tmp->next;
    tmp->next->pre = tmp->pre;
    if(value != NULL){
        // memcpy(value, tmp->data, sizeof(*data));
        memcpy(value, tmp->data, ptr->size);
    }

    free(tmp->data);
    free(tmp);
    return value;
}

void list_show(LINKLIST *p, llist_user_show *print_students){
    link_list *tmp = p->head.next;
    do{
        print_students(tmp->data);
        tmp = tmp->next;
    }while(tmp != &p->head);

}
void list_destroy(LINKLIST *p){
    link_list *tmp;
    link_list *next;
    for(tmp = p->head.next; tmp != &p->head; tmp = next){
        next = tmp->next;
        free(tmp->data);
        free(tmp);
    }
    free(p);
}