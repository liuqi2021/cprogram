#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<unistd.h>

#include "fifo.h"

int main(){
    datatype array[] = {1, 2, 3, 4, 5, 6};
    int i;
    queue *head = NULL;
    head = fifo_create();
    if(head == NULL){
        exit(1);
    }
    for(i = 0; i < sizeof(array)/sizeof(*array); i++){
        printf("%d\n",__LINE__);
        fifo_enqueue(head, &array[i]);
    }

    fifo_display(head);
    fifo_destroy(head);
    exit(0);


}