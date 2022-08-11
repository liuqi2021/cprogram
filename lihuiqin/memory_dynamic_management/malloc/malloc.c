#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void malloc_func1(int *p){
    p = malloc(sizeof(int));
    if(p){
        exit(1);
    }
}

void malloc_func2(int **q){
    *q = malloc(sizeof(int));
    if(*q){
        exit(1);
    }
}

int main(){
#if 0
    int i;
    int *p;
    int *q;

    int *arr;
    arr = malloc(4*sizeof(int));
    p = malloc(sizeof(int));
    q = calloc(4, sizeof(int));
    *p = 100;
    printf("%ld\n",sizeof(*p));
    printf("%d\n", *p);


    for(i = 0; i < 4; i++){
        scanf("%d",&arr[i]);
    }
    for(i = 0; i < 4; i++){
        printf("arr[%d] = %d\n",i,arr[i]);
    }
    printf("\n");
    free(p);
    free(q);
    free(arr);
#endif;

    int *p, *q;
    p = NULL;
    q = NULL;
    malloc_func1(p);
    malloc_func2(&q);
    free(p);
    free(q);
    exit(1);

}
