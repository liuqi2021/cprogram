#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 3
#define N 4
float average_score(int *p, int n);
void print_score(int (*p)[N], int num);

int main(int argc, char *argv[]){
    int array1[M][N] = {200,2,3,4,5,6,7,8,9,10,11,100};
    int i, j;
    // for(int i = 0; i < M; i++){
    //     for(int j = 0; j < N; j++){
    //         printf("%4d", array1[i][j]);
    //     }
    //     printf("\n");
    // }
    int average;
    average = average_score(array1[0], M*N);
    printf("average = %d\n", average);

    print_score(array1, 2);
    exit(0);

}

void print_score(int (*p)[N], int num){
    int i;
    for(i = 0; i < N; i++){
        printf("%4d", *(*(p+num)+i));
    }
    printf("\n");
}

float average_score(int *p, int n){
    int i;
    float aver;
    int sum = 0;
    for(i = 0; i < n; i++){
        sum = sum + p[i];
    }
    aver = sum/n;
    return aver;
}
