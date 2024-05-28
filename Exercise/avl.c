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

 AVLTree * x=y->left;
 if(x==NULL){
    return y;
 }
 AVLTree * T2=x->right;
 x->right=y;
 y->left=T2;
 y->height=max(avl_height(y->left),avl_height(y->right))+1;
 x->height=max(avl_height(x->left),avl_height(x->right))+1;
 return x;
}

//Function to perform a left rotation on a node
AVLTree *avl_left_rotate(AVLTree *x){
    /* EXERCISE */

 AVLTree * y=x->right;
 if(y==NULL){
    return x;
 }
 AVLTree *T2=y->left;
 y->left=x;
 x->right=T2;
 x->height=max(avl_height(x->left),avl_height(x->right))+1;
 y->height=max(avl_height(y->left),avl_height(y->right))+1;
 return y;

}

//Function to insert a node in an AVL tree
AVLTree *avl_insert(AVLTree *node, int key){
    /* EXERCISE */
    if(node==NULL){
        return avl_create_node(key);
    }

    if(key==node->key){
        return node;
    }

    if(key>node->key){
        node->right=avl_insert(node->right,key);
    }
    else{
        node->left=avl_insert(node->left,key);
    }

 node->height=max(avl_height(node->left),avl_height(node->right))+1;

int balance=avl_balance(node);

if(balance>1 && key<node->left->key){
    return avl_right_rotate(node);
}
else if(balance>1 && key>node->left->key){
    node->left=avl_left_rotate(node->left);
    return avl_right_rotate(node);
}
else if(balance<-1 && key>node->right->key){
    return avl_left_rotate(node);
}
else if(balance<-1 && key<node->right->key){
    node->right=avl_right_rotate(node->right);
    return avl_left_rotate(node);
}

return node;

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