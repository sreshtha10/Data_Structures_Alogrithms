//Doubly Linked List
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    struct node *prev;
    int info;
    struct node *next;
}Node;


//Printing the list 
void printList(Node* start){
    Node *p;
    p = start;
    if(start == NULL){
        printf("List is empty\n");
        return;
    }
    while(p!=NULL){
        printf("%d ",p->info);
        p = p->next;
    }
    printf("\n");
    return;
}



//Insert in the empty list 

Node *add_to_empty(Node* start,int data){
    Node * tmp = (Node*)malloc(sizeof(Node));
    tmp->info = data;
    tmp->next = NULL;
    tmp->prev = NULL;
    start = tmp;
    return start;
}

//Insert at beg of the list
Node * add_at_beg(Node *start,int data){
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->info = data;
    tmp->next = start;
    tmp->prev = NULL;
    start->prev = tmp;
    start = tmp;
    return start;
}


//Insert at end

Node* add_at_end(Node* start,int data){
    Node* tmp,*p;
    tmp =(Node*)malloc(sizeof(Node));
    tmp->info = data;
    p = start;
    while(p->next != NULL){
        p = p->next;
    }
    tmp->next = p->next;
    tmp->prev = p;
    p->next = tmp;
    return start;
}

//Insert after the Node

Node* add_after(Node* start,int data,int q){
    Node* tmp,*p;
    p = start;
    tmp =(Node*)malloc(sizeof(Node));
    tmp->info =data;
    while(p !=NULL){
        if(p->info == q){
            tmp->next = p->next;
            tmp->prev = p;
            if(p->next != NULL){
                p->next->prev = tmp;
            }
            p->next = tmp;
            return start;
        }
        p = p->next;
    }
    printf("Element not found\n");
    return start;
}


int main(){
    Node *start = NULL;
    start = add_to_empty(start,1);
    start = add_at_end(start,2);
    start = add_at_end(start,3);
    start = add_after(start,6,2);
    printList(start);
    return 0;
}
