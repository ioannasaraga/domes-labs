#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "list.h"
#include "../customer/customer.h"

struct list{
    Customer* customer;
    List *next;
};

//Function to add an element at the end of the list
List *list_push(List *l, Customer* c){

    List *node = malloc(sizeof(List));
    node->next = NULL;
    node->customer = c;

    if(l==NULL)
        l = node;
    else{
        List *cur = l;
        while(cur->next!=NULL)
            cur = cur->next;
        cur->next = node;
    }

    return l;
}

//Function to return the size of a list
int list_size(List *l){
    List *cur = l;
    int count = 0;
    while(cur!=NULL){
        count++;
        cur = cur->next;
    }
    return count;
}

//Function to return the first element of the list
List *list_first(List *l){
    return l;
}

//Function to return the last element of a list
List* list_last(List* l){
    if (l == NULL)
        return l;

    while (l->next != NULL) {
        l = l->next;
    }
    return l;
}

//Function de-allocate a list
void list_free(List* l){
    List* cur = NULL;
    while (l != NULL) {
        cur = l->next;
        free(l);
        l = cur;
    }
}

//Helper function to print a list
void list_print(List *l){
    List *cur = l;
    printf("[");
    while(cur!=NULL){
        if(cur->next!=NULL){
            printf("%s, ", customer_get_id(list_get_customer(cur)));
        }
        else{
            printf("%s", customer_get_id(list_get_customer(cur)));
        }
        cur = cur->next;
    }
    printf("]\n");
}

//Function to return the record from a node
Customer* list_get_customer(List *l){
    return l->customer;
}

//Function to return the next node in the list
List *list_get_next(List *l){
    return l->next;
}

//Function to add an element at the start of the list
List *list_prepend(List *l, Customer* customer) {
    List *node = malloc(sizeof(List));
    node->customer = customer;
    node->next = l;

    return node;
}

List * list_delete_customer(List* l, char* id) {
    List* cur = l;
    List* prev = NULL;
    while (cur != NULL) {
        if (strcmp(customer_get_id(list_get_customer(cur)), id) == 0) {
            if (prev == NULL) {
                List* next = cur->next;
                free(cur);
                return next;
            } else {
                prev->next = cur->next;
                free(cur);
                return l;
            }
        }
        prev = cur;
        cur = cur->next;
    }
    return l;
}

Customer* list_search(List *l, char* id) {
    List* cur = l;
    while (cur != NULL) {
        if (strcmp(customer_get_id(list_get_customer(cur)), id) == 0)
            return list_get_customer(cur);
        cur = cur->next;
    }
    return NULL;
}
