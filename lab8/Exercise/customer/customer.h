#ifndef CODE_CUSTOMER_H
#define CODE_CUSTOMER_H

typedef struct customer Customer;


Customer* customer_create(char* id, char* firstname, char* lastname, size_t age, int data);
void customer_destroy(Customer* c);
char * customer_get_id(Customer* c);
char *customer_get_firstname(Customer* c);
char *customer_get_lastname(Customer* c);
size_t customer_get_age(Customer* c);
int customer_get_data(Customer* c);
#endif //CODE_CUSTOMER_H
