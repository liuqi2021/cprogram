#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
    int fd;
    // close(1);
    // fd = open("/tmp/out", O_RDWR|O_CREAT, 0660);
    // write(fd, "fd = %d\n", 1024);


    fd = open("/tmp/out", O_RDWR|O_CREAT, 0660);
    // write(fd, "fd = %d\n", 1024);
    close(1);

    dup(fd);
    close(fd);






    puts("hello");
    exit(0);
}