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

void postorder(){
    Vertex* q = root,*ptr = root;
    if(ptr == NULL){
        // tree is empty
        return;
    }
    while(1){
        while(ptr->lchild != NULL){
            push(ptr);
            ptr = ptr->lchild;
        }
        while(ptr->rchild == NULL || ptr->rchild == q){
            printf("%d ",ptr->data);
            q = ptr;
            if(stack == NULL){
                return;
            }
            ptr = pop();
        }
        push(ptr);
        ptr = ptr->rchild;
    }
    printf("\n");
    return;
}

int main(void){
    return 0;
}
