//Doubly Linked List

/*Functions used:
    1. Display - To print the Doubly Linked List.
    2. add_to_empty - To insert an element in an empty List.
    3. add_at_beg - To insert element at the beginning of the list.
    4. add_at_end - To insert an element at the end of the list.
    5. add_after - To insert an element after a particular node.
    6. add_before - To insert an element before a particular node.
    8. reverseList - To reverse the list.
    9. printReverse - To print the list in reverse.
    */
    
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
//Printing the list in reverse order.

void printReverse(Node* start){
    Node*p;
    p = start;
    while(p->next != NULL){
        p = p->next;
    }
    while(p != NULL){
        printf("%d ",p->info);
        p = p->prev;
    }
    printf("\n");
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

//Insert before a Node

Node* add_before(Node* start,int data,int item){
    Node* p,*tmp;
    tmp = (Node*)malloc(sizeof(Node));
    tmp->info = data;
    if(start == NULL){
        printf("List is empty\n");
        return start;
    }
    p = start;
    if(start->info == item){
        tmp->next = start;
        tmp->prev = NULL;
        start->prev = tmp;
        start = tmp;
        return start;
    }
    while(p!=NULL){
        if(p->info == item){
            tmp->next = p;
            tmp->prev = p->prev;
            p->prev->next = tmp;
            p->prev = tmp;
            return start;
        }
        p = p->next;
    }
    printf("Element not found\n");
    return start;
    
}

//Deletion of a node.
Node* delete(Node* start,int data){
    Node*tmp;
    //Case 1 when list is empty
    if(start == NULL){
        printf("List is already empty\n");
        return start;
    }
    //Case 2 Deletion of the only node
    if(start->next == NULL){
        if(start->info == data){
            tmp = start;
            start = NULL;
            free(tmp);
            return start;
        }
        else{
            printf("Element not found\n");
            return start;
        }
    }
    //Case 3 Deletion of the first Node
    if(start->info == data){
        tmp = start;
        start = start->next;
        free(tmp);
        return start;
    }
    //Case 4 Deletion of any node in the middle
    tmp = start->next;
    while(tmp->next!=NULL){
        if(tmp->info == data){
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
            free(tmp);
            return start;
        }
        tmp = tmp->next;
    }
    //Case 5 Deletion of the last Node
    if(tmp->next == NULL && tmp->info == data){
        tmp->prev->next = NULL;
        free(tmp);
        return start;
    }
    printf("Element not found !\n");
    return start;
    
}

//Reversing the linked list 

Node* reverseList(Node* start){
    Node* p,*n,*current;
    current = start;
    p = NULL;
    while(current != NULL){
        n = current->next;
        current->next = p;
        current->prev = n;
        p = current;
        current = n;
    }
    start = p;
    return start;
}

int main(){
    Node *start = NULL;
    start = add_to_empty(start,1);
    start = add_at_end(start,2);
    start = add_at_end(start,3);
    start = reverseList(start);
    printList(start);
    printReverse(start);
    
    return 0;
}
