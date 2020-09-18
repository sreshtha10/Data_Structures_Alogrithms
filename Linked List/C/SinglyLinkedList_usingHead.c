// Singly Linked list using a header node:
// header node is the node whose info part stores other information and head->link points to the first node.

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *link;
}Node;


//Display Method

void display(Node* head){
    Node *p;
    if(head->link == NULL){
        printf("List is empty\n");
        return;
    }
    p = head->link;
    while(p!=NULL){
        printf("%d ",p->info);
        p = p->link;
    }
    printf("\n");
}

Node* addatend(Node* head,int data){
    Node *tmp = (Node*)malloc(sizeof(Node));
    Node *p = head;
    tmp->info = data;
    while(p->link != NULL){
        p = p->link;
    }
    p->link = tmp;
    tmp->link = NULL;
    return head;
}

Node* addbefore(Node* head,int data,int item){
    Node* p =head, *tmp =(Node*)malloc(sizeof(Node));
    while(p->link!=NULL){
        if(p->link->info == item){
            tmp->link = p->link;
            tmp->info = data;
            p->link = tmp;
            return head;
        }
        p = p->link;
    }
    printf("Element not found\n");
    return head;
}

Node* addatpos(Node* head,int data,int pos){
    Node* p = head,*tmp = (Node*)malloc(sizeof(Node));
    for(int i = 0;i<pos-1;i++){
        p = p->link;
        if(p == NULL){
            printf("Elements are less.\n");
            return head;
        }
    }
    tmp->link = p->link;
    tmp->info = data;
    p->link = tmp;
    return head;
}

Node* delete(Node* head,int data){
    Node *p,*tmp;
    if(head->link == NULL){
        printf("List is already empty\n");
        return  head;
    }
    if(head->link->info == data){
        tmp = head->link;
        head->link = tmp->link;
        free(tmp);
        return head;
    }
    p = head->link;
    while(p != NULL){
        if(p->link->info == data){
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return head;
        }
        p = p->link;
    }
    printf("Element not found\n");
    return head;
}


Node* reverse(Node* head){
    Node* p,*n,*curr;
    curr = head->link;
    p = NULL;
    while(curr != NULL){
        n = curr->link;
        curr->link = p;
        p = curr;
        curr = n;
    }
    head->link = p;
    return head;
}



int main(void){
    Node *head = (Node*)malloc(sizeof(Node));
    head->info = 0;
    head->link = NULL;
    head = addatend(head,1);
    head = addatend(head,2);
    head = addbefore(head,3,2);
    head = addatpos(head,6,2);
    head = reverse(head);
    display(head);
    
    return 0;
}
