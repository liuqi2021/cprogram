#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv){
    if(argc < 2){
        fprintf(stderr, "usage:./flen argv[0]\n");
        exit(1);
    }

    FILE *fp;
    fp = fopen(argv[1], "r");
    if(fp == NULL){
        perror("fopen():");
    }

    
    fseek(fp, 0, SEEK_END);
    fprintf(stdout,"len = %ld\n", ftell(fp));
    rewind(fp);
    fprintf(stdout,"len = %ld\n", ftell(fp));
    fclose(fp);
}