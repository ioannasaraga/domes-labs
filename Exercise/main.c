#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    List *l = NULL;
    l = list_push(l,2);
    l = list_push(l,4);
    l = list_push(l,6);
    l = list_push(l,8);
    l = list_push(l,10);

   List *l2 = NULL;
    l2 = list_push(l2,5);
    l2 = list_prepend(l2,30);
    l2= list_add_after_first(l2,15);
    l2 = list_push(l2,20);
    l2 = list_push(l2,25);
    printf("The first element of the list is %d\n", list_get_data(list_first(l2)));
    printf("The last element of the list is %d\n", list_get_data(list_last(l2)));
    l=list_merge(l,l2);
    printf("The list is:\n");
    list_print(l);

    return 0;
}