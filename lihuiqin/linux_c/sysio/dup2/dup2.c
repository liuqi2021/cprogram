#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
    int fd;
    fd = open("/tmp/out", O_RDONLY|O_CREAT, 0660);

    dup2(fd, 1);
    if(fd != 1){
        close(fd);
    }

    puts("hello");
}