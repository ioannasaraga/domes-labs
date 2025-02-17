#ifndef CODE_LIST_H
#define CODE_LIST_H

#include "../customer/customer.h"

typedef struct list List;

int list_size(List *l);
List *list_first(List *l);
List* list_last(List* l);
void list_free(List* l);
void list_print(List *l);
List *list_get_next(List *l);
List *list_merge(List *l1,List *l2);
int list_sum(List * l);
List* list_copy(List * l);

// Customer methods

List *list_push(List *l, Customer* customer);
Customer* list_get_customer(List *l);
Customer* list_search(List *l, char* id);
List * list_delete_customer(List* l, char* id);
List *list_prepend(List *l, Customer* customer);

#endif //CODE_LIST_H
