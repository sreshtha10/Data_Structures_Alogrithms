#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *lchild;
    int deta;
    struct node *rchild;
    int balance;
}Node;


Node* rotateRight(Node* pptr){
    Node* aptr = pptr->lchild;
    pptr->lchild = aptr->rchild;
    aptr->rchild = pptr;
    return aptr;
}

Node* rotateLeft(Node* pptr){
    Node* aptr = pptr->rchild;
    pptr->rchild = aptr->lchild;
    aptr->lchild = pptr;
    return aptr;
}


int main(void){
    return 0;
}
