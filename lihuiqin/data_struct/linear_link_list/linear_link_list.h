#ifndef _LINEAR_LINK_LIST_H_
#define _LINEAR_LINK_LIST_H_

#define DATASIZE 1024
typedef int datatype;

typedef struct{
    datatype data[DATASIZE];
    int count;
}sqlite;

sqlite * sqlite_create();
void sqlite_create1(sqlite **);
void sqlite_show(sqlite *p);

int sqlite_insert(sqlite *, int i, datatype *);
int sqlite_delete(sqlite *, int i);
int sqlite_getcount(sqlite *);
int sqlite_find(sqlite *, int );
int sqlite_isempty(sqlite *p);
int sqlite_setempty(sqlite *p);
void sqlite_destory(sqlite **);
void sqlite_merge(sqlite *list1, sqlite *list2);
#endif