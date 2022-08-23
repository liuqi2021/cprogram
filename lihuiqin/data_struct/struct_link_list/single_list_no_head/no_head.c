#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "no_head.h"

int list_insert(linklist **p, struct student *data){
    linklist *tmp;
    tmp = malloc(sizeof(*tmp));
    if(tmp == NULL){
        // printf("%d\n",__LINE__);
        return -1;
    }
    tmp->data = *data;
    tmp->next = *p;
    *p = tmp;

    return 0;
    
}
int list_delete(linklist **p){
    linklist *del_node;
    if(*p == NULL){
        return -1;
    }
    del_node = *p;
    *p = (*p)->next;
    free(del_node);
    return 0;
}
int list_find(linklist *p, int data){
    linklist *find_node = p;
    if(p == NULL){
        return -1;
    }

    while(p->next != NULL){
        if(p->data.id == data){
            return 0;
        }
        p = p->next;
    }

    return -2;


}
void list_show(linklist *p){
    linklist *tmp = p;
    while(tmp){
        printf("%d\n",__LINE__);
        printf("id = %d name = %s math = %d chinese = %d\n",tmp->data.id, tmp->data.name, tmp->data.math, tmp->data.chinese);
        tmp = tmp->next;
    }

}