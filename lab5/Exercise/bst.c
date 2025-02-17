#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

// Creating a new BSTNode with input data
BSTNode* create_node(int data) {
    BSTNode* temp = (BSTNode*)malloc(sizeof(BSTNode));
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

// Insert a new node into the binary search tree
BSTNode* insert(BSTNode* root, int data) {
    if (root == NULL) return create_node(data);
    if (data < root->data)
        // If the data is less than the root node, insert it into the left subtree
        root->left = insert(root->left, data);
    else if (data > root->data)
        // If the data is greater than or equal to the root node, insert it into the right subtree
        root->right = insert(root->right, data);
    return root;
}

// CAUTION: visit is a method that it is passed as an argument to other methods
void visit(BSTNode* node) {
    printf("%d ", node->data);
}

int count(BSTNode* root)
{
    return root ? count(root->left) + count(root->right) + 1 : 0;
}

// De-allocating all the memory of the tree
void destroy(BSTNode* node) {
    if (node != NULL) {
        destroy(node->left);
        destroy(node->right);
        free(node);
    }
}

/* -------------------------- */
/* FUNCTIONS FOR LAB EXERCISE */
/* -------------------------- */

BSTNode* delete(BSTNode* root, int data) 
{
    if (root == NULL) {
        return NULL;
    }
    
    if (data < root->data) {
        root->left = delete(root->left, data);
    } 
    else if (data > root->data) {
        root->right = delete(root->right, data);
    } 
    else {
        
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        }

        
        BSTNode* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }

        
        root->data = temp->data;

        
        root->right = delete(root->right, temp->data);
    }
    return root;
}
    

    


// Search a node from the binary search tree
BSTNode* search(BSTNode* root, int data) {
    /* EXERCISE */
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
        return root;
    }
    else if(root->data<data){
       return  search(root->right,data);
    }
    else{
       return  search(root->left,data);
    }
}

// Traverse the binary search tree in-order
void inorder(BSTNode* root, Visit visit) {
    /* EXERCISE */
    if(root==NULL){
        return;
    }
    inorder(root->left,visit);
    visit(root);
    inorder(root->right,visit);
}

// Traverse the binary search tree pre-order
void preorder(BSTNode* root, Visit visit) {
    /* EXERCISE */
    if(root==NULL){
        return;
    }
    visit(root);
    preorder(root->left,visit);
    preorder(root->right,visit);
   
}

// Traverse the binary search tree post-order
void postorder(BSTNode* root, Visit visit) {
    /* EXERCISE */
    if(root==NULL){
        return;
    }
    postorder(root->left,visit);
    postorder(root->right,visit);
    visit(root);

}

// Find minimum value of a binary search tree
BSTNode* min_value(BSTNode* root) {
    /* EXERCISE */
    if(root==NULL){
        return NULL;
    }
    else if(root->left==NULL){
        return root;
    }
    else{
        return min_value(root->left);
    }
    
}

// Find maximum value of a binary search tree
BSTNode* max_value(BSTNode* root) {
    /* EXERCISE */
    if(root==NULL){
        return NULL;
    }
    else if(root->right==NULL){
        return root;
    }
    else{
        return max_value(root->right);
    }
}

