#ifndef CODE_HASHTABLE_H
#define CODE_HASHTABLE_H

#include <stdio.h>

#define HASHTABLE_SIZE 101
# define MAX_LOAD_FACTOR 0.75

enum status {SUCCESS, FAILURE};
typedef enum status STATUS;

#include "./customer/customer.h"

typedef struct hashtable Hashtable;

Hashtable* hashtable_create(size_t size);
void hashtable_destroy(Hashtable* h);
size_t hashtable_size(Hashtable* h);
Hashtable* hashtable_insert(Hashtable* h, Customer* c);
STATUS hashtable_remove(Hashtable* h, char* id);
Customer* hashtable_get(Hashtable* h, char* id);
size_t hashtable_hash(Hashtable* h, char* id);
void hashtable_print(Hashtable* h);
Hashtable* hashtable_with_default_size();
size_t hashtable_get_max_chain_size(Hashtable* h);
size_t hashtable_get_num_collisions(Hashtable* h);
double hashtable_get_avg_collisions(Hashtable* h);
size_t hashtable_get_num_empty(Hashtable* h);
size_t hashtable_get_number_of_customers(Hashtable* h);
size_t hashtable_get_max_list_size(Hashtable* h);
size_t next_prime(size_t n);
Hashtable* hashtable_resize(Hashtable* h);
float hashtable_get_load_factor(Hashtable* h);

#endif //CODE_HASHTABLE_H
