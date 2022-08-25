#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "polynominal.h"

int main(){
    int a[][2] = {{5,0},{2,1},{8,8},{3,16}};
    int b[][2] = {{1,1},{16,3},{-8,8}};
    linklist *list1 = NULL;
    linklist *list2 = NULL;


    list1 = poly_create(a, 4);
    list2 = poly_create(b, 3);
    poly_show(list1);
    // poly_show(list2);

    poly_merge(list1, list2);
    poly_show(list1);




    exit(0);
}