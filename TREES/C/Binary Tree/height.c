#include<stdio.h>
#include<stdlib.h>

typedef struct treenode{
    int data;
    struct treenode *lchild;
    struct treenode *rchild;
}Treenode;

int height(Treenode *root){
    if(root == NULL){
        return 0;
    }
    hleft= height(root->lchild);
    hright = height(root->rchild);
    if(hleft > hright){
        return 1+hleft;
    }
    else{
        return 1+hright;
    }
}
