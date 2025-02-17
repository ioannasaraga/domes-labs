#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "skip_list.h"
// Including the acutest.h library
#include "./acutest/acutest.h"


void test_skip_list_insert(void){
    srand(165798);
    SkipList *list = skip_list_init(0.5,MAX_LEVEL);
    list = skip_list_insert(list,3);
    list = skip_list_insert(list,6);
    list = skip_list_insert(list,2);
    list = skip_list_insert(list,8);
    list = skip_list_insert(list,11);
    list = skip_list_insert(list,9);
    list = skip_list_insert(list,5);

    //Check that the lowest level of the list is order
    int array[7] = {2,3,5,6,8,9,11};
    SLNode *cur = list->head->forward[0];
    for(int i=0;i<7;i++){
        TEST_CHECK(array[i] == cur->key);
        cur = cur->forward[0];
    }

    //check the levels of the list
    int levels[7] = {1,2,3,1,4,2,1};
    cur = list->head->forward[0];
    for(int i=0;i<7;i++){
        TEST_CHECK(levels[i] == cur->level);
        cur = cur->forward[0];
    }
    skip_list_destroy(list);
}

void test_skip_list_search(void){
    SkipList *list = skip_list_init(0.5,MAX_LEVEL);
    list = skip_list_insert(list,3);
    list = skip_list_insert(list,6);
    list = skip_list_insert(list,2);
    list = skip_list_insert(list,8);
    list = skip_list_insert(list,11);
    list = skip_list_insert(list,9);
    list = skip_list_insert(list,5);

    TEST_CHECK(skip_list_search(list,6)==1);
    TEST_CHECK(skip_list_search(list,2)==1);
    TEST_CHECK(skip_list_search(list,11)==1);
    TEST_CHECK(skip_list_search(list,7)==0);
    TEST_CHECK(skip_list_search(list,INT_MAX)==0);
    skip_list_destroy(list);
}

TEST_LIST = {
        { "test_skip_list_insert", test_skip_list_insert },
        { "test_skip_list_search",  test_skip_list_search },
        { NULL, NULL }
};
