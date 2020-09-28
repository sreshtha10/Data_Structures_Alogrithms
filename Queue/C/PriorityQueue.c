// Priority Queue 

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int priority;
    int data;
    struct node *next;
}Node;

Node * front = NULL;

void display(){
    if(front == NULL){
        printf("Queue Underflow\n");
        return;
    }
    Node*p = front;
    while(p!=NULL){
        printf("Queue: %d\tPriority: %d\n ",p->data,p->priority);
        p = p->next;
    }
    printf("\n");
    return;
}

void insert(int x,int pr){
    Node *p,*tmp= (Node*)malloc(sizeof(Node));
    if(tmp == NULL){
        printf("Memory not available\n");
        return;
    }
    tmp->data = x;
    tmp->priority = pr;
    if(front == NULL || pr<front->priority){  
        tmp->next = front;
        front = tmp;
        return;
    }
    else {
        p = front;
        while(p->next != NULL && p->next->priority <= pr)
                p = p->next;       
        tmp->next = p->next;
        p->next = tmp;
    }
    return;
}

int delete(){
    if(front == NULL){
        printf("Queue Underflow\n");
        exit(1);
    }
    Node *tmp = front;
    int x = front->data;
    front = front->next;
    free(tmp);
    return x;
}


int main(void){
    insert(1,1);
    insert(2,0);
    insert(3,3);
    insert(4,2);
    delete();
    display();
}


