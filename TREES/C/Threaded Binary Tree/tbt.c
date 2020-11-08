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
    int deta;
    boolean rthread;
    struct treenode* rchild;
}Treenode;


