// Array implementation of Stack
#include<stdio.h>
#include<stdio.h>

#define max 10   // Maximum size of our stack array
int stack[max];  // array
int top = -1;    // top represents the index of the top element, if stack is empty top = -1

void display(){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }
    for(int i = 0;i<=top;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
    return;
}

void push(int x){
    if(top == 10){
        printf("stack overflow\n");
        return;
    }
    stack[top+1]= x;
    top += 1;
    return;
}

int pop(){
    int item;
    if(top == -1){
        printf("Stack underflow\n");
        return;
    }
    item = stack[top];
    top -= 1;
    return item;
}

int peek(){
    int item;
    if(top == -1){
        printf("stack underflow\n");
        return;
    }
    return stack[top];
}

int main(void){
    
    display();
    push(1);
    push(2);
    push(3);
    display();
    printf("%d\n",pop());
    printf("%d",peek());
    
}
