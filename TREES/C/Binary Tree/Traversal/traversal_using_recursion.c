/* Binary Search Tree is a node-based binary tree data structure which has the following properties:

The left subtree of a node contains only nodes with keys lesser than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
The left and right subtree each must also be a binary search tree.*/


#include<stdio.h>
#include<stdlib.h>

typedef struct treenode{
    int data;
    struct treenode *lchild;
    struct treenode* rchild;
}Treenode;


// traversal - same as binary tree - preorder, inorder, postorder.

void preorder(Treenode* ptr){
    if(ptr == NULL){ // Base Case;
        return;
    }
    printf("%d ",ptr->data);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

void inorder(Treenode* ptr){
    if(ptr == NULL){
        return;
    }
    inorder(ptr->lchild);
    printf("%d ",ptr->data);
    inorder(ptr->rchild);
}

void postorder(Treenode* ptr){
    if(ptr == NULL){
        return;
    }
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d ",ptr->data);
}



/* searching - * if the key = element, element is found.
               * if the key < element, search in left subtree
               * if the key > element, search in the right subtree.
               * if the pointer reaches NULL ie the end of the tree, element is not in the BST.
               
*/

Treenode* search_nr(Treenode* root,int element){   // nr - non recursive
    Treenode* ptr = root;
    while(ptr != NULL){
        if(ptr->data == element){
            return ptr;
        }
        else if(ptr->data > element){
            ptr = ptr->lchild;
        }
        else{
            ptr = ptr->rchild;
        }
    }
    return NULL; // element not found
}


Treenode* search_r(Treenode* root,int element){ // r - recursive
    if(root == NULL){
        return NULL; // element not found
    }
    if(root->data == element){
        return root;
    }
    else if(element > root->data){
        search_r(root->rchild,element);
    }
    else{
        search_r(root->lchild,element);
    }
}


// Min and Max keys in BST

Treenode* min_nr(Treenode* ptr){
    if(ptr == NULL){
        return NULL;
    }
    while(ptr->lchild != NULL){
        ptr = ptr->lchild;
    }
    return ptr;
}

Treenode* min_r(Treenode* ptr){
    if(ptr== NULL){
        return NULL;
    }
    else if(ptr->lchild == NULL){
        return ptr;
    }
    else{
        return min_r(ptr->lchild);
    }
}

Treenode* max_nr(Treenode* ptr){
    if(ptr == NULL){
        return NULL;
    }
    while(ptr->rchild != NULL){
        ptr = ptr->rchild;
    }
    return ptr;
}


Treenode* max_r(Treenode* ptr){
    if(ptr == NULL){
        return NULL;
    }
    else if(ptr->rchild == NULL){
        return ptr;
    }
    else{
        return max_r(ptr->rchild);
    }
}

// insertion

Treenode* insert_nr(Treenode* root,int ikey){
    Treenode* ptr,*par = NULL;
    ptr = root;
    while(ptr!=NULL){
        par = ptr;
        if(ikey > ptr->data){
            ptr = ptr->rchild;
        }
        else if(ikey < ptr->data){
            ptr = ptr->lchild;
        }
        else{
            printf("DUPLICATE DATA\n");
            return root;
        }
    }
    Treenode* tmp = (Treenode*)malloc(sizeof(Treenode));
    tmp->data = ikey;
    tmp->lchild = NULL;
    tmp->rchild = NULL;
    if(par == NULL){
        root= tmp;
        return root;
    }
    else if(ikey > par->data){
        par->lchild = tmp;
    }
    else{
        par->rchild = tmp;
    }
    return root;
}


Treenode* insert_r(Treenode* ptr,int ikey){
    if(ptr == NULL){  // Base case.
        ptr = (Treenode*)malloc(sizeof(Treenode));
        ptr->data = ikey;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
    }
    else if(ikey>ptr->data){
        ptr->rchild = insert_r(ptr->rchild,ikey);
    }
    else if(ikey < ptr->data){
        ptr->lchild = insert_r(ptr->lchild,ikey);
        
    }
    else{
        printf("DUPLICATE\n");
    }
    return ptr;
}


int main(void){
    Treenode* root = NULL;

    return 0;
}
