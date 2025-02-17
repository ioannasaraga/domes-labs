#include <stdlib.h>

#include "bst.h"

// Including the acutest.h library
#include "acutest/acutest.h"

// Test inserting BSTNodes into the binary search tree
void test_insert(void) {
    BSTNode* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Test that the BSTNodes were inserted in the correct order
    TEST_CHECK(root->data == 50);
    TEST_CHECK(root->left->data == 30);
    TEST_CHECK(root->right->data == 70);
    TEST_CHECK(root->left->left->data == 20);
    TEST_CHECK(root->left->right->data == 40);
    TEST_CHECK(root->right->left->data == 60);
    TEST_CHECK(root->right->right->data == 80);

    destroy(root);
}

// Test deleting BSTNodes from the binary search tree
void test_delete(void) {
    BSTNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 15);
    insert(root, 10);
    insert(root, 5);
    insert(root, 23);
    insert(root, 25);
    insert(root, 40);
    insert(root, 35);
    insert(root, 45);
    insert(root, 70);
    insert(root, 60);
    insert(root, 55);
    insert(root, 65);
    insert(root, 80);
    insert(root, 75);
    insert(root, 85);


    // Delete some nodes from the tree

    // For cases where there is only one child or no child
    root = delete(root, 5);
    root = delete(root, 15);
    root = delete(root, 23);    

    root = delete(root, 85);
    root = delete(root, 30);
    root = delete(root, 50);

    // Test the new root node
    TEST_CHECK(root->data == 45 || root->data == 55);

    // Test that the deleted nodes are no longer in the tree
    TEST_CHECK(search(root, 5) == NULL);
    TEST_CHECK(search(root, 15) == NULL);
    TEST_CHECK(search(root, 23) == NULL);
    TEST_CHECK(search(root, 30) == NULL);
    TEST_CHECK(search(root, 50) == NULL);
    TEST_CHECK(search(root, 85) == NULL);

    // Check the tree contains the correct number of nodes
    TEST_CHECK(count(root) == 12);

    if (root->data == 45)
    {
        TEST_CHECK(root->left->left->left->data == 10);
        TEST_CHECK(root->left->left->data == 20);
        TEST_CHECK(root->left->left->right == NULL);

        TEST_CHECK(root->left->data == 25);

        TEST_CHECK(root->left->right->left->data == 35);
        TEST_CHECK(root->left->right->data == 40);
        TEST_CHECK(root->left->right->right == NULL);

        
        TEST_CHECK(root->right->left->left->data == 55);
        TEST_CHECK(root->right->left->data == 60);
        TEST_CHECK(root->right->left->right->data == 65);

        TEST_CHECK(root->right->data == 70);

        TEST_CHECK(root->right->right->left->data == 75);
        TEST_CHECK(root->right->right->data == 80);
        TEST_CHECK(root->right->right->right == NULL);
    }
    else
    {
        TEST_CHECK(root->left->left->left->data == 10);
        TEST_CHECK(root->left->left->data == 20);
        TEST_CHECK(root->left->left->right->data == 25);

        TEST_CHECK(root->left->data == 35);

        TEST_CHECK(root->left->right->left == NULL);
        TEST_CHECK(root->left->right->data == 40);
        TEST_CHECK(root->left->right->right->data == 45);

        
        TEST_CHECK(root->right->left->left == NULL);
        TEST_CHECK(root->right->left->data == 60);
        TEST_CHECK(root->right->left->right->data == 65);

        TEST_CHECK(root->right->data == 70);

        TEST_CHECK(root->right->right->left->data == 75);
        TEST_CHECK(root->right->right->data == 80);
        TEST_CHECK(root->right->right->right == NULL);
    }

    destroy(root);
}

void test_search(void) {
    // Create a new binary search tree
    BSTNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Test searching for a node that exists
    BSTNode* found = search(root, 40);
    TEST_CHECK(found->data == 40);

    // Test searching for a node that does not exist
    found = search(root, 10);
    TEST_CHECK(found == NULL);

    destroy(root);
}


// Create an array to store the visited nodes
static int test_postorder_visited[7];
static int test_postorder_index = 0;
void save_visited_postorder(BSTNode* node) {
    test_postorder_visited[test_postorder_index++] = node->data;
}
// Test the postorder function
void test_postorder(void) {
    // Initialize a binary search tree
    // printf("HERE");
    BSTNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Traverse the tree in postorder
    postorder(root, save_visited_postorder);

    // Test that the visited nodes are in the correct order
    TEST_CHECK(test_postorder_visited[0] == 20);
    TEST_CHECK(test_postorder_visited[1] == 40);
    TEST_CHECK(test_postorder_visited[2] == 30);
    TEST_CHECK(test_postorder_visited[3] == 60);
    TEST_CHECK(test_postorder_visited[4] == 80);
    TEST_CHECK(test_postorder_visited[5] == 70);
    TEST_CHECK(test_postorder_visited[6] == 50);

    destroy(root);
}

// Test the preorder function
static int test_preorder_visited[7];
static int test_preorder_index = 0;
void save_visited_preorder(BSTNode* node) {
    test_preorder_visited[test_preorder_index++] = node->data;
}
void test_preorder() {
    // Initialize a binary search tree
    BSTNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Traverse the tree in preorder
    preorder(root, save_visited_preorder);

    // Test that the visited nodes are in the correct order
    TEST_CHECK(test_preorder_visited[0] == 50);
    TEST_CHECK(test_preorder_visited[1] == 30);
    TEST_CHECK(test_preorder_visited[2] == 20);
    TEST_CHECK(test_preorder_visited[3] == 40);
    TEST_CHECK(test_preorder_visited[4] == 70);
    TEST_CHECK(test_preorder_visited[5] == 60);
    TEST_CHECK(test_preorder_visited[6] == 80);

    destroy(root);
}

// Test the inorder function
static int test_inorder_visited[7];
static int test_inorder_index = 0;
void save_visited_inorder(BSTNode* node) {
    test_inorder_visited[test_inorder_index++] = node->data;
}
void test_inorder() {
    // Initialize a binary search tree
    BSTNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Traverse the tree in inorder
    inorder(root, save_visited_inorder);

    // Test that the visited nodes are in the correct order
    TEST_CHECK(test_inorder_visited[0] == 20);
    TEST_CHECK(test_inorder_visited[1] == 30);
    TEST_CHECK(test_inorder_visited[2] == 40);
    TEST_CHECK(test_inorder_visited[3] == 50);
    TEST_CHECK(test_inorder_visited[4] == 60);
    TEST_CHECK(test_inorder_visited[5] == 70);
    TEST_CHECK(test_inorder_visited[6] == 80);

    destroy(root);    
}

// Test the min_value function
void test_min_value() {
    // Initialize a binary search tree
    BSTNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Get the minimum value in the tree
    BSTNode* min_node = min_value(root);
    int min_val = min_node->data;
    // Test that the minimum value is correct
    TEST_CHECK(min_val == 20);

    destroy(root);
}

// Test the max_value function
void test_max_value() {
    // Initialize a binary search tree
    BSTNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Get the maximum value in the tree
    BSTNode* max_node = max_value(root);
    int max_val = max_node->data;

    // Test that the maximum value is correct
    TEST_CHECK(max_val == 80);

    destroy(root);
}


TEST_LIST = {
    { "test_insert", test_insert },
    { "test_delete", test_delete },
    { "test_search", test_search },
    { "test_postorder", test_postorder },
    { "test_inorder", test_inorder },
    { "test_preorder", test_preorder },
    { "test_min_value", test_min_value },
    { "test_max_value", test_max_value },
    { NULL, NULL }
};