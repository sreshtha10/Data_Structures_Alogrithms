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
    if (start == NULL)
    {
        printf("List is empty")
    }
    while(p->link != NULL)
    {
        printf("%d",p->info);
    }
    p = p->link;
}// end of display function

//Adding the element at the beginning of linked list 

struct node add_at_beg(struct node*start,int value)
{
    struct *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
    return start;
}//End of add_at_beg function

//search function
void search(struct node *start,int val)
{
    
}
