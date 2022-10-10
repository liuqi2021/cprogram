#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define FILE_NAME "./log"
#define MAXSIZE 256
#define KEYSIZE 256
#define BUFSIZE 512

typedef struct tri{
    struct tri *ch[26];
    char desc[MAXSIZE];    
}node;

int get_word(FILE *fp, char *key, char *desc){
    char buf[BUFSIZ];
    char *retp;
    int i, j;
    // while(1){
        retp = fgets(buf, BUFSIZ, fp);
        if(retp == NULL){
            return -1;
        }
    // }
    for(i = 0; i < KEYSIZE - 1 && buf[i] != ':'; i++){
        key[i] = buf[i];
    }
    key[i] = '\0';
    i++;
    for(j = 0; j < MAXSIZE-1 && buf[i] != '\0'; i++, j++){
        desc[j] = buf[i];
    }
    desc[j] = '\0';
    return 0;
}

node *new_node(){
    node *tmp;
    int i;
    tmp = malloc(sizeof(*tmp));
    if(tmp == NULL){
        return NULL;
    }
    tmp->desc[0] = '\0';
    for(i = 0; i < 26; i++){
        tmp->ch[i] = NULL;
    }
    return tmp;
}
int tree_insert(node **tree, char *key, char *desc){
    if((*tree == NULL)){
        *tree = new_node();
        // printf("%d\n",__LINE__);
        if((*tree) == NULL){
            // printf("%d\n",__LINE__);
            return -1;
        }
    }
    // printf("%d\n",__LINE__);
    if(*key == '\0'){
        // printf("%d\n",__LINE__);
        strcpy((*tree)->desc, desc);
        return 0;
    }
    // printf("%d\n",__LINE__);
    return tree_insert((*tree)->ch + *key - 'a', key+1, desc);
    // printf("%d\n",__LINE__);
}

char *tree_find(node *tree, char *key){
    if((tree == NULL)){
        printf("67");
        return NULL;
    }

    if(*key == '\0'){
        printf("72\n");
        return tree->desc;
    }
    printf("75");
    return tree_find((tree)->ch[*key - 'a'], key+1);
}
int main(){
    node *tree = NULL;
    FILE *fp;
    char *datap;
    int ret;
    char desc[MAXSIZE] = {'\0'};
    char key[KEYSIZE] = {'\0'};
    fp = fopen(FILE_NAME, "r");
    if(fp == NULL){
        fprintf(stderr, "fopen():open failed");
    }
    while(1){
        ret = get_word(fp, key, desc);
        if(ret != 0){
            break;
        }
        puts(key);
        puts(desc);
        tree_insert(&tree, key, desc);
    }

    datap = tree_find(tree, "ant");
    if(datap == NULL){
        printf("error\n");
    }
    else{
        puts(datap);
    }
    fclose(fp);
}