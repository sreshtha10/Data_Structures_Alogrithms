// Singly Linked List - Data Structures


/* List of functions created:
    1. Display - To print the Singly Linked List.
    2. add_at_beg - To insert element at the beginning of the list.
    3. search - To search an element in the list.
    4. add_at_end - To insert an element at the end of the list.
    5. add_after - To insert an element after a particular node.
    6. add_before - To insert an element before a particular node.
    
    
*/

#include<stdio.h>
#include<stdlib.h> //I used dynamic memory allocation.


//Node - An element of a linked list which contain two parts: 1. Data 2. Link to the next node.
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
        printf("%d ",p->info);
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



//Insertion after a specified node.
struct node* add_after(struct node *start,int node_data,int data){
    struct node *tmp, *p;
    p = start;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    while(p != NULL){
        if(p->info == node_data){
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        p = p->link;
    }
    printf("Element not found !!\n");
    return start;
} // End of the function.



//Insertion before a node
struct node * add_before(struct node *start,int node_data,int data){
    struct node * tmp,*p;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    p = start;
    while(p != NULL){
        if(p->link->info == node_data){
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        p = p->link;
    }
    printf("Element not found !! \n");
    return start;
}// End of function.



//Insertion at a given position.


int main()
{
    struct node *start = NULL;
    start = add_at_beg(start,1);
    start = add_at_end(start,2);
    start = add_at_end(start,3);
    display(start);
    printf("\n");
    start = add_after(start,2,4);
    display(start);
    start = add_before(start,2,10);
    printf("\n");
    display(start);
    
    return 0;
}
