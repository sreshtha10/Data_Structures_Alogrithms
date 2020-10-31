#include<stdio.h>
#include<stdlib.h>

typedef struct vertex{
    struct vertex* lchild;
    int data;
    struct vertex* rchild;
}Vertex;

typedef struct node{
    struct vertex* data;
    struct node* next;
}Node;

Vertex* root = NULL;
Node* front = NULL;
Node* rear = NULL;


void insert(Vertex* v){
    Node* tmp = (Node*)malloc(sizeof(Node));
    if(tmp == NULL){
        // queue overflow 
        return;
    }
    tmp->data = v;
    if(front != NULL){
        rear->next = tmp;
        rear = tmp;
    }
    else{
        rear = tmp;
        tmp->next= NULL;
        front = tmp;
    }
    return;
}

Vertex* delete(){
    if(front == NULL){
        // queue underflow
        exit(1);
    }
    Vertex* v = front->data;
    Node* tmp = front;
    front = front->next;
    free(tmp);
    return v;
}

void levelorder(){
    Vertex* ptr = root;
    if(ptr == NULL){
        // empty tree
        return;
    }
    insert(ptr);
    while(front != NULL){
        ptr = delete();
        printf("%d ",ptr->data);
        if(ptr->lchild != NULL){
            insert(ptr->lchild);
        }
        if(ptr->rchild != NULL){
            insert(ptr->rchild);
        }
    }
    printf("\n");
    return;
}
int main(void){
    return 0;
}
