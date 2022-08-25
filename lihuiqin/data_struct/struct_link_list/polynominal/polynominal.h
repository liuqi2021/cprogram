
#ifndef __POLYNOMINAL_H_
#define __POLYNOMINAL_H_

typedef struct node_st{
    int coe;
    int exp;
    struct node_st *next;
}linklist;

linklist *  poly_create(int a[][2], int cnt);

int poly_merge(linklist *p1, linklist *p2);
void poly_show(linklist *p);


#endif