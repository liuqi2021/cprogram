#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1[] = "hello_word!";
    char *str2 = "hello world";
    char *p = str1;
    printf("sizeof(str1) = %ld, strlen(str1) = %ld\n", sizeof(str1), strlen(str1));
    printf("sizeof(str2) = %ld, strlen(str2) = %ld\n", sizeof(str2), strlen(str2));
    puts(p+1);
    strcpy(p, "hello_china");
    puts(p);
    strcpy(str1, "hello_word");
    puts(str1);
    puts(p);

    puts(str2);
    strcpy(str2, "fight_ame"); // str2 shi yi ge zhi zhen,er "hello world"shi yige chang liang,chang liang bu ke yi bei gaibian,yinci baocuo
    puts(str2);
    
    exit(0);
}