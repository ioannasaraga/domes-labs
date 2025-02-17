#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "skip_list.h"

int main(){
    srand(time(NULL));
    SkipList *list = skip_list_init(0.5,MAX_LEVEL);
    list = skip_list_insert(list,3);
    list = skip_list_insert(list,6);
    list = skip_list_insert(list,2);
    list = skip_list_insert(list,8);
    list = skip_list_insert(list,11);
    list = skip_list_insert(list,9);
    list = skip_list_insert(list,5);
    list = skip_list_insert(list,4);
    list = skip_list_insert(list,20);

    skip_list_print(list);
    printf("%d %d %d %d\n", skip_list_search(list,2),skip_list_search(list,8),skip_list_search(list,11),skip_list_search(list,7));
    skip_list_destroy(list);
}

