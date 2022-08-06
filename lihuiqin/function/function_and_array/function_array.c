#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invert_array(int *, int);

int main(){
if(0){
    int a[4] = {1,2,3,4};
    int b[2][3] = {{1,2,3},{4,5,6}};
    int (*q)[3] = b;
    int *p = a;
    int i = 0;
    for(i = 0; i < (sizeof(a)/sizeof(a[0])); i++ ){
        printf("a[%d] = %d\n", i, p[i]);
    }
    printf("b[1][1] = %d\n", q[1][1]);
    printf("b[1][1] = %d\n", *(*(q+1)+1));
    exit(0);
}

    int a[5] = {5, 7, 3, 8, 2};
    
    for(int i = 0; i < sizeof(a)/sizeof(*a); i++){
        printf("a[%d]= %d\n", i, a[i]);
    }

    invert_array(a, sizeof(a)/sizeof(*a));
    
    for(int i = 0; i < sizeof(a)/sizeof(*a); i++){
        printf("a[%d]= %d\n", i, a[i]);
    }
    exit(0);
}

void invert_array(int *p, int n){
    int i, temp;
    for(i = 0; i < n/2; i++){
        temp = p[i];
        p[i] = p[n-1-i];
        p[n-1-i] = temp;
    }
}