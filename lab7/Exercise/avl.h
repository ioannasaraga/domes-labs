#ifndef K08_DEV_AVL_H
#define K08_DEV_AVL_H

typedef struct avl_node{
    int key;
    struct avl_node *left;
    struct avl_node *right;
    int height; // Height of the tree in the current node
}AVLTree;

int max(int a,int b);
int avl_height(AVLTree *avl);
AVLTree *avl_create_node(int key);
int avl_balance(AVLTree *node);
AVLTree *avl_right_rotate(AVLTree *y);
AVLTree *avl_left_rotate(AVLTree *x);
AVLTree *avl_insert(AVLTree *node, int key);
void avl_preorder(AVLTree *node);
void avl_destroy(AVLTree *node);

#endif //K08_DEV_AVL_H
