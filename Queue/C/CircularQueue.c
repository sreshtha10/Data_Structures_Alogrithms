// Circular Queue using array 

#include<stdio.h>
#define MAX 10

int cq[MAX];
int front =-1,rear=-1;

int isEmpty(){
    if(front == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(front == rear+1 || (front == 0 && rear ==  MAX-1)){
        return 1;
    }
    else{
        return 0;
    }
}

void display(){
    if(isEmpty()){
        printf("Queue Underflow\n");
        return;
    }
    int i = front;
    if(front < rear){
        while(i<=rear){
            printf("%d ",cq[i]);
            i += 1;
        }
    }
    else{
        while(i<=MAX-1){
            printf("%d ",cq[i]);
            i+=1;
        }
        i = 0;
        while(i<=rear){
            printf("%d ",cq[i]);
            i+=1;
        }
    }
    printf("\n");
    return;
}

void insert(int x){
    if(isFull()){
        printf("Queue Overflow\n");
        return;
    }
    if(front = -1){  // queue is empty
        front = 0;
    }
    if(rear == MAX-1){   // rear is at the last element of the array
        rear = 0;
    }
    else{
        rear = rear+1;
    }
    cq[rear] = x;
    return;
}


int delete(){
    if(isEmpty()){
        printf("Queue Underflow\n");
        return;
    }
    int x = cq[front];
    if(front == rear){ // only one element is left
        front =-1;
        rear =-1;
    }
    else if(front == MAX-1){
        front = 0;
    }
    else{
        front += 1;
    }
    return x;
}

int peek(){
    if(isEmpty()){
        printf("Queue Underflow\n");
        exit(1);
    }
    return cq[front];
}


int main(void){
    insert(5);
    insert(10);
    insert(15);
    display();
    delete();
    display();
    printf("%d\n",peek());
    insert(20);
    insert(25);
    insert(30);
    display();
    delete();
    display();
    return 0;
    
}

