#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(){
    AVLTree *avl = NULL;

    avl = avl_insert(avl,10);
    avl = avl_insert(avl,20);
    avl = avl_insert(avl,30);
    avl = avl_insert(avl,40);
    avl = avl_insert(avl,50);
    avl = avl_insert(avl,25);
    avl = avl_insert(avl,5);
    avl = avl_insert(avl,15);
    avl = avl_insert(avl,0);

    avl_preorder(avl);

    avl_destroy(avl);
}
