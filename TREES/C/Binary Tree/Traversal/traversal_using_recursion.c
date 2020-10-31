#include<stdio.h>

//Traversal in a binary tree - Recursive

// 1. Preorder VLR


struct node{
    struct node *lchild;
    int info;
    struct node *rchild;
}Node;


void preorder(Node *ptr){
    if(ptr == NULL){
        return;
    }          // base case
    printf("%d",ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

// Inorder LVR

void inorder(Node* ptr){
    if(ptr == NULL){
        return;
    }
    inorder(ptr->lchild);
    printf("%d",ptr->info);
    inorder(ptr->rchild);
}

// Postorder LRV

void postorder(Node* ptr){
    if(ptr == NULL){
        return;
    }
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d",ptr->info);
}
