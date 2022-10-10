#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef int datatype;
#define MAXSIZE 32
#define FILE_NAME "/tmp/tree"

struct student{
    char id;
};

typedef struct node_st{
    struct student data;
    struct node_st *left;
    struct node_st *right;
}linklist;

int tree_insert(linklist **tree, struct student *tmp){
    linklist *node;
    if(*tree == NULL){
        node = malloc(sizeof(**tree));
        if(node == NULL){
            exit(1);
        }
        (node)->data = *tmp;
        (node)->left = NULL;
        (node)->right = NULL;
        *tree = node;
        return 0;
    }
    if(tmp->id <= (*tree)->data.id){
        return tree_insert(&((*tree)->left), tmp);
    }
    else{
        return tree_insert(&((*tree)->right), tmp);
    }
}

linklist *__tree_load(FILE *fp){
    int c;
    linklist *tree;
    c = fgetc(fp);
    /* if c < 0..*/
    if(c != '('){
        fprintf(stderr, "read error\n");
        exit(1);
    }
    c = fgetc(fp); //SHUO MING SHI YE ZI
    if(c == ')'){
        return NULL;
    }

    tree = malloc(sizeof(*tree));
    if(tree == NULL){
        return NULL;
    }
    tree->data.id = c;
    tree->left = __tree_load(fp);
    tree->right = __tree_load(fp);
    c = fgetc(fp);
    if(c != ')'){
        return NULL;
    }
    return tree;

}
linklist *tree_load(const char *path){
    linklist *tmp;
    FILE * fp = fopen(path, "r");
    if(fp == NULL){
        printf("73error\n");
        return NULL;
    }

    tmp = __tree_load(fp);
    fclose(fp);
    return tmp;
}
void tree_draw_0(linklist *tree, int level){
    int i;
    if(tree == NULL){
        return;
    }
    tree_draw_0(tree->right, level+1);
    for(i = 0; i < level; i++){
        printf("    ");
    }
    // print_student(&tree->data);
    printf("%c\n",tree->data.id);
    tree_draw_0(tree->left, level+1);
}
void tree_draw(linklist *tree){
    tree_draw_0(tree, 0);
}
int main(){
    linklist *tree;
    tree = tree_load(FILE_NAME);
    if(tree == NULL){
        printf("error\n");
        return 1;
    }
    tree_draw(tree);
}