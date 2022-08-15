#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linear_link_list.h"

sqlite * sqlite_create(){
    sqlite *point = NULL;
    point = malloc(sizeof(*point));
    if(point == NULL){
        printf("request memory failed, exit~\n");
        return NULL;
    }
    point->count = -1;
    return point;
}

void sqlite_create1(sqlite **p){
    *p = malloc(sizeof(**p));
    if(*p == NULL){
        printf("request memory failed, exit~\n");
        // return NULL;
    }
    // return *p;
    (*p)->count = -1;
}

int sqlite_insert(sqlite *p, int i, datatype *data){
    int j;
    if(i-1 > p->count || i < 0){
        printf("error, cant not insert at position:%d\n",i);
        return -2;
    }
    for(j = p->count; j >= i; j--){
        printf("j=%d ",j);
        p->data[j+1] = p->data[j];
    }
    p->count++;
    p->data[i] = *data;
    printf("i=%d,data[] = %d\n",i, p->data[i]);
    return 0;
}

int sqlite_delete(sqlite *p, int i){
    int j;
    if(i < 0 || i > p->count){
        return -1;
    }
    for(j = i; j < p->count; j++){
        p->data[j] = p->data[j+1];
    }
    p->count--;
    return 0;

}
void sqlite_show(sqlite *p){

    int i = 0;
    if(p->count == -1){
        exit(1);
    }
    for (i = 0; i <= p->count; i++){
        printf("%d ",p->data[i]);
    }
    printf("\n");
}

int sqlite_getcount(sqlite *p){
    int count;
    count = p->count;
    return count+1;
}

int sqlite_setempty(sqlite *p){
    p->count = -1;
    return 0;
}

int sqlite_istempty(sqlite *p){
    if(p->count < 0)
        return -1;
    return 0;
}

int sqlite_find(sqlite *p, int data){
    int i = 0;
    if(sqlite_istempty(p)  == -1){
        printf("%d\n",__LINE__);
        return -1;
    }

    for(i = 0; i < p->count; i++){
        if((p->data)[i] == data){
            return i;
        }

    }
    return -1;
}

void sqlite_merge(sqlite *list1, sqlite *list2){
    int i;
    
    for(i = 0; i <= list2->count; i++){
        if((sqlite_find(list1, list2->data[i])) < 0){
            // printf("insert %d\n",list2->data[i]);
            sqlite_insert(list1, 0, &list2->data[i]);
        }
    }
}
void sqlite_destory(sqlite **p){
    free(*p);
    *p = NULL; 
}

// sqlite