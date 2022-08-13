#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

#define NAMESIZE 1024
struct student_st{
    int id;
    char *name;
    int math;
    int chinese;
};

void st_set(struct student_st *p, const struct student_st *q){
    // p->id = 10011;
    // strcpy(p->name, "allen");
    // p->math = 100;
    // p->chinese = 99;
    //*p = *q; //wrong,it means p->name = q->name, that means when q changed, p changed, too
    p->id = q->id;
    p->name = malloc(strlen(q->name)+1);
    if(p->name == NULL){
        printf("request memory failed, exit!");
        exit(1);
    }
    strcpy(p->name, q->name);
    p->math = q->math;
    p->chinese = q->chinese;
    printf("%s  %d\n",p->name, p->math);
}

void st_show(struct student_st *p){
    printf("id = %d\n",p->id);
    printf("name = %s\n",p->name);
    printf("math = %d\n",p->math);
    printf("chinese = %d\n",p->chinese);
}

void st_changname(struct student_st *p, char *name){
    free(p->name);
    p->name = malloc(strlen(name)+1); //p>name = realloc(p->name, strlen(name)+1))
    if(p->name == NULL){
        printf("request memory failed, exit!");
        exit(1);
    }
    //strcpy(p->name, "mary");//
    strcpy(p->name, name);
}

void menu(){
    int oper;
    printf("please input your operation:\n 1:set\n 2:show\n 3rename\n");
    printf("q for exit\n");
}

int main(){
    struct student_st stu,tmp;
    struct student_st *p = &stu;
    char newname[NAMESIZE];
    int oper;
    int ret;
    do{
        menu();
        ret = scanf("%d", &oper);
        if(ret != 1)
            break;
        switch(oper){
            case(1):
                printf("please input info:id, name, math, chinese\n");
                tmp.name = malloc(NAMESIZE);
                scanf("%d%s%d%d",&tmp.id,tmp.name,&tmp.math,&tmp.chinese);
                st_set(p, &tmp);
                free(tmp.name);
                break;
            case(2):
                st_show(p);
                break;
            case(3):
                printf("Please input new name\n");
                scanf("%s",newname);
                st_changname(p, newname);
                st_show(p);
                break;
            default:
                exit(1);
        }
    }while(1);
    exit(0);
}