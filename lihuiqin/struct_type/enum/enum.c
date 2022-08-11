#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{
    MON,
    TUE,
    WED,
    THR,
    FRI,
    SAT,
    SUN
};


struct job{
    int id;
    int state;
    char name[128];
}job_state;

int main(){

    job_state.state = MON;
    printf("%d\n",job_state.state);

    switch(job_state.state){
        case MON:
            printf("MON\n");
            break;
        case TUE:
            printf("TUE\n");
            break;
        case WED:
            printf("WED\n");
            break;
        case THR:
            printf("THR\n");
            break;
        default:
            exit(1);
    }
    exit(0);


}