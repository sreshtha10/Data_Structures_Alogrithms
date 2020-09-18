/* Sorting Linked List can be done in two ways:
        1. By exchanging the data.
        2. By exchanging the links.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *link;
}Node;

void display(struct node *start)
{
    struct node *p;
    p = start;
    //If the start pointer points to nothing then list is empty.
    if (start == NULL)
    {
        printf("List is empty");
        return;
    }
    while(p != NULL)
    {
        printf("%d ",p->info);
        //After accessing the first element, we use link part of the structure to access the next element.
        p = p->link;
    }
    printf("\n");
    
}// end of display function

struct node *insert(struct node* start ,int data){
    struct node *p,*tmp;
    tmp =(struct node*)malloc(sizeof(struct node));
    // Adding the node to the beginning of the linked list
    if(start == NULL){
        tmp->info = data;
        tmp->link = start;
        start = tmp;
        return start;
    }
    p = start;
    while(p->link!=NULL){
        p = p->link;
    }
    tmp->info = data;
    tmp->link = p->link;
    p->link= tmp;
    return start;
}    


Node *concatinate(Node *start1,Node* start2,Node* start3){
    Node *p1,*p2;
    p1 = start1,p2 = start2;
    while(p1 != NULL){
        start3 = insert(start3,p1->info);
        p1 = p1->link;
    }
    while(p2 != NULL){
        start3 = insert(start3,p2->info);
        p2 = p2->link;
    }
    return start3;
}


int main(void){
    Node* start1 = NULL;
    Node * start2 = NULL;
    Node * start3 = NULL;
    start1 = insert(start1,2);
    start2 = insert(start2,1);
    start2 = insert(start2,5);
    start2 = insert(start2,6);
    start1 = insert(start1,1);
    start1 = insert(start1,4);
    start1 = insert(start1,7);
    display(start1);
    display(start2);
    start3 = concatinate(start1,start2,start3);
    display(start3);
    return 0;
}
        
