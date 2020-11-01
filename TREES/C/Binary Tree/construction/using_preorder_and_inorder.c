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

treenode* construct(struct listnode *pre, struct listnode* in,int num ){
    int i,j;
    if(num == 0){   //Empty tree
        return NULL;
    }
    struct treenode* tmp = (struct treenode*)malloc(sizeof(struct treenode));
    tmp->data = pre->data;
    tmp->lchild = NULL;
    tmp->rchild = NULL;
    if(num == 1){  // only one node is there in the tree.
        return tmp;
    }
    struct listnode* q = in;
    for(i = 0;q->data!=pre->data;i++){
        q = q->next;
    }
    //i is at the root of the tree. left of i in inorder will be it's left child.
    tmp->lchild = construct(pre->next,in,i);
    for(j=1;j<i+1;j++){
        pre = pre->next;
    }
    tmp->rchild = construct(pre,q->next,num-i-1);
    return tmp;
}


int main(void){
    return 0;
}
