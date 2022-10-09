#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
    if(argc < 2){
        fprintf(stderr, "Usage:\n");
        exit(1);
    }
    int i = 0;
    FILE *fp;
    char *linebuf;
    size_t linesize;
    fp = fopen(argv[1], "r");
    if(fp == NULL){
        perror("fopen:");
    }
    printf("1111111111\n");
    while(1){
        i++;
        if(getline(&linebuf, &linesize, fp) < 0){
            break;
        }
        printf("len[%d] = %ld\n",i, strlen(linebuf));
        printf("len[%d] = %d\n",i, linesize);

    }

    fclose(fp);
    exit(0);

}