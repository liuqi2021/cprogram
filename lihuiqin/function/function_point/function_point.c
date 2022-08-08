#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int add(int a, int b){
    return (a+b);
}

int main(){
    int a, b;
    a = 100;
    b = 200;
    int ret;
    int (*p)(int, int);
    p = add;
    ret = p(a, b);
    printf("ret = %d\n", ret);
}