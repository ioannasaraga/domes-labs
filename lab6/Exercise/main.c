#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "hashtable.h"
#include "./list/list.h"
#include "./customer/customer.h"

int main(void) {

    // Create 10 customers
    Customer **customers = malloc(sizeof(Customer*) * 10);

    char id[10][5] = {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10"};
    char name[10][15] = {"name1", "name2", "name3", "name4", "name5", 
                            "name6", "name7", "name8", "name9", "name10"};
    char lastname[10][15] = {"lastname1", "lastname2", "lastname3", "lastname4", "lastname5", 
                                "lastname6", "lastname7", "lastname8", "lastname9", "lastname10"};
    size_t age[10] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
    int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};

    printf("\nCreating customers...\n");
    for(int i = 0; i < 10; i++) {
        customers[i] = customer_create(id[i], name[i], lastname[i], age[i], data[i]);
        printf("Created Customer: %s %s %s %zu %d\n", customer_get_id(customers[i]), 
                                                        customer_get_firstname(customers[i]), 
                                                        customer_get_lastname(customers[i]), 
                                                        customer_get_age(customers[i]), 
                                                        customer_get_data(customers[i]));
    }

    // Create hashtable
    // Hashtable* h = hashtable_with_default_size();

    // Create hashtable with custom hash function
    Hashtable* h = hashtable_create(5);

    // Insert customers into hashtable
    printf("\nInserting customers into hashtable...\n");
    for(int i = 0; i < 10; i++) {
        // char * id = customer_get_id(customers[i]);
        h = hashtable_insert(h, customers[i]);
    }
    
    printf("Hashtable size: %zu\n", hashtable_size(h));
    printf("Number of customers in hashtable: %zu\n", hashtable_get_number_of_customers(h));

    hashtable_print(h);

    // Get customer with id A5 from hashtable
    printf("\nGetting customer A5 from hashtable...\n");
    char id5[5] = "A5";
    Customer *c5 = hashtable_get(h, id5);
    printf("Customer: %s %s %s %zu %d\n", customer_get_id(c5), 
                                            customer_get_firstname(c5), 
                                            customer_get_lastname(c5), 
                                            customer_get_age(c5), 
                                            customer_get_data(c5));

    printf("\nStatistics:\n");
    printf("Hashtable size: %zu\n", hashtable_size(h));
    printf("Number of customers in hashtable: %zu\n", hashtable_get_number_of_customers(h));
    printf("Number of collisions: %lu\n", hashtable_get_num_collisions(h));
    printf("Max size of a chain: %zu\n", hashtable_get_max_chain_size(h));
    printf("Average collisions: %.2f\n", hashtable_get_avg_collisions(h));
    printf("Number of empty hashtable chains: %zu\n", hashtable_get_num_empty(h));

    printf("\nRemoving customer A2 from hashtable...\n");
    hashtable_remove(h, "A2") == SUCCESS ? printf("SUCCESS\n") : printf("FAILURE\n");
    printf("Removed Customer A2\n");
    printf("Hashtable size: %zu\n", hashtable_size(h));
    printf("Number of customers in hashtable: %zu\n", hashtable_get_number_of_customers(h));
    hashtable_print(h);

    // Destroy hashtable
    printf("\nDestroying hashtable...\n");
    hashtable_destroy(h);

    // Destroy customers
    for(int i = 0; i < 10; i++)
        customer_destroy(customers[i]);
    free(customers);

    return 0;
}