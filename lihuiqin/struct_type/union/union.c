#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

union{
    struct{
        uint16_t i;
        uint16_t j;
    }x;
    uint32_t y;
}bitand;

union{
    struct{
        char a:1;
        char b:2;
        char c:1;
    }bit;
    char c;
}bit_field;

int main(){
    // uint32_t i = 0x11223344;
    // printf("%x\n",(i >> 16) + i & 0xffff);
    // exit(0);
    bitand.y = 0x11223344;
    printf("%x\n",bitand.x.i);
    printf("%x\n",bitand.x.j);

    bit_field.c = 0x0000;
    printf("%x\n",bit_field.c);
    printf("%x\n",bit_field.bit.a);
    printf("%d\n",bit_field.bit.a);
    printf("%x\n",bit_field.bit.b);
    printf("%d\n",bit_field.bit.b);
    exit(0);
}