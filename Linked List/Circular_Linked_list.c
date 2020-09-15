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


Node* add_at_end(Node* last,int data){
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->info = data;
    tmp->link = last->link;
    last->link = tmp;
    last = tmp;
    return last;
}


Node* add_after(Node * last,int data,int item){
    Node * p,*tmp = (Node*)malloc(sizeof(Node));
    tmp->info = data;
    p = last->link;
    do{
        if(p->info == item){
            tmp->link = p->link;
            p->link = tmp;
            if(p == last){
                last = tmp;
            }
            return last;
        }
        p = p->link;
    }while(p!=last->link);
    printf("Element not found\n");
    return last;
    
}

Node * delete(Node* last,int data){
    Node *tmp,*p;
    if(last == NULL){
        printf("List is empty\n");
        return last;
    }
    if(last->link == last && last->info == data){
        tmp = last;
        last = NULL;
        free(tmp);
        return last;
    }
    if(last->link->info == data){
        tmp = last->link;
        last->link = tmp->link;
        free(tmp);
        return last;
    }
    p = last->link;
    while(p->link != last){
        if(p->link->info == data){
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return last;
        }
        p = p->link;
    }
    if(last->info == data){
        tmp = last;
        p->link = last->link;
        last = p;
        free(tmp);
        return last;
    }
    printf("Element not found\n");
    return last;
    
}


int main(void){
    Node* last = NULL;
    last = add_to_empty(last,1);
    last = add_at_end(last,2);
    last = add_at_end(last,3);
    last = add_at_end(last,4);
    last = add_after(last,6,2);
    last = delete(last,6);
    display(last);
    return 0;
}
