#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    putchar('a');
    write(1,"b",1);
    putchar('a');
    write(1,"b",1);
    putchar('a');
    write(1,"b",1);
    exit(0);
}