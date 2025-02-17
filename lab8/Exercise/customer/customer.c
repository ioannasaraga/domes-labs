#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "customer.h"

struct customer {
    char* id;
    char* firstname;
    char* lastname;
    size_t age;
    int data;
};

// Create a new customer
Customer* customer_create(char* id, char* firstname, char* lastname, size_t age, int data) {
    Customer* c = malloc(sizeof(Customer));
    c->id = strdup(id);
    c->firstname = strdup(firstname);
    c->lastname = strdup(lastname);
    c->age = age;
    c->data = data;
    return c;
}

// De-allocate a customer
void customer_destroy(Customer* c) {
    free(c->firstname);
    free(c->lastname);
    free(c->id);
    free(c);
}

// id getter
char * customer_get_id(Customer* c) {
    return c->id;
}

// firstname getter
char *customer_get_firstname(Customer* c) {
    return c->firstname;
}

// lastname getter
char *customer_get_lastname(Customer* c) {
    return c->lastname;
}

// age getter
size_t customer_get_age(Customer* c) {
    return c->age;
}

// data getter
int customer_get_data(Customer* c) {
    return c->data;
}

