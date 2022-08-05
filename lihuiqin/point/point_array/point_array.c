#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int array[3] = {100, 200, 300};
    int (*p)[3] = &array;
    int *q = array;
    int i = 99;
    char *str[3] = {"hello", "world", "!"};
    int *array2[3] = {100, 200, 300};
    // int *q = array;
    // int *r = &array;
    printf("array[0] = %d\n", (*p)[0]);
    printf("array[1] = %d\n", (*p)[1]);
    printf("array[2] = %d\n", *(*p+2));
    printf("array[1] = %d\n", *(q+1));
    printf("array[1] = %d\n", q[1]);
    puts(str[1]);
    printf("%c\n", str[1][1])
;    printf("i = %p, &i = %p\n", i, &i);
    exit(0);    
}