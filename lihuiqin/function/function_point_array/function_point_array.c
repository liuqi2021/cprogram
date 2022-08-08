#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int add(int a, int b){
    return (a+b);
}

int minor(int a, int b){
    return (a-b);
}

int main(){
    int a, b;
    int i = 0;
    a = 100;
    b = 200;
    int ret;
    int (*p[2])(int, int);
    p[0] = add;
    p[1] = minor;
    for(i = 0; i < 2; i++){
        ret = p[i](a, b);
        printf("ret = %d\n", ret);
    }
}