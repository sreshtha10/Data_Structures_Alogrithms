#include<stdio.h>
#include<stdlib.h>

typedef struct treenode{
    struct treenode* lchild;
    int data;
    struct treenode* rchild;
}treenode;

typedef struct listnode{
    int data;
    struct listnode* next;
}listnode;

treenode* construct(listnode *post,listnode* in,int num){
    if(num == 0){
        return NULL;
    }
    treenode* tmp = (treenode*)malloc(sizeof(treenode));
    listnode* ptr= post;
    for(int i=0;i<num;i++){
        ptr = ptr->next;   
    }
    tmp->data = ptr->data;
    tmp->lchild = NULL;
    tmp->rchild = NULL;
    if(num == 1){
        return tmp;
    }
    listnode* q = in;
    int i,j;
    for(i = 0;q->data!=ptr->data;i++){
        q = q->next;
    }
    tmp->lchild = construct(post,in,i);
    for(j=1;j<i+1;j++){
        post = post->next;
    }
    tmp->rchild = construct(post,q->next,num-i-1);
    return tmp;
}

int main(void){
    return 0;
}
