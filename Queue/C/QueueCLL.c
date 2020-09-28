// Queue using circular linked list 
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}Node;

Node* rear = NULL;

void display(){
    Node*p;
    if(rear == NULL){
        printf("Queue Undeflow\n");
        return;
    }
    p = rear->next;
    do{
        printf("%d ",p->data);
        p = p->next;
    }while(p !=rear->next );
    printf("\n");
    return;
}

void insert(int x){
    Node* tmp = (Node*)malloc(sizeof(Node));
    if(tmp == NULL){
        printf("Queue Overflow\n");
        return;
    }
    tmp->data = x;
    if(rear != NULL){
        tmp->next = rear->next;
        rear->next = tmp;
        rear = tmp;
    }
    else{
        rear = tmp;
        rear->next = tmp;
    }
    
    return;
}

int delete(){
    if(rear == NULL){
        printf("Queue Undeflow\n");
        exit(1);
    }
    Node * tmp = rear->next;
    rear->next = tmp->next;
    int x = tmp->data;
    free(tmp);
    return x;
}

int peek(){
    if(rear == NULL){
        printf("Queue Undeflow\n");
        exit(1);
    }
    return rear->next->data;
}

int main(void){
    insert(1);
    insert(2);
    insert(3);
    display();
    delete();
    display();
}

