#include<stdio.h>
#include<stdlib.h>

typedef struct vertex{
    struct vertex* lchild;
    int data;
    struct vertex *rchild;
}Vertex;

typedef struct node{
    struct vertex* data;
    struct node* next;
}Node;

Node* stack = NULL;
Vertex* root = NULL;

void push(Vertex* v){
    Node* tmp = (Node*)malloc(sizeof(Node));
    if(tmp == NULL){
        //overflow
        return;
    }
    tmp->next = stack;
    stack = tmp;
    return;
}

Vertex* pop(){
    if(stack == NULL){
        //underflow
        exit(1);
    }
    Node* tmp = stack;
    Vertex* v = stack->data;
    stack = stack->next;
    free(tmp);
    return v;
}


void preorderTraversal(){
    if(root == NULL){
        // tree is empty
        return;
    }
    Vertex *v;
    push(root);
    while(stack != NULL){
        v = pop();
        printf("%d ",v->data);
        if(v->rchild != NULL){
            push(v->rchild);
        }
        if(v->lchild != NULL){
            push(v->lchild);
        }
    }
    printf("\n");
    return;
}

int main(void){
    return 0;
}
