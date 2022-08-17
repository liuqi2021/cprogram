#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "single_struct.h"

int main(){
    linklist *head = NULL;
    int i;
    int ret;
    int data[] = {100, 990, 300, 400, 10};
    int test_data;
    test_data = 1000;

    // head = list_create(head);
    linklist_create1(&head);
    if(head == NULL){
        printf("malloc head failed,exit\n");
        exit(1);
    }
    // for(i = 0; i < sizeof(data)/sizeof(*data); i++){
    //     ret = list_insert(head, i, &data[i]);
    //     if(ret != 0){
    //         linklist_destroy(head);
    //         printf("insert node failed\n");
    //         exit(1);
    //     }
    // }

    // list_insert_tail(head, &test_data);
    // list_insert_head(head, &test_data);
    for(i = 0; i < sizeof(data)/sizeof(*data); i++){
        list_order_insert(head, &data[i]);
    }
    // ret = linklist_delete_data(head, &data[1]);
    // printf("ret = %d\n", ret);
    linklist_show(head);
    linklist_delete_pos(head, 2);
    linklist_show(head);

    linklist_destroy(head);
}