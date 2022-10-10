#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<fifo.h>

typedef int datatype;
#define MAXSIZE 32

struct student{
    datatype id;
    char name[MAXSIZE];
    int math;
    int chinese;   
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

struct student *tree_find(linklist *tree, int tmp_id){
    
    if(tree == NULL){
        return NULL;
    }
    if(tmp_id == tree->data.id){
        return &(tree->data);
    }
    if(tmp_id <= (tree->data.id)){
    // if((tree->data.id) <= tmp_id){
        printf("%d\n", 50);
        return tree_find((tree->left),tmp_id);
    }
    else{
        printf("%d\n", 54);
        return tree_find((tree->right),tmp_id);
    }
}

void print_student(const void *ptr){
    const struct student *p = ptr;
    printf("%d %d %d %s\n",p->id, p->math, p->chinese, p->name);
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
    printf("%d\n",tree->data.id);
    tree_draw_0(tree->left, level+1);
}
void tree_draw(linklist *tree){
    tree_draw_0(tree, 0);
}
int main(){
    int arr[] = {1, 2, 3, 7, 6, 5, 9, 8, 4};
    linklist *tree = NULL;
    int i;
    struct student tmp, *tmp1;

    for(i = 0; i < sizeof(arr)/sizeof(*arr); i++){
        tmp.id = arr[i];
        snprintf(tmp.name, MAXSIZE, "stu%d", i);
        tmp.math = random() % 100;
        tmp.chinese = random() % 100;

        tree_insert(&tree, &tmp);
    }

    // tmp1 = tree_find(tree, 2);
    // if(tmp1 == NULL){
    //     printf("error_...\n");
    // }
    // else{
    //     printf("find\n");
    //     print_student(tmp1);
    // }
    tree_draw(tree);
}