#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * add(int a, int b, int *p){
	int sum;
	sum = (a + b);
	p = &sum;
	return p;

}

int  minor(int a, int b, int *p){
	int minor;
	minor = (a - b);
	p = &minor;
	return minor;
}


int main(){
	int a = 100;
	int b = 45;
	int *q;
	int *(*p)(int,int, int *);
	int (*r)(int, int, int *);
	r = minor;
	p = add;
	q = p(a, b, q);
	printf("%d \n", *q);
	*q = r(a, b, q);
	printf("%d\n",*q);
	exit(0);	
}
