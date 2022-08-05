#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(int i){
    int result;
    if( i <= 0 ){
        result = 1;
        return result;
    }
    while(i > 0){
        result = i * factorial(i-1);
        return result;\
    }
}
int main(){
    int i = 10;
    int result;
    result = factorial(4);
    printf("result = %d\n", result);
    exit(0);
}