#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
    int i = 0;
    char *s = "hello";
    char s1[] = "ssss";
    printf("s1 = %s\n", s1);
    printf("s = %s\n", s);
    puts(s1);
    while(argv[i]){
        // puts(argv[i]);
        printf("%s\n", argv[i]);
        printf("%p\n", argv[i]);
        i++;
    }

}