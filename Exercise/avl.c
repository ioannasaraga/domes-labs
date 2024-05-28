#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

// A utility function to get maximum of two integers
int max(int a,int b){
    return (a > b)? a : b;
}

//Return the height of a node
int avl_height(AVLTree *avl){
    if(avl==NULL) return 0;
    return avl->height;
}

//A function to create a new node
//Height of node is initially 1, since the simple bst insertion, inserts the node as a leaf
AVLTree *avl_create_node(int key){
    AVLTree *node = malloc(sizeof(AVLTree));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

//Return the balance of a current node
int avl_balance(AVLTree *node){
    if (node==NULL) return 0;
    return avl_height(node->left) - avl_height(node->right);
}

//Function to perform a right rotation on a node
AVLTree *avl_right_rotate(AVLTree *y){
    /* EXERCISE */
}

//Function to perform a left rotation on a node
AVLTree *avl_left_rotate(AVLTree *x){
    /* EXERCISE */
}

//Function to insert a node in an AVL tree
AVLTree *avl_insert(AVLTree *node, int key){
    /* EXERCISE */
}

void avl_preorder(AVLTree *node){
    if(node!=NULL){
        printf("%d\n",node->key);
        avl_preorder(node->left);
        avl_preorder(node->right);
    }
}

void avl_destroy(AVLTree *node){
    if (node != NULL) {
        avl_destroy(node->left);
        avl_destroy(node->right);
        free(node);
    }
}