// Linked list implementation of queue
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}Node;

Node *front = NULL;
Node *rear = NULL;

void insert(int x){
    Node* tmp = (Node*)malloc(sizeof(Node));
    if(tmp == NULL){
        printf("Queue Overflow\n");
        return;
    }
    tmp->data = x;
    if(front == NULL){
        front = tmp;
    }
    else{
        rear->next = tmp;
    }
    rear = tmp;
    tmp->next = NULL;
    return;
}


int delete(){
    if(front == NULL){
        printf("Queue Underflow\n");
        return;
    }
    int x = front->data;
    Node * tmp = front;
    front  = front->next;
    free(tmp);
    return x;
}


int peek(){
    if(front == NULL){
        printf("Queue Underflow\n");
        exit(1);
    }
    return front->data;
}



void display(){
    Node* p = front;
    if(front == NULL){
        printf("Queue Underflow\n");
        return;
    }
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

int main(void){
    insert(1);
    insert(2);
    insert(3);
    peek();
    delete();
    display();
    return 0;
}
