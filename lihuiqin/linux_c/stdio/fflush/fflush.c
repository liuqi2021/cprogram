#include<stdio.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv){
    // if(argc < 2){
    //     fprintf(stderr,"usage: ./fflush argv[1]\n");
    // }

    fprintf(stdout, "Before while");
    fflush(stdout);
    while(1);
    fprintf(stdout, "After while");
}
