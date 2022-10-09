#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE 16777212
int main(int argc, char *argv[]){
    char buf[BUFSIZE];
    size_t len;
    int ret, pos;
    if(argc < 3){
        perror("fopen");
        fprintf(stderr, "fopen()%d\n", errno);
        puts(strerror(errno));
        exit(1);
    }
    int fd_source, fd_dest;
    fd_source = open(argv[1], O_RDONLY);
    fd_dest = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0600);

    while(1){
        len = read(fd_source, buf, BUFSIZE);
        if(len < 0){
            break;
        }
        if(len == 0){
            break;
        }
        pos = 0;
        while(len > 0){
            ret = write(fd_dest, buf+pos, len);
            if(ret < 0){
                perror("write()");
                exit(1);
            }
            pos += ret;
            len-=ret;
            

        }
    }

    close(fd_dest);
    close(fd_source);
    exit(0);
}