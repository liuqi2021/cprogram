#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * mycpy(char * const dest, const char * src){
    int i = 0;
    for(i = 0; (dest[i] = src[i]); i++){
        ;
    }
}

char *myncpy(char * const dest, const char * src, int n){
    int i;
    for(i = 0; i < n && (dest[i] = src[i]); i++){
        ;
    }
    for(;i < n ; i++){
        printf("111");
        dest[i] = '\0';
    }
}

int main(){
    char str1[] = "hello_world!";
    char str2[128];
     char str3[128];
    mycpy(str2, str1);
    puts(str2);
    myncpy(str2, str1, 3);
    puts(str2);
    exit(0);
}