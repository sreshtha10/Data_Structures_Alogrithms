/* threaded binary tree 
For a binary tree, total links are 2n out of which only n-1 are utilized as it contain n-1 edges. So memory is wasted for n+1  NULL links. This space can be utilized to increase the 
efficiency of binary tree. 
In threaded binary tree, these n+1 NULL links will contains the address of their inorder predecessor(stored in left link) and inorder successor(stored in right link). These utilized links are called threads.
*/
#include<stdio.h>
#include<stdlib.h>

typedef enum{ true,false}boolean;

typedef struct treenode{ // we will use boolean data types to differentiate b/w threads and actual child.
    boolean lthread;
    struct treenode* lchild;
    int data;
    boolean rthread;
    struct treenode* rchild;
}Treenode;


Treenode* inorder_sucessor(Treenode* ptr){
    if(ptr->rthread == true){
        return ptr->rchild;
    }
    ptr = ptr->rchild;
    while(ptr->lthread == false){
        ptr = ptr->lchild;
    }
    return ptr;
}


Treenode* inorder_predecessor(Treenode* ptr){
    if(ptr->lthread == true){
        return ptr->lchild;
    }
    ptr  = ptr->lchild;
    while(ptr->rthread == false){
        ptr = ptr->rchild;
    }
    return ptr;
}


void inorder_traversal(Treenode* root){
    Treenode* ptr;
    if(root == NULL){
        printf("Tree is empty\n");
        return;
    }
    ptr= root;
    while(ptr->lthread == false){
        ptr = ptr->lchild;
    }
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = inorder_sucessor(ptr);
    }
    printf("\n");
    return;
}


Treenode* insert(Treenode* root, int element){
    Treenode *tmp,*par = NULL,*ptr;
    ptr = root;
    // first we will check if the element already exists
    while(ptr != NULL){
        if(element == ptr->data){
            printf("element already exists\n");
            return root;
        }
        par = ptr;
        if(element < ptr->data){
            if(ptr->lthread == false){
                ptr = ptr->lchild;
            }
            else{
                    break;
            }
        }
        else{
            if(ptr->rthread == false){
                ptr = ptr->rchild;
            }
            else{
                break;
            }
        }
    }
    // if element is not already there we will insert it.
    tmp = (Treenode*)malloc(sizeof(Treenode));
    tmp->data = element;
    tmp->rthread = true;
    tmp->lthread = true;
 
    if(par == NULL){   // tree is empty.
        root = tmp;
        tmp->lchild = NULL;
        tmp->rchild = NULL;
    }
    else if(element < par->data){     // insertion in left subtree.
        par->lthread = false;
        tmp->lchild = par->lchild;
        tmp->rchild = par;
        par->lchild = tmp;
    } 
    else{                   // insertion in left subtree.
        par->rthread = false;
        tmp->rchild = par->rchild;
        tmp->lchild = par;
        par->rchild = tmp;
    }
    return root;
}


/* Deletion in threaded BST
    case 1. Node to be deleted is a leaf.
    case 2. Node to be deleted has one child
    case 3. Node to be deleted has two children.
*/

Treenode* case_a(Treenode* root,Treenode* ptr, Treenode* par){
    if(par == NULL){
        root = NULL;
    }
    else if(par->lchild == ptr)  //left child is to be deleted.
    {
        par->lthread = true;
        par->lchild = ptr->lchild;
    }
    else{
        par->rthread = true;
        par->rchild  = ptr->rchild;
    }
    free(ptr);
    return root;
}




int main(void){
    Treenode* root = NULL;
    root = insert(root,1);
    root = insert(root,2);
    root = insert(root,0);
    root = insert(root,5);
    root = insert(root,4);
    inorder_traversal(root);
    return 0;
}
