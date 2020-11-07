  
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
        par->rchild = tmp;
    }
    else{
        par->lchild = tmp;
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
        ptr->lchild = insert_r( ptr->lchild,ikey);
        
    }
    else{
        printf("DUPLICATE\n");
    }
    return ptr;
}

/* deletion - case 1.  Node to be deleted is a leaf
              case 2. Node to be deleted has only 1 child.
              case 3. Node to be deleted has 2 child.
    */
    
Treenode* delete_nr(Treenode* root,int dkey){
    Treenode* ptr = root,*par = NULL;
    while(ptr != NULL){
        if(dkey == ptr->data){
            break;
        }
        par = ptr;
        if(dkey > ptr->data){
            ptr = ptr->rchild;
        }
        else{
            ptr = ptr->lchild;   
        }
    }
    if(ptr == NULL) // element not found
    {
        printf("%d not found in the BST\n",dkey);
        return root;
    }
    else if(ptr->lchild == NULL && ptr->rchild == NULL){ // no child.
        // case 1
        if(par == NULL){ // root node to be deleted
            root = NULL;
        }
        else if(par->lchild == ptr){
            par->lchild = NULL;
        }
        else{
            par->rchild = NULL;
        }
        free(ptr);
        return root;
    }
    else if(ptr->lchild == NULL || ptr->rchild == NULL){ // one child.
        // case 2.
        if(par == NULL){ // ptr is root node
            if(ptr->lchild != NULL){
                root = ptr->lchild;
                free(ptr);
                return root;
            }
            else{
                root = ptr->rchild;
                free(ptr);
                return root;
            }
        }
        else if(ptr == par->lchild){
            if(ptr->lchild != NULL){
                par->lchild = ptr->lchild;
                free(ptr);
                return root;
            }
            else{
                par->lchild = ptr->rchild;
                free(ptr);
                return root;
                
            }
        }
        else{
            if(ptr->lchild != NULL){
                par->rchild = ptr->lchild;
                free(ptr);
                return root;
            }
            else{
                par->rchild = ptr->rchild;
                free(ptr);
                return root;
                
            }
        }
        
    }
    else{ // node to be deleted has two childs.
        // case 3.
        int x;
        Treenode* tmp = ptr->rchild,*tmp2 = ptr->rchild;
        while(tmp->lchild != NULL){
            tmp2 = tmp;
            tmp = tmp->lchild;
        }
        x = tmp->data;
        tmp2->lchild = NULL;
        free(tmp);
        ptr->data = x;
        if(par == NULL){
            root = ptr;
        }
        return root;
    }
    
    
    return root;
}


int main(void){
    Treenode* root = NULL;
    root = insert_r(root,10);
    root = insert_r(root,7);
    root = insert_r(root,8);
    root = insert_r(root,9);
    root = insert_r(root,12);
    root - insert_r(root,11);
    root = insert_r(root,13);
    //preorder(root);
    root = delete_nr(root,10);
    preorder(root);

    
    
    return 0;
}
