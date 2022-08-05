#include <stdio.h>
#include <stdlib.h>

int * add(int a, int b, int *q){
    int sum;
    sum = (a + b);
    printf("sum = %d\n", sum);
    q = &sum;
    return q;
}

int  minor(int a, int b){
    int sum;
    sum = (a - b);
    return sum;
}

int main(){
    int *p;
    int *q;
    int a, b;
    int (*func1)(int, int);
    a = 10;
    b = 33;
    p = add(a, b, q);
    printf("sum = %d\n", *p);
    func1 = minor(b, a);
    printf("monor = %d\n", *func1);
    exit(0);
}