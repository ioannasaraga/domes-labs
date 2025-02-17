#include <stdlib.h>
#include <limits.h>
#include "list.h"
#include "acutest/acutest.h"

void test_list_push(){
    List *l = NULL;
    l = list_push(l,1);
    l = list_push(l,2);
    l = list_push(l,3);

    TEST_CHECK(list_size(l)==3 && list_get_data(list_first(l)) == 1 && list_get_data(list_last(l)) == 3);

    list_free(l);
}

//FUNCTIONS - LAB EXERCISE

void test_list_prepend(){

    List *l=NULL;
    l=list_push(l,2);
    l=list_push(l,3);
    l=list_prepend(l,1);
    TEST_CHECK(1 > 0);
    TEST_CHECK(list_size(l)==3 && list_get_data(list_first(l)) == 1 && list_get_data(list_last(l)) == 3);
}

void test_list_add_after(){
    List *l = NULL;
    l = list_push(l,1);
    l = list_push(l,3);
    l=list_add_after_first(l,2);
    
    TEST_CHECK(1 > 0);
    TEST_CHECK(list_size(l)==3 && list_get_data(list_first(l)) == 1 && list_get_data(list_last(l)) == 3);
}

void test_list_merge(){
    List *l = NULL;
    l = list_push(l,1);
    l = list_push(l,2);
   

    List *l2 = NULL;
    l2 = list_push(l2,3);
    l=list_merge(l,l2);
    TEST_CHECK(list_size(l)==3 && list_get_data(list_first(l)) == 1 && list_get_data(list_last(l)) == 3);
    
    TEST_CHECK(1 > 0);
}

TEST_LIST = {
        { "test_list_push", test_list_push  },
        { "test_list_prepend",  test_list_prepend  }, //EXERCISE
        { "test_list_add_after",  test_list_add_after  }, // EXERCISE
        { "test_list_merge",  test_list_merge  }, // EXERCISE
        { NULL, NULL } /* zeroed record marking the end of the list */
};
