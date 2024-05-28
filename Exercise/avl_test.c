#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "avl.h"

// Including the acutest.h library
#include "./acutest/acutest.h"

/* HELPER FUNCTIONS */
int isBalanced(AVLTree *root)
{
    /* for height of left subtree */
    int lh;

    /* for height of right subtree */
    int rh;

    /* If tree is empty then return true */
    if (root == NULL)
        return 1;

    /* Get the height of left and right sub trees */
    lh = avl_height(root->left);
    rh = avl_height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left)
        && isBalanced(root->right))
        return 1;

    /* If we reach here then tree is not height-balanced */
    return 0;
}

/* --- TESTS ---------*/

void test_avl_right_rotate(){
    //No left child case
    AVLTree *node = avl_create_node(5);
    node = avl_right_rotate(node);

    TEST_CHECK(node->key == 5);

    avl_destroy(node);

    //No right child case
    node = avl_create_node(5);
    node->height = 2;
    node->left = avl_create_node(3);
    node = avl_right_rotate(node);

    TEST_CHECK(node->key == 3 && node->right->key == 5);
    TEST_CHECK(node->height == 2 && node->right->height == 1);

    avl_destroy(node);

    //Full subtrees case
    node = avl_create_node(5);
    node->height = 3;
    node->left = avl_create_node(3);
    node->left->height = 2;
    node->right = avl_create_node(8);
    node->right->height = 1;
    node->left->left = avl_create_node(1);
    node->left->right = avl_create_node(4);

    node = avl_right_rotate(node);

    TEST_CHECK(node->key == 3 && node->left->key == 1 && node->right->key == 5
         && node->right->left->key == 4 && node->right->right->key == 8);

    TEST_CHECK(node->height == 3 && node->right->height == 2);

    avl_destroy(node);
}

void test_avl_left_rotate(){
    //No right child case
    AVLTree *node = avl_create_node(3);
    node = avl_left_rotate(node);

    TEST_CHECK(node->key == 3);

    avl_destroy(node);

    //No left child case
    node = avl_create_node(3);
    node->height = 2;
    node->right = avl_create_node(5);

    node = avl_left_rotate(node);

    TEST_CHECK(node->key == 5 && node->left->key == 3);
    TEST_CHECK(node->height == 2 && node->left->height == 1);

    avl_destroy(node);

    //Full subtrees case
    node = avl_create_node(3);
    node->height = 3;
    node->right = avl_create_node(5);
    node->height = 2;
    node->left = avl_create_node(1);
    node->right->left = avl_create_node(4);
    node->right->right = avl_create_node(8);

    node = avl_left_rotate(node);

    TEST_CHECK(node->key == 5 && node->left->key == 3 && node->right->key == 8
               && node->left->left->key == 1 && node->left->right->key == 4);

    TEST_CHECK(node->height == 3 && node->left->height == 2);

    avl_destroy(node);

}

void test_avl_insert(){
    AVLTree *avl = NULL;
    avl = avl_insert(avl,10);
    avl = avl_insert(avl,20);
    avl = avl_insert(avl,30);
    avl = avl_insert(avl,40);
    avl = avl_insert(avl,50);
    avl = avl_insert(avl,25);
    avl = avl_insert(avl,5);
    avl = avl_insert(avl,15);
    avl = avl_insert(avl,0);
    avl = avl_insert(avl,35);
    avl = avl_insert(avl,60);
    avl = avl_insert(avl,70);

    TEST_CHECK(avl->key == 30 &&
               avl->left->key == 10 && avl->right->key == 40 &&
               avl->left->left->key == 5 && avl->left->right->key == 20 && avl->right->left->key == 35 && avl->right->right->key == 60 &&
               avl->left->left->left->key == 0 && avl->left->right->left->key == 15 && avl->left->right->right->key == 25 &&
               avl->right->right->left->key == 50 && avl->right->right->right->key == 70);

    avl_destroy(avl);

    //Large tree - check balance
    time_t t;
    srand((unsigned) time(&t));
    AVLTree *large = NULL;
    for(int i=0;i<1000;i++)
        large = avl_insert(large,rand()%10000);


    TEST_CHECK(isBalanced(large)==1);

    avl_destroy(large);
}


TEST_LIST = {
        { "test_avl_right_rotate", test_avl_right_rotate },
        { "test_avl_left_rotate",  test_avl_left_rotate },
        { "test_avl_insert", test_avl_insert },
        { NULL, NULL }
};
