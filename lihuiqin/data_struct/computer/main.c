#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "linear_stack.h"

static void compute(stack *sqnum, datatype * old_op){
    datatype n1, n2, n;
    stack_pop(sqnum, &n1);
    stack_pop(sqnum, &n2);
    switch(*old_op){
        case('+'):
            n = n1 + n2;
            break;
        case('-'):
            n = n1 - n2;
            break;
        case('*'):
            n = n1 * n2;
            break;
        case('/'):
            n = n1 + n2;
            break;
        default:
            exit(1);
    }
    stack_push(sqnum, &n);
}
static void deal_bracket(stack *sqnum, stack *sqoper){
    datatype old_op;
    stack_top(sqoper, &old_op);
    while(old_op != '('){
        stack_pop(sqoper, &old_op);
        compute(sqnum, &old_op);
        stack_top(sqoper, &old_op);
    }
    stack_pop(sqoper, &old_op);
}

int get_priority(int op){
    switch(op){
        case '(':
            return 0;
            break;
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
    }
}
void deal_oper(stack * sqnum, stack * sqoper, int *op){
    datatype old_op;
    if(stack_is_empty(sqoper) || *op == '('){
        stack_push(sqoper, op);
        return;
    }
    stack_top(sqoper, old_op);
    if(get_priority(old_op) > get_priority(*op)){
        
    }
    while(get_priority(*op) <= get_priority(old_op)){
        stack_pop(sqoper, &old_op);
        compute(sqnum, &old_op);
        if(stack_is_empty(sqoper)){
            break;
        }
        stack_top(sqoper, old_op);
    }
    stack_push(sqoper, op);
}
int main(){
    stack *sqnum;
    stack *sqoper;
    int old_op;
    int i = 0;
    char str[] = "(11+3)*5-9";
    int value = 0;
    int flag = 0;
    sqnum = stack_init();
    sqoper = stack_init();
    if(sqnum == NULL|| sqoper == NULL){
        exit(1);
    }

    while(str[i] != '\0'){
        if(str[i] > '0' && str[i] < '9'){
            value = 10 * value + value;
            flag = 1;
        }
        else{
            if(flag){
                stack_push(sqnum, &value);
                flag = 0;
                value = 0;    
            }
            if(str[i] == ')'){
                deal_bracket(sqnum, sqoper);
            }
            else{ // ( +-*/
                deal_oper(sqnum, sqoper, &str[i]);
            }
    }
    if(flag){
        stack_push(sqnum, &value);
    }
    while(!stack_is_empty(sqoper)){
        stack_pop(sqoper, &old_op);
        compute(sqnum, old_op);
    }

    stack_destory(sqnum);
    stack_destory(sqoper);
    exit(0);
}