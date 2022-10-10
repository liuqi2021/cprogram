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

// void print_student(const void *ptr){
//     const struct student *p = ptr;
//     printf("%d %d %d %s\n",p->id, p->math, p->chinese, p->name);
// }

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

int __tree_save(linklist *tree, FILE *fp){
    fputc('(', fp);
    if(tree == NULL){
        fputc(')', fp);
        return 0;
    }
    fputc(tree->data.id,fp);
    __tree_save(tree->left,fp);
    __tree_save(tree->right,fp);
    fputc(')',fp);
    return 0;
}

void tree_draw(linklist *tree){
    tree_draw_0(tree, 0);
}

void tree_save(linklist *tree, const char *path){
    FILE *fp = fopen(path, "w");
    if(fp == NULL){
        return;
    }
    __tree_save(tree, fp);
    fclose(fp);
    return;
}
int main(){
    char arr[] = "cefadjbh";
    linklist *tree = NULL;
    int i;
    struct student tmp, *tmp1;

    for(i = 0; i < sizeof(arr)-1; i++){
        tmp.id = arr[i];

        tree_insert(&tree, &tmp);
    }
    tree_draw(tree);

    tree_save(tree, FILE_NAME);
}