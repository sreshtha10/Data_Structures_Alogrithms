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

/* searching - * if the key = element, element is found.
               * if the key < element, search in left subtree
               * if the key > element, search in the right subtree.
               * if the pointer reaches NULL ie the end of the tree, element is not in the BST.
               
*/

Treenode* search(Treenode* root,int element){
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


