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




//Selection Sort by exchanging data
Node* selectionSort_data(Node* start){
    Node* a,*b;
    int tmp;
    for(a = start;a->link->link != NULL ;a = a->link){
        for(b = a->link;b->link!=NULL;b = b->link){
            if(a->info > b->info){
                tmp = a->info;
                a->info = b->info;
                b->info =tmp;
            }
        }
    }
    return start;
}



Node* bubbleSort_data(Node* start){
    int tmp;
    Node* p,*q,*end;
    for(end = NULL;end != start->link;end =q){
            for(p = start;p->link != end;p = p->link){
                q = p->link;
                if(p->info > q->info){
                    tmp = p->info;
                    p->info = q->info;
                    q->info = tmp;
                }
            
            }
        }
    return start;
}


//Selection Sort using rearranging the links

Node* selectionSort_link(Node* start){
    Node *p,*q,*r,*s,*tmp;
    for(r = p = start;p->link!= NULL;r=p,p=p->link){
        for(s = q = p->link;q!=NULL;s=q,q = q->link){
            if(p->info > q->info){
                tmp = p->link;
                p->link = q->link;
                q->link = tmp;
                s->link= p;
                if(p != start){
                    r->link= q;
                }
                if(p == start){
                    start = q;
                }
                tmp = p;
                p = q;
                q = tmp;
            }
        }
    }
    return start;
}




int main(void){
    Node* start = NULL;
    start = add_at_beg(start,10);
    start = add_at_end(start,1);
    start = add_at_end(start,0);
    start = add_at_end(start,11);
    bubbleSort_data(start);
    display(start);
    return 0;
}
        
