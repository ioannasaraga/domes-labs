#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main(){
    Vector* v = vector_create(3);
     vector_push_back(v,1);
    return 0;
}
