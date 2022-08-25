#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "polynominal.h"

linklist * poly_create(int a[][2], int cnt){
    linklist *p, *insert_node, *tmp;
    int i;
    p = malloc(sizeof(*p));
    if(p == NULL){
        return NULL;
    }
    p->next = NULL;
    tmp = p;
    for(i = 0; i < cnt; i++){
        insert_node = malloc(sizeof(*insert_node));
        if(insert_node == NULL){
            free(p);
            return NULL;
        }
        insert_node->coe = *(*(a+i)+0);
        insert_node->exp = *(*(a+i)+1);

        insert_node->next = NULL;
        tmp->next = insert_node;
        tmp = insert_node;
    }
    return p;

}

int poly_merge(linklist *p1, linklist *p2){
    linklist *merge_list = p1;
    linklist *list1 = p1->next;
    linklist *list2 = p2->next;
    linklist * del_node;

    while(list1 && list2){
        if(list1->exp < list2->exp){
            merge_list->next = list1;
            merge_list = list1;
            list1 = list1->next;

        }
        else if(list1->exp > list2->exp){
                merge_list->next = list2;
                merge_list = list2;
                list2 = list2->next;

            }
            else{
                list1->coe = (list1->coe + list2->coe);
                
                if(list1->coe == 0){
                    list1 = list1->next;
                    list2 = list2->next;
                }
                else{
                    merge_list->next = list1;
                    merge_list = list1;
                    list1 = list1->next;
                    list2 = list2->next;
                }

            }
    }
    if(list1 == NULL){
        merge_list->next = list2;
    }
    else
        merge_list->next = list1;
}

void poly_show(linklist *p){

    linklist *tmp = p->next;
    while(tmp){
        printf("coe = %d exp = %d\n", tmp->coe, tmp->exp);
        tmp = tmp->next;
    }
}

