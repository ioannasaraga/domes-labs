#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "hashtable.h"
#include "./list/list.h"        
#include "./customer/customer.h"

struct hashtable {
    size_t size;
    List** table;
};

// Create a new hashtable with the specified size
Hashtable* hashtable_create(size_t size) {
    Hashtable *h = malloc(sizeof(Hashtable));
    h->size = size;
    h->table = malloc(sizeof(List*) * size);
    for (int i = 0; i < size; i++)
        h->table[i] = NULL;
    return h;
}

// Create a new hashtable with the default size
Hashtable* hashtable_with_default_size() {
    return hashtable_create(HASHTABLE_SIZE);
}

// De-allocate a hashtable
void hashtable_destroy(Hashtable* h) {
    for (int i = 0; i < hashtable_size(h); i++)
        list_free(h->table[i]);
    free(h->table);
    free(h);
}

// Hash function
size_t hashtable_hash(Hashtable* h, char* id) {
    /* EXERCISE */

    size_t hash = 0;
    for (size_t i = 0; id[i] != '\0'; ++i) {
        hash += (unsigned char)id[i];  
    }
    return hash % h->size;
    
}

// Insert a customer into the hashtable (if it doesn't already exist)
Hashtable* hashtable_insert(Hashtable* h, Customer* c) {
     /* EXERCISE */
    size_t index = hashtable_hash(h, customer_get_id(c));

    
    Customer *tmp = list_search(h->table[index], customer_get_id(c));
    if (tmp != NULL) {
        return h;  
    }

    
    h->table[index] = list_push(h->table[index], c);

    
    float check = hashtable_get_load_factor(h);
    if (check > 0.8) {
        h = hashtable_resize(h);  

        
        index = hashtable_hash(h, customer_get_id(c));
        h->table[index] = list_push(h->table[index], c);
    }

    return h;
}




// Resize the hashtable
Hashtable* hashtable_resize(Hashtable* h) {
    size_t new_size = 2 * h->size;
    h->size = new_size;
    h->table = (List**)realloc(h->table, new_size * sizeof(List*));

    
    for (size_t i = h->size / 2; i < h->size; i++) {
        h->table[i] = NULL;
    }

    return h;
}




// Get a customer from the hashtable
Customer* hashtable_get(Hashtable* h, char* id) {
    /* EXERCISE */
        size_t index = hashtable_hash(h, id);
    
    
    Customer *customer = list_search(h->table[index], id);
    
    return customer;
   
}

// Remove a customer from the hashtable

STATUS hashtable_remove(Hashtable* h, char* id) {
    
    size_t index = hashtable_hash(h, id);

    
    List* current_list = h->table[index];

    
    Customer* customer = list_search(current_list, id);
    if (customer == NULL) {
        return FAILURE;  
    }

  
    h->table[index] = list_delete_customer(current_list, id);
    customer_destroy(customer);
    
    return SUCCESS;  
}



/* 
    UTILITIES
*/

// Return the size of a hashtable
size_t hashtable_size(Hashtable* h) {
    return h->size;
}

// Print the hashtable
void hashtable_print(Hashtable* h) {
    printf("\nHashtable format:\n");
    for (int i = 0; i < hashtable_size(h); i++) {
        printf("%d: ", i);
        list_print(h->table[i]);
    }
}

float hashtable_get_load_factor(Hashtable* h) {
    return (float) hashtable_get_number_of_customers(h) / hashtable_size(h);
}

// First prime after n
size_t next_prime(size_t n) {
    size_t i = n + 1;
    while (1) {
        int is_prime = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime)
            return i;
        i++;
    }
}

// Get the maximum chain size
size_t hashtable_get_max_chain_size(Hashtable* h) {
    size_t max = 0;
    for (int i = 0; i < hashtable_size(h); i++) {
        size_t size = list_size(h->table[i]);
        if (size > max)
            max = size;
    }
    return max;
}

// Get the number of collisions
size_t hashtable_get_num_collisions(Hashtable* h) {
    size_t collisions = 0;
    for (int i = 0; i < hashtable_size(h); i++) {
        size_t size = list_size(h->table[i]);
        if (size > 1)
            collisions += size - 1;
    }
    return collisions;
}

// Get the average number of collisions
double hashtable_get_avg_collisions(Hashtable* h) {
    return (double) hashtable_get_num_collisions(h) / hashtable_size(h);
}

// Get the number of empty buckets
size_t hashtable_get_num_empty(Hashtable* h) {
    size_t empty = 0;
    for (int i = 0; i < hashtable_size(h); i++) {
        if (h->table[i] == NULL)
            empty++;
    }
    return empty;
}

// Get the number of customers
size_t hashtable_get_number_of_customers(Hashtable* h) {
    size_t num_of_customers = 0;
    for (int i = 0; i < hashtable_size(h); i++) 
        num_of_customers += list_size(h->table[i]);
    return num_of_customers;
}

// Get the maximum list size
size_t hashtable_get_max_list_size(Hashtable* h) {
    size_t max = 0;
    for (int i = 0; i < hashtable_size(h); i++) {
        size_t size = list_size(h->table[i]);
        if (size > max)
            max = size;
    }
    return max;
}


