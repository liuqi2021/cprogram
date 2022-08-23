#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "no_head.h"

int main(){
    int i, ret;
    struct student tmp;
    linklist *list = NULL;
    for(i = 0; i < 10; i++){
        tmp.id = i;
        snprintf(tmp.name, 1024, "std%d", i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;
        list_insert(&list, &tmp);
    }
    // printf("%d\n",__LINE__);
    list_delete(&list);
    list_show(list);
    ret = list_find(list, 1);
    printf("ret = %d\n",ret);

    exit(0);
}

