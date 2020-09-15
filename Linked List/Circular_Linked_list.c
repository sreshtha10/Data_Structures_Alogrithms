//Circular Linked List

#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int info;
    struct node* link;
}Node;

//Insert to empty list 
void display(Node *last){
    if(last == NULL){
        printf("List is empty");
        return;
    }
    Node *p;
    p = last->link;
    do{
        printf("%d ",p->info);
        p = p->link;
    }while(p!= last->link);
    printf("\n");
    return;
}



Node * add_to_empty(Node *last,int data){
    Node * tmp = (Node*)malloc(sizeof(Node));
    tmp->info = data;
    last = tmp;
    tmp->link = last;
    return last;
}



Node* add_to_beg(Node* last,int data){
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->info = data;
    tmp->link = last->link;
    last->link= tmp;
    return last;
}

int main(void){
    Node* last = NULL;
    last = add_to_empty(last,1);
    last = add_to_beg(last,2);
    display(last);
    return 0;
}
