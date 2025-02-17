#include <stdio.h>
#include "reverse.h"

int main(void){
    int num = 0x11223344;
    int rev_num = reverse_byte_order(num);
    int i, mask, sym_mask;
    char byte, sym_byte;

    for (i = 0; i < sizeof(int); i++){
        mask = 0xFF << 8*i;
        sym_mask = 0xFF << 8*(sizeof(int)-i-1);
        byte = (num & mask) >> 8*i;
        sym_byte = (rev_num & sym_mask) >> 8*(sizeof(int) - i - 1);
        if ((byte ^ sym_byte) != 0x00)
            break;
    }
    printf("%s\n", i < sizeof(int) ? "Wrong!" : "Correct!");
    printf("Number:          %.8x\n", num);
    printf("Reversed number: %.8x\n", rev_num);
}

int reverse_byte_order(int num){
    //Exercise

    return /*something else, delete the 0->*/0;
}