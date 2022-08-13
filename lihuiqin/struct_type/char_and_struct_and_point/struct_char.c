#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct test_st{
    int i;
    char str1[111];
    char str2; // wrong type, str[] or *str, no str!!!!
    char *str3;
    int j;
}test;

int main(){
    test.i = 100;
    // test.str1[111] = "liuqi";
    strcpy(test.str1, "luqi");  //Right, str1 already has memory size;
    strcpy(test.str3, "l");  //Wrong, str3 is a point and has no value, we should allocate some memory to it
    printf("%p i = %d\n",&test.i, test.i);
    printf("%p %s\n",test.str1, test.str1);
    puts(test.str1);


    exit(1);
}