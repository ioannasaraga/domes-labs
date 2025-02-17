#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "bloom_filter.h"
#include "./customer/customer.h"

int main() {
    BloomFilter *bf = bloom_filter_create(101);
    Customer *c1 = customer_create("A","Gaspar","Noé",59,125);
    Customer *c2 = customer_create("B","Panos","Cosmatos",49,268);

    bloom_filter_insert(bf,c1);
    if(bloom_filter_check(bf,c1)==1)
        printf("Customer might be in the bloom filter\n");
    else
        printf("Customer is definitely not in the bloom filter\n");

    if(bloom_filter_check(bf,c2)==1)
        printf("Customer might be in the bloom filter\n");
    else
        printf("Customer is definitely not in the bloom filter\n");
}