#ifndef CODE_HASHTABLE_H
#define CODE_HASHTABLE_H

#include <stdio.h>
#include "./customer/customer.h"

typedef struct bloom_filter{
    unsigned char *array;
    unsigned int size;
}BloomFilter;

unsigned int h1(BloomFilter *bf,char *id);
unsigned int h2(BloomFilter *bf,char *id);
unsigned int h3(BloomFilter *bf,char *id);
BloomFilter *bloom_filter_create(unsigned int size);
void bloom_filter_set_bit(BloomFilter *bf,unsigned int hash);
unsigned int bloom_filter_get_bit(BloomFilter *bf,unsigned int hash);
void bloom_filter_insert(BloomFilter *bf,Customer *c);
int bloom_filter_check(BloomFilter *bf,Customer *c);
void bloom_filter_destroy(BloomFilter *bf);

#endif //CODE_HASHTABLE_H
