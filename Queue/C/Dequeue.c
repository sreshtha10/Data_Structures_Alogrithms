/* Dequeue - Double Ended Queue
    Functions : 1. insert at front end 
                2. insert at rear end 
                3. delete from front end
                4. delete from rear end
                */
                
#include<stdio.h>
#define MAX 10
int dq[MAX];
int front =-1,rear = -1;

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
    if(front <= rear){
        while(i<=rear){
            printf("%d ",dq[i]);
            i += 1;
        }
    }
    else{
        while(i<=MAX-1){
            printf("%d ",dq[i]);
            i+=1;
        }
        i = 0;
        while(i<=rear){
            printf("%d ",dq[i]);
            i+=1;
        }
    }
    printf("\n");
    return;
}

void insert_at_rearEnd(int x){
    if(isFull()){
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1){
        front = 0;
        rear = 0;
    }
    else if(rear == MAX-1){
        rear = 0;
    }
    else{
        rear += 1;
    }
    dq[rear] = x;
    return;
}

void insert_at_frontEnd(int x){
    if(isFull()){
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1){
        front = 0;
        rear =0;
    }
    else if(front == 0){
        front = MAX-1;
    }
    else{
        front -= 1;
    }
    dq[front] = x;
    return;
}

int delete_at_frontEnd(){
    if(isEmpty()){
        printf("Queue Underflow\n");
        exit(1);
    }
    int x = dq[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else if(front == MAX-1){
        front = 0;
    }
    else{
        front += 1;
    }
    return x;
}

int delete_at_rearEnd(){
    if(isEmpty()){
        printf("Queue Underflow\n");
        exit(1);
    }
    int x = dq[rear];
    if(front == rear){
        front =-1;
        rear = -1;
    }
    else if(rear == 0){
        rear = MAX-1;
    }
    else{
        rear -= 1;
    }
    return x;
}

int main(void){
    insert_at_frontEnd(1);
    insert_at_frontEnd(2);
    insert_at_rearEnd(3);
    delete_at_rearEnd();
    delete_at_frontEnd();
    delete_at_frontEnd();
    insert_at_frontEnd(10);
    display();
}

