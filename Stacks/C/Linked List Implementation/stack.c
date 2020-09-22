// Linked List implementation

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;
Node * top = NULL;

void display(){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    Node *p = top;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

void push(int x){
    Node * tmp  = (Node*)malloc(sizeof(Node));
    if(tmp == NULL){
        printf("Stack Overflow\n");
        return;
    }
    tmp->data = x;
    tmp->next = top;
    top = tmp;
    return;
}

int pop(){
    int x;
    if(top == NULL){
        printf("Stack Underflow\n");
        return;
    }
    Node * tmp;
    tmp = top;
    x = top->data;
    top = top->next;
    free(tmp);
    return x;
}



int main(void){
    display();
    push(1);
    push(2);
    display();
    printf("%d\n",pop());
    display();
    return 0;
}
