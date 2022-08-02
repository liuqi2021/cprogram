#include <stdio.h>
#include <stdlib.h>

int main(){
    int array[2][3] = {3, 5, 1, 7, 4, 8};
    int *p = array;
    int *q = array[0]; // xiang dang yu *array
    int i = 100;
    int *r = &i;
    printf("i = %d\n", r[0]);
    printf("%p, %p\n", array, array+1);
    printf("%d, %d\n", **(array), **(array+1));
    printf("%p, %p\n", p, p+1);
    printf("%d, %d\n", (*p), *(p+1));
    printf("%d, %d\n", (*q), *(q+1));
    printf("%d, %d\n", (*q), (q[1]));
    printf("%d\n", *(array[1]));
}