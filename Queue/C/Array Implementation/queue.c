// Array implementation of queue

#include<stdio.h>
#define MAX 10
int q[MAX];
int front  = -1,rear = -1;

void insert(int x){
    if(rear == MAX-1){
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1)
        front = 0;
    rear = rear+1;
    q[rear] = x;
}

int delete(){
    int x;
    if(front == -1 || front == rear +1){
        printf("Queue underflow\n");
        return;
    }
    x = q[front];
    front  = front +1;
    return x;
}

int peek(){
    int x;
    if(front == -1 || front  == rear+1){
        printf("Queue Underflow\n");
        return;
    }
    x = q[front];
    return x;
}

void display(){
    
}

int main(void){
    
}
