#include <stdio.h>
#include "swap.h"

int main(void){
    int a, a_bak, b, b_bak;
    a_bak = a = +12345;
    b_bak = b = -54321;

    swap(&a, &b);
    
    printf("%s\n", a_bak == b && b_bak == a ? "Correct!" : "Wrong!");
    printf("Before swap: a: %d, b: %d\n", a_bak, b_bak);
    printf("After swap:  a: %d, b: %d\n", a, b);
    return 0;
}

void swap(int *a, int *b){
    //Exercise

    return;
}