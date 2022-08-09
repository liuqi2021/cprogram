#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 128

struct birth_st{
    int year;
    int month;
    int day;
};

struct struct_student{
    int id;
    char name[SIZE];
    struct birth_st birth;
    int math;
    int chinese;
};

int main(){
    struct struct_student stu1 = {20220808, "mary", {1994, 06, 04}, 100, 99};
    struct struct_student *p;
    p = &stu1;
    printf("ID = %d\n", stu1.id);
    printf("name = %s\n", p->name);
    printf("birth:%d-%d-%d\n",(*p).birth.year,(*p).birth.month,(*p).birth.day);



    exit(0);

}