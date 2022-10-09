#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(){
    FILE *fp;
    fp = fopen("./tmp", "w");
    if(fp ==NULL){
        fprintf(stderr,"fopen:%d\n", errno);
        perror("fopen:");
        puts(strerror(errno));
    }
    fclose(fp);
}