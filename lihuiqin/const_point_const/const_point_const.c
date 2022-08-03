#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592653

 
int main(){
    int i = 100;
    int j = 200;
    const int *p = &i;
    int * const q = &i;
    const int * const r = &i;

    //*p = 300;
    //q = &j;
    //r = &j;
    p = &j;
    *q = 999;
    printf("*p = %d\n", *p);
    printf("*q = %d\n", *q);

    
    exit(0);
}