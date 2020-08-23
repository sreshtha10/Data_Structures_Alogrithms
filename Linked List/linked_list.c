//linked list
#include<stdio.h>
#include<stdlib.h>

//Node 
struct node {
    int info;
    struct node *link;
};

//Display or Print the linked list

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
        printf("%d",p->info);
        //After accessing the first element, we use link part of the structure to access the next element.
        p = p->link;
    }
    
}// end of display function

//Adding the element at the beginning of linked list 

struct node *add_at_beg(struct node*start,int value)
{
    //If we want to add a node at the beginning of linked list then we have start should point at this node and this node should point at the next node.
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = value;
    tmp->link = start;
    start = tmp;
    return start;
}//End of add_at_beg function

//search function
void search(struct node *start,int val)
{
    struct node *p;
    p = start;
    int pos =1;
    while(p->link != NULL){
        if(p->info == val)
        {
            printf("Element found at index %d",pos);
            return;
        }
        pos++;
        p = p->link;
    }
    printf("Element not found in the linked list");
}//End of search function.


//function to add element at the end of linked list
struct node *add_at_end(struct node *start, int data)// To add an element at the end of the linked list first we need to find the last element and then point the last element to the new node and new node to null.
{
    struct node *tmp;
    struct node *p;
    p = start;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    while(p->link != NULL)
    {
        p = p->link;
    }
    tmp->link = NULL;
    p->link = tmp;
    return start;
    
}// end of the function



int main()
{
    struct node *start = NULL;
    return 0;
}
