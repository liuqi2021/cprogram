#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linear_link_list.h"

int main(){

    int i, ret;
    sqlite *list1 = NULL;
    sqlite *list2 = NULL;
    int pos, count;
    datatype data1[] = {100, 56, 89, 73, 24};
    datatype data2[] = {99, 56, 65, 73, 22,24,9};

    list1 = sqlite_create();
    printf("&list1 = %p\n", list1);
    list2 = sqlite_create();
    printf("&list2 = %p\n", list2);
    if(list1 == NULL || list2 == NULL){
        fprintf(stderr, "sqlist_create()\n");
        exit(1);
    }
    else{
        printf("succed\n");
    }

    for(i = 0; i < sizeof(data1)/sizeof(*data1); i++){
        ret = sqlite_insert(list1, i, &data1[i]);
        if(ret != 0){
            fprintf(perror,"sqlite_insert()\n");
            exit(1);
        }
    }


    for(i = 0; i < sizeof(data2)/sizeof(*data2); i++){
        ret = sqlite_insert(list2, i, &data2[i]);
        if(ret != 0){
            fprintf(perror,"sqlite_insert()\n");
            exit(1);
        }
    }
    sqlite_show(list1);
    sqlite_show(list2);
    sqlite_merge(list1, list2);

    count = sqlite_getcount(list1);
    printf("The length of linear list is %d\n", count);
    sqlite_show(list1);
    sqlite_show(list2);



    // sqlite_show(list);
    // sqlite_delete(list, 2);
    // sqlite_show(list);
    // sqlite_delete(list, 5);
    // sqlite_show(list);
    // count = sqlite_getcount(list);
    // printf("The length of linear list is %d\n", count);
    // pos = sqlite_find(list, 56);
    // if(pos == -1){
    //     printf("%d is not in list\n",56);
    // }
    // printf("pos = %d\n", pos);
    printf("%d",__LINE__);
    sqlite_destory(&list1);
    printf("%d",__LINE__);
    sqlite_destory(&list2);
    exit(0);
}