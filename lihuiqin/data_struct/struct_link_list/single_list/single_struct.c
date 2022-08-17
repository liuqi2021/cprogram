#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "single_struct.h"



linklist * list_create(linklist *p){
    p = malloc(sizeof(*p));
    if(p == NULL)
        return NULL;

    p->next = NULL;
    return p;
}

void linklist_create1(linklist **p){
    *p = malloc(sizeof(**p));
    (*p)->next = NULL;
}

int list_insert(linklist *p, int pos, datatype *data){
    int i = 0;
    linklist *node = p;
    linklist *insert_node = NULL;
    if(pos < 0)
        return -1;
    while(i < pos && node != NULL){
        node = node->next;
        i++;
    }
    if(node){
        insert_node = malloc(sizeof(*insert_node));
        if(insert_node == NULL){
            return -2;
        }
        insert_node->next = node->next;
        node->next = insert_node;
        insert_node->score = *data;
    }
    else
        return -3;
        
    return 0;
}

int list_insert_tail(linklist *p, datatype *data){
    linklist *tail_node;
    linklist *node = p;
    while(node->next != NULL){
        node = node->next;
    }
    tail_node = malloc(sizeof(*tail_node));
    node->next = tail_node;
    tail_node->score = *data;
    tail_node->next = NULL;
    return 0;
}

int list_insert_head(linklist *p, datatype *data){
    linklist *head_node;
    linklist *node = p;
    head_node = malloc(sizeof(*head_node));
    if(node->next == NULL){
        node->next = head_node;
    }
    else{
        head_node->next = node->next;
        node->next = head_node;
    }
    head_node->score = *data;
    return 0;

}

int list_order_insert(linklist *p, int *data){
    linklist *node = NULL;
    linklist *list = p;
    while(list->next && list->next->score < *data){
        list = list->next;
    }
    node = malloc(sizeof(*node));
    if(node == NULL){
        return -1;
    }
    node->score = *data;
    node->next = list->next;
    list->next = node;
    return 0;
}
int linklist_delete_pos(linklist *p, int pos){
    linklist *delete_pos;
    linklist *list = p;
    int i = 0;
    if(pos <= 0){
        return -1;
    }
    while(i < pos && list){
        list = list->next;
        i++;
    }
    if(list){
        delete_pos = list->next;
        list->next = delete_pos->next;
        printf("delet_value = %d\n",delete_pos->score);
        free(delete_pos);
    }
    else{
        return -1;
    }
    return 0;
}

int linklist_delete_data(linklist *p, datatype *data){
    linklist *delete_node;
    linklist *list = p;
    while(list->next){
        if(list->next->score == *data){
            delete_node = list->next;
            list->next = delete_node->next;
            free(delete_node);
        }
        // if(list->next == NULL){
        //     return -1;
        // }
        list = list->next;
    }
    return 0;
}

int linklist_is_empty(linklist *p){
    if(p->next == NULL)
        return 0;
    return 1;
}

void linklist_show(linklist *p){
    linklist *node = p->next;
    if(linklist_is_empty(node) == 0)
        return;

    while(node != NULL){
        printf("%3d  ",node->score);
        node = node->next;
    }
    printf("\n");
    return;
}

void linklist_destroy(linklist *p){
    linklist *node = p, * next;
    if(linklist_is_empty(node) == 0)
        free(p);
        return;
    while(node != NULL){
        next = node->next;
        free(node);
        node = next;
    }
    free(p);
    return;
}