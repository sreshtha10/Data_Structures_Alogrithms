# Binary Search Tree.

## Properties

* All the keys in the left subtree of a node must be less than that node value.

* All the keys in the right subtree of a node must be greater than the node value.

* Both left and right subtree must be also a BST.

* No duplicates are allowed.


![Example](https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/1200px-Binary_search_tree.svg.png)

___

## Traversal

* Level Traversal - printing nodes at each level one by one.

* Preorder - (root) -> (left subtree) -> (right subtree).

* Inorder - (left subtree) -> (root) -> (right subtree).
    * Inorder always gives sorted result with BST.   

* Postorder - (left subtree) -> (right subtree) -> (root).

___

## Searching - O(h), h = height of tree.

* If element == node.value -> return node.

* If element < node.value -> search in left subtree.

* If element > node.value -> search in right substree.

* If element != leaf node -> element is not present in the BST.

* Worst case - O(logn)
* Best case - O(n)


___

## Insertion - O(h), h = height of tree.

* If key == node.value -> return as duplicates are not allowed.

* If key < node.value -> insertion to be done in left subtree.

* If key > node.value -> insertion to be done in right subtree.

* Once, a leaf node is reached, add the element to right or left of the leaf node.

* Insertion always happens in the leaf node.

___

## Deletion

* ### Case A - Node to be deleted has 0 child i.e. it is a leaf node.

    * Simply delete by setting the parent.right or parent.left = null


* ### Case B - Node to be deleted has 1 child.

    * node.parent.left | right = node.right | left.

* ### Case C - Node to be deleted has 2 children.
    
    * Replace the node with inorder successor or predecessor.
    
