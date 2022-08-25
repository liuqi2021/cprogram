#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct node_st{
    int pos;
    struct node_st *next;
}linklist;


int jose_create_tail(linklist **p, int *data){
    linklist *tmp, *tail, *current;
    tail = *p;
    tmp = malloc(sizeof(*tmp));

    if(*p == NULL){
        tmp->pos = *data;
        *p = tmp;
        (*p)->next = *p;
        return 0;
    }


    if(tmp == NULL){
        return -1;
    }
    printf("%d\n", __LINE__);
    tmp->pos = *data;
    while(tail->next != *p){
        tail = tail->next;
    }
    tmp->next = *p;
    tail->next = tmp;
    return 0;
}

int jose_create_head(linklist **p, int *data){
    linklist *tmp, *tail, *current;
    tail = *p;
    tmp = malloc(sizeof(*tmp));

    if(*p == NULL){
        tmp->pos = *data;
        *p = tmp;
        (*p)->next = *p;
        return 0;
    }

    if(tmp == NULL){
        return -1;
    }
    tmp->pos = *data;
    tmp->next = *p;
    while(tail->next != *p){
        tail = tail->next;
    }
    tail->next = tmp;
    *p = tmp;
    return 0;
}


void jose_show(linklist *p){
    linklist *tmp;
    tmp = p;
    do{
        printf("%3d", tmp->pos);
        tmp = tmp->next;
    }while(tmp != p);
    printf("\n");
}

linklist * jose_kill(linklist *p, int num){
    linklist *tmp;
    linklist *del_node = p;

    int i = 1;
    while(del_node != del_node->next ){
        while(i < num){
            tmp = del_node;
            del_node = del_node->next;
            i++;
        }
        printf("%d\n",del_node->pos);
        tmp->next = del_node->next;
        free(del_node);
        del_node = tmp->next;
        i = 1;
    }
    return del_node;
}
void jose_show_all(linklist *p){
    linklist *tmp;
    tmp = p;
    do{
        printf("%3d", tmp->pos);

        tmp = tmp->next;
        // sleep(1);
        // fflush(stderr);
    }while(tmp != NULL);
    printf("\n");
}

int main(){
    int array[] = {15, 48, 33, 22, 56};
    // int array[] = {15};
    linklist *p = NULL;
    int i;
    for(i = 0; i < sizeof(array)/sizeof(*array); i++){
        jose_create_head(&p, &array[i]);
        // printf("%p\n",p);
    }
    jose_show(p);
    p = jose_kill(p, 3);
    jose_show(p);
}