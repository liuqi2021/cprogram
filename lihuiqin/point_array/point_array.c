#include <stdio.h>
#include <stdlib.h>

int main(){
    int array[3] = {100, 200, 300};
    int (*p)[3] = &array;
    int *q = array;
    // int *q = array;
    // int *r = &array;
    printf("array[0] = %d\n", (*p)[0]);
    printf("array[1] = %d\n", (*p)[1]);
    printf("array[2] = %d\n", *(*p+2));
    printf("array[1] = %d\n", *(q+1));
    printf("array[1] = %d\n", (*q)[1]);
    exit(0);    
}