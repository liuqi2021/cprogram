#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

#define NAMESIZE 32
struct student_st{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

void st_set(struct student_st *p, struct student_st *q){
    // p->id = 10011;
    // strcpy(p->name, "allen");
    // p->math = 100;
    // p->chinese = 99;
    *p = *q;
}

void st_show(struct student_st *p){
    printf("id = %d\n",p->id);
    printf("name = %s\n",p->name);
    printf("math = %d\n",p->math);
    printf("chinese = %d\n",p->chinese);
}

void st_changname(struct student_st *p){
    strcpy(p->name, "mary");
}

int menu(){
    int oper;
    printf("please input your operation:\n 1:set\n 2:show\n 3rename\n");
    printf("q for exit\n");
    scanf("%d", &oper);
    return oper;
}

int main(){
    struct student_st stu,tmp;
    struct student_st *p = &stu;
    int oper;
    do{
        oper = menu();
        switch(oper){
            case(1):
                printf("please input info:id, name, math, chinese\n");
                scanf("%d%s%d%d",&tmp.id,tmp.name,&tmp.math,&tmp.chinese);
                st_set(p, &tmp);
                break;
            case(2):
                st_show(p);
                break;
            case(3):
                st_changname(p);
                st_show(p);
                break;
            default:
                exit(1);
        }
    }while(1);
    exit(0);
}