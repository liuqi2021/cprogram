#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(){
    FILE *fp = NULL;
    long int count = 0;
    
    while(1){
        fp = fopen("./tmp", "w");
        if(fp ==NULL){
            fprintf(stderr,"fopen:%d\n", errno);
            perror("fopen:");
            puts(strerror(errno));
            break;
        }
        count++;
        printf("count=%ld\n", count);
    }
    printf("count=%ld\n", count);

    // fclose(fp);
}