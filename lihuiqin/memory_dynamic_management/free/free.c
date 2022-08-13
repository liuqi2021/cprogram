#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p;
    p = malloc(sizeof(int));
    if(p == NULL){
        printf("malloc failed!\n");
        exit(1);
    }
    *p = 100;
    printf("%p-->%d\n",p, *p);
    free(p);
    p = NULL;
    *p = 200;
    printf("%p-->%d\n",p, *p);
    exit(0);

}