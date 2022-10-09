#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char **argv){

    if(argc < 2){
        fprintf(stderr, "Usage:\n");
        exit(1);
    }
    int fd;
    fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0600);
    if(fd < 0){
        perror("open()");
        exit(1);
    }

    // lseek(fd, 5*1024*1024*1024-1, SEEK_SET);
    lseek(fd, 5LL*1024LL*1024LL*1024LL-1LL, SEEK_SET);
    write(fd, "", 1);


    close(fd);
    exit(0);
}