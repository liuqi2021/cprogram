#include <stdio.h>
#include <stdlib.h>

struct info_1{
    int i;
    char name;
    float j;
    char addr;
};

struct info_2{
    int f;
    struct info_1 info;
};

int main(){
    struct info_1 a;
    struct info_2 b;
    printf("sizeof(info_1) = %ld\n", sizeof(a));
    printf("sizeof(info_2) = %ld\n", sizeof(b));

    exit(0);
}