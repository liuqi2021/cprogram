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

    struct stat stat_result;
    int ret;
    ret = stat(argv[1], &stat_result);
    if(ret < 0){
        perror("stat()");
        exit(1);
    }

    printf("size = %ld\n",stat_result.st_size);
    exit(0);
}