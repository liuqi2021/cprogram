#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <file.h>
#include <linux/module.h>
// #include <linux/moduleparam.h>
// #include <linux/init.h>

#define FILE_PATH "/tmp/out"
#define BUFSIZE 1024
int main(int argc, char *argv[]){
    char *source_path, *dest_path;
    printf("argc = %d\n",argc);
    int ch;
    char buf[BUFSIZE];
    if(argc != 3){
        fprintf(stderr, "source_path, dest_path needed\n");
        exit(1);
    }
    source_path = argv[1];
    dest_path = argv[2];
    FILE *fp1, *fp2;
    fp1 = fopen(source_path, "r");
    if(fp1 == NULL){
        perror("fopen():");
        exit(1);
    }
    fp2 = fopen(dest_path, "w+");
    if(fp2 == NULL){
        fclose(fp1);
        perror("fopen():\n");
        exit(1);
    }

    while(fgets(buf, BUFSIZE, fp1) != NULL){
        fputs(buf, fp2);

    }

    fclose(fp2);
    fclose(fp1);
    
    exit(0);


    
}