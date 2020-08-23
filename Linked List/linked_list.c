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
        printf("List is empty");
        return;
    }
    while(p != NULL)
    {
        printf("%d",p->info);
        p = p->link;
    }
    
}// end of display function

//Adding the element at the beginning of linked list 

struct node *add_at_beg(struct node*start,int value)
{
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

struct node *add_at_end(struct node *start, int data)
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
    
}

int main()
{
    struct node *start = NULL;
    return 0;
}
