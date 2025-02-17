#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "bloom_filter.h"
#include "./customer/customer.h"

/* -------- HASH FUNCTIONS --------*/

//DJB2 hash function
unsigned int h1(BloomFilter *bf,char *id){
    unsigned int hash = 5381;
    unsigned int c;

    while ((c = *id++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash%bf->size;
}

//SDBM hash function
unsigned int h2(BloomFilter *bf,char *id){
    unsigned int hash = 0;
    unsigned int c;

    while ((c = *id++))
        hash = c + (hash << 6) + (hash << 16) - hash;

    return hash%bf->size;
}

//simple hash function
unsigned int h3(BloomFilter *bf,char *id){
    unsigned int hash = 0;
    unsigned int c;

    while ((c = *id++))
        hash += c;   

    return hash%bf->size;
}
/*---------------------------------*/

//Function to create a bloom filter
BloomFilter *bloom_filter_create(unsigned int size){
    BloomFilter *bf = malloc(sizeof(BloomFilter));
    bf->array = malloc(size/8 + 1);
    memset(bf->array,0,size/8+1);
    bf->size = size;
    return bf;
}

//Helper functions for bit operations
void bloom_filter_set_bit(BloomFilter *bf,unsigned int hash){
    /* EXERCISE */

   int index=hash/8;
   int pos=hash%8;
   unsigned int mask= 1 << pos;
   bf->array[index]=bf->array[index] | mask;


}

unsigned int bloom_filter_get_bit(BloomFilter *bf,unsigned int hash){
    /* EXERCISE */


   int index=hash/8;
   int pos=hash%8;
   unsigned int mask=1 << pos;
   unsigned int value=bf->array[index] & mask;
    
    return value!=0;
}

//Function to insert a key into the bloom filter
void bloom_filter_insert(BloomFilter *bf,Customer *c){
    /* EXERCISE */

    unsigned int hash1=h1(bf, customer_get_id(c));
    bloom_filter_set_bit(bf, hash1);

    unsigned int hash2=h2(bf, customer_get_id(c));
    bloom_filter_set_bit(bf, hash2);

    unsigned int hash3=h3(bf, customer_get_id(c));
    bloom_filter_set_bit(bf, hash3);

}

//Function to check if a key might be in the bloom filter
int bloom_filter_check(BloomFilter *bf,Customer *c){
    /* EXERCISE */

    unsigned int hash1=h1(bf, customer_get_id(c));
    unsigned int value1= bloom_filter_get_bit(bf, hash1);

    unsigned int hash2=h2(bf, customer_get_id(c));
    unsigned int value2= bloom_filter_get_bit(bf, hash2);

    unsigned int hash3=h3(bf, customer_get_id(c));
    unsigned int value3= bloom_filter_get_bit(bf, hash3);


    if(value1==0 || value2==0 || value3==0){
        return 0;
    }
    else{
        return 1;
    }
}

//Function to destroy the bloom filter
void bloom_filter_destroy(BloomFilter *bf){
    /* EXERCISE */
    free(bf->array);
    free(bf);

}
