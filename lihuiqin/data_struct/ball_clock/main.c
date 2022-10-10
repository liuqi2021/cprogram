#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#include "linear_stack.h"
#include "fifo.h"

static int fifo_check(queue *qu){
    int i = (qu->head+1) % MAXSIZE;
    while(i != qu->tail){
        if(qu->data[i] > qu->data[(i+1)%MAXSIZE]){
            return 0;
        }
        i = (i+1)%MAXSIZE;
    }
    return 1;

}
int main(){
    int BALL = 26;
    int i, container, value, time = 0;
    queue *qu = NULL;
    stack *stack_hour = NULL;
    stack *stack_5min = NULL;
    stack *stack_1min = NULL;
    fifo_create(qu);
    stack_init(stack_hour);
    stack_init(stack_1min);
    stack_init(stack_5min);
    if(qu == NULL || stack_hour == NULL || stack_5min == NULL || stack_1min == NULL){
        exit(1);
    }

    for(i = 1; i <= BALL; i++){
        fifo_enqueue(qu, &i);
    }

    fifo_display(qu);
    while(1){
        fifo_dequeue(qu, &container);
        time++;

        if(stack_1min->top != 3){
            stack_push(stack_1min,&container);
        }
        else{
            while(!stack_is_empty(stack_1min)){
                stack_pop(stack_1min,&value);
                fifo_enqueue(qu,&value);
            }
            if(stack_5min->top != 12){
                stack_push(stack_5min,&container);
            }
            else{
                while(!stack_is_empty(stack_5min)){
                    stack_pop(stack_5min,&value);
                    fifo_enqueue(qu,&value);
                }
                if(stack_hour->top != 12){
                    stack_push(stack_hour,&container);
                }
                else{
                    while(!stack_is_empty(stack_hour)){
                        stack_pop(stack_hour,&value);
                        fifo_enqueue(qu,&value);
                    }
                    fifo_enqueue(qu,&container);
                    if(fifo_check(qu)){
                        break;
                    }
                }
            }
        }
    }

    printf("time=%d\n", time);





    fifo_destroy(qu);
    stack_destory(stack_hour);
    stack_destory(stack_5min);
    stack_destory(stack_1min);
}