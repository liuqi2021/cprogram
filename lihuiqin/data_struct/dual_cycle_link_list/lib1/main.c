#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linklist.h"
#define NAMESIZE 32


typedef struct struct_student{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
}stu_st;



void print_student(const void *ptr){
    const stu_st *p = ptr;
    printf("%d %d %d %s\n",p->id, p->math, p->chinese, p->name);
}

static int id_comp(const void *key, const void *record){
    const int *dest  = key;
    const stu_st *target = record;
    if(target->id == *dest){
        return 0;
    }
    return -1;
}

int main(){
    int i, ret1, ret2, id;
    // user_function student;
    LINKLIST *head = NULL;
    list_create(&head, sizeof(struct struct_student));
    stu_st tmp, *tmp1, *value;
    for(i = 0; i < 7; i++){
        tmp.id = i;
        snprintf(tmp.name, NAMESIZE, "stu%d", i);
        tmp.math = random() % 100;
        tmp.math = random() % 100;
        ret1 = list_insert(head, &tmp, INSERT_BACKUP);
        if(ret1 != 0){
            list_destroy(head);
            exit(1);
        }
    }
    
    id = 3;
    tmp1 = list_find(head, &id, id_comp);
    if(tmp1 == NULL){
        printf("mismatch!!!\n");
    }
    else{
        printf("id = %d\n",tmp1->id);
        print_student(tmp1);
    }
    // ret2 = list_delete(head, &id, id_comp);
    // if(ret2 != 0){
    //     printf("delete failed\n");
    // }
    value = malloc(sizeof(*value));
    value = list_fetech(head, &id, id_comp, value);
    if(value == NULL){
        printf("find and delete failed\n");
    }
    else{
        print_student(value);
    }
    list_show(head, print_student);
    list_destroy(head);


    exit(0);
}