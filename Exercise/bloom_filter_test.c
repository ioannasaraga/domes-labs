#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "bloom_filter.h"
#include "./customer/customer.h"

// Including the acutest.h library
#include "./acutest/acutest.h"

void test_bloom_filter_set_bit(void){
    BloomFilter *bf = bloom_filter_create(100);
    for(int i=4;i<=76;i+=8)
        bloom_filter_set_bit(bf,i);

    for(int i=0;i<10;i++)
        TEST_CHECK(bf->array[i]==16);

    bloom_filter_destroy(bf);
}


void test_bloom_filter_get_bit(void) {
    BloomFilter *bf = bloom_filter_create(100);
    for(int i=4;i<=76;i+=8)
        bloom_filter_set_bit(bf,i);

    for(int i=4;i<=76;i+=8)
        TEST_CHECK(bloom_filter_get_bit(bf,i)==1);

    TEST_CHECK(bloom_filter_get_bit(bf,3)==0);
    TEST_CHECK(bloom_filter_get_bit(bf,69)==0);
    TEST_CHECK(bloom_filter_get_bit(bf,99)==0);

    bloom_filter_destroy(bf);
}


void test_bloom_filter_insert(void) {
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

    //Create a bloom filter and insert all customers
    BloomFilter *bf = bloom_filter_create(60);
    for(int i=0;i<10;i++)
        bloom_filter_insert(bf,customers[i]);

    for(int i=4;i<12;i++)
        TEST_CHECK(bloom_filter_get_bit(bf,4)==1);

    for(int i=0;i<10;i++)
        customer_destroy(customers[i]);
    free(customers);
    bloom_filter_destroy(bf);
}


void test_bloom_filter_check(void) {
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

    //Create a bloom filter and insert all customers
    BloomFilter *bf = bloom_filter_create(60);
    for(int i=0;i<10;i++)
        bloom_filter_insert(bf,customers[i]);

    for(int i=0;i<10;i++)
        TEST_CHECK(bloom_filter_check(bf,customers[i])==1);

    Customer *not = customer_create("ABC","name11","lastname11",30,10);
    TEST_CHECK(bloom_filter_check(bf,not)==0);
    customer_destroy(not);

    for(int i=0;i<10;i++)
        customer_destroy(customers[i]);
    free(customers);
    bloom_filter_destroy(bf);
}

TEST_LIST = {
        { "test_bloom_filter_set_bit", test_bloom_filter_set_bit },
        { "test_bloom_filter_get_bit",  test_bloom_filter_get_bit },
        { "test_bloom_filter_insert",  test_bloom_filter_insert },
        { "test_bloom_filter_check",  test_bloom_filter_check },
        { NULL, NULL }
};
