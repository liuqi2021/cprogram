#include <stdio.h>
#include <stdlib.h>


int main(){
    int i = 99;
    int *p = &i;
    float *q = &i;
    printf("i = %d\n", i);
    printf("p = %p\n", p);
    printf("&p = %p\n", &p);
    printf("*p = %d\n", *p);
    printf("q = %p\n", q);
    printf("&q = %p\n", &q);
    printf("*q = %d\n", *q);

    exit(0);
}