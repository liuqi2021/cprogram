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

typedef struct node_struct{
    struct student data;
    struct node_struct *left;
    struct node_struct *right;
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
        return tree_find((tree->left),tmp_id);
    }
    else{
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
    printf("--");
    // print_student(&tree->data);
    printf("%d|\n",tree->data.id);
    tree_draw_0(tree->left, level+1);
}
void tree_draw(linklist *tree){
    tree_draw_0(tree, 0);
}

static int get_level(linklist *tree){
    if(tree == NULL){
        return 0;
    }
    return get_level(tree->left) + 1 + get_level(tree->right);
}

static linklist * find_left(linklist *root){
    if(root->left == NULL){
        return root;
    }
    return find_left(root->left);
}

static linklist * find_right(linklist *root){
    if(root->right == NULL){
        return root;
    }
    return find_right(root->right);
}

static void turn_left(linklist **tree){
    linklist *cur = *tree;
    *tree = cur->right;
    cur->right = NULL;
    find_left(*tree)->left = cur;
}

static void turn_right(linklist **tree){
    linklist *cur = *tree;
    *tree = cur->left;
    cur->left = NULL;
    find_right(*tree)->right = cur;
}

void tree_balance(linklist **tree){
    int sub;

    if(*tree == NULL){
        return;
    }

    while(1){
        sub = get_level((*tree)->left) - get_level((*tree)->right);
        if(sub >= -1 && sub <= 1){
            break;
        }
        if(sub < -1){
            turn_left(tree);
        }
        else{
            turn_right(tree);
        }
    }
    tree_balance(&(*tree)->left);
    tree_balance(&(*tree)->right);

}

void tree_delete(linklist **tree, int id){
    linklist ** node = tree;
    linklist * cur;
    while(*node != NULL && (*node)->data.id != id){
        if(id < (*node)->data.id){
            node = &(*node)->left;
        }
        else{
            node = &(*node)->right;
        }
    }
    if(*node == NULL){
        return;
    }
    cur = *node;
    if(cur->left == NULL){
        *node = cur->right;
    }
    else{
        *node = cur->left;
        find_right(cur->left)->right = cur->right;
    }
    free(cur);
}

#if 0
void tree_travel(linklist *tree){ // root->left->right
    if(tree == NULL){
        return;
    }
    print_student(&tree->data);
    tree_travel(tree->left);
    tree_travel(tree->right);

}
#else
void tree_travel(linklist *tree){ // level
    queue *qu;
    linklist *cur;
    int ret;
    qu = fifo_create(sizeof(*tree));
    if(qu == NULL){
        exit(1);
    }
    // fifo_enqueue(qu, tree);
    fifo_enqueue(qu, tree);
    while(1){
        ret = fifo_dequeue(qu, cur);
        if(ret == -1){
            break;
        }
        if(cur->left != NULL){
            fifo_enqueue(qu, &cur->left);
        }
        if(cur->right != NULL){
            fifo_enqueue(qu, &cur->right);
        }
    }

    fifo_destroy(qu);
}
#endif
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

    tree_draw(tree);
    
    tree_balance(&tree);
    tree_draw(tree);
    // tree_delete(&tree, 5);
    // tree_draw(tree);
    tree_travel(tree);
}