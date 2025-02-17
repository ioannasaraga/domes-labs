#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "hashtable.h"
#include "./list/list.h"
#include "./customer/customer.h"

// Including the acutest.h library
#include "./acutest/acutest.h"

#define HASHTABLE_TEST_SIZE 5

// Test the hashtable_hash function
void test_hashtable_hash(void) {
    // Create a hashtable
    Hashtable* h = hashtable_with_default_size();

    // Create a customer
    Customer* c = customer_create("123456789", "John", "Doe", 1000, 20);

    // Check that the hash function returns the correct value
    TEST_CHECK(h != NULL);
    TEST_CHECK(hashtable_hash(h, customer_get_id(c)) == 73);

    // De-allocate the hashtable and customer
    hashtable_destroy(h);
    customer_destroy(c);
}

// Test the hashtable_insert function
void test_hashtable_insert(void) {
    // Create a hashtable
    Hashtable* h = hashtable_create(HASHTABLE_TEST_SIZE);

    // Create 10 customers
    Customer **customers = malloc(sizeof(Customer*) * 10);
    char id[10][5] = {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10"};
    char name[10][15] = {"name1", "name2", "name3", "name4", "name5", 
                            "name6", "name7", "name8", "name9", "name10"};
    char lastname[10][15] = {"lastname1", "lastname2", "lastname3", "lastname4", "lastname5", 
                                "lastname6", "lastname7", "lastname8", "lastname9", "lastname10"};
    size_t age[10] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
    int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};

    for(int i = 0; i < 10; i++)
        customers[i] = customer_create(id[i], name[i], lastname[i], age[i], data[i]);

    for(int i = 0; i < 10; i++) {
        h = hashtable_insert(h, customers[i]);

        if (i == 4)
            TEST_CHECK(h != NULL && hashtable_size(h) == 11);

        if (i == 9)
            TEST_CHECK(h != NULL && hashtable_size(h) == 23);

        TEST_CHECK(hashtable_get_number_of_customers(h) == i + 1);
    }

    // De-allocate the hashtable and customer
    hashtable_destroy(h);

    // Destroy customers
    for(int i = 0; i < 10; i++)
        customer_destroy(customers[i]);
    free(customers);
}


// Test the hashtable_get function
void test_hashtable_get(void) {
    // Create a hashtable
    Hashtable* h = hashtable_create(HASHTABLE_TEST_SIZE);

    // Create 10 customers
    Customer **customers = malloc(sizeof(Customer*) * 10);
    char id[10][5] = {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10"};
    char name[10][15] = {"name1", "name2", "name3", "name4", "name5", 
                            "name6", "name7", "name8", "name9", "name10"};
    char lastname[10][15] = {"lastname1", "lastname2", "lastname3", "lastname4", "lastname5", 
                                "lastname6", "lastname7", "lastname8", "lastname9", "lastname10"};
    size_t age[10] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
    int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};

    for(int i = 0; i < 10; i++)
        customers[i] = customer_create(id[i], name[i], lastname[i], age[i], data[i]);

    for(int i = 0; i < 10; i++)
        h = hashtable_insert(h, customers[i]);

    for(int i = 0; i < 10; i++)
        TEST_CHECK(hashtable_get(h, id[i]) == customers[i]);
    
    // Check entity not found
    TEST_CHECK(hashtable_get(h, "A11") == NULL);

    // De-allocate the hashtable and customer
    hashtable_destroy(h);

    // Destroy customers
    for(int i = 0; i < 10; i++)
        customer_destroy(customers[i]);
    free(customers);
}

// Test the hashtable_remove function
void test_hashtable_remove(void) {
    // Create a hashtable
    Hashtable* h = hashtable_create(HASHTABLE_TEST_SIZE);

    // Create 10 customers
    Customer **customers = malloc(sizeof(Customer*) * 10);
    char id[10][5] = {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10"};
    char name[10][15] = {"name1", "name2", "name3", "name4", "name5", 
                            "name6", "name7", "name8", "name9", "name10"};
    char lastname[10][15] = {"lastname1", "lastname2", "lastname3", "lastname4", "lastname5", 
                                "lastname6", "lastname7", "lastname8", "lastname9", "lastname10"};
    size_t age[10] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
    int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};

    for(int i = 0; i < 10; i++)
        customers[i] = customer_create(id[i], name[i], lastname[i], age[i], data[i]);

    for(int i = 0; i < 10; i++)
        h = hashtable_insert(h, customers[i]);

    for(int i = 0; i < 10; i++)
        TEST_CHECK(hashtable_remove(h, id[i]) == SUCCESS);

    for(int i = 0; i < 10; i++)
        TEST_CHECK(hashtable_get(h, id[i]) == NULL);

    // Check entity not found
    TEST_CHECK(hashtable_remove(h, "A11") == FAILURE);

    // De-allocate the hashtable and customer
    hashtable_destroy(h);

    // Destroy customers
    for(int i = 0; i < 10; i++)
        customer_destroy(customers[i]);
    free(customers);
}


TEST_LIST = {
        { "test_hashtable_hash", test_hashtable_hash },
        { "test_hashtable_insert",  test_hashtable_insert },
        { "test_hashtable_get",  test_hashtable_get },
        { "test_hashtable_remove",  test_hashtable_remove },
        { NULL, NULL }
};
