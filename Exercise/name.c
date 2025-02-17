#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(void){
    char *name=malloc(MAX*sizeof(char));
    scanf("%s",name);
    printf("%s\n",name);
    free(name);
}