#include <stdio.h>
#include <stdlib.h>

typedef struct list List;
struct list{
    int data;
    List *next;
};

List *list_push(List *l, int data){
    List *node = malloc(sizeof(List));
    node->next = NULL;
    node->data = data;

    if(l==NULL){
        l = node;
    }
    else{
        List *cur = l;
        while(cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = node;
    }

    return l;
}

List *list_first(List *l){
    return l;
}

List* list_last(List* l){
    if (l == NULL)
        return l;

    while (l->next != NULL) {
        l = l->next;
    }
    return l;
}

void list_free(List* l){
    List* cur = NULL;
    while (l != NULL) {
        cur = l->next;
        free(l);
        l = cur;
    }
}

void list_print(List *l){
    List *cur = l;
    printf("[");
    while(cur!=NULL){
        if(cur->next!=NULL){
            printf("%d, ",cur->data);
        }
        else{
            printf("%d",cur->data);
        }
        cur = cur->next;
    }
    printf("]\n");
}

int list_size(List *l){
    List *cur = l;
    int count = 0;
    while(cur!=NULL){
        count++;
        cur = cur->next;
    }
    return count;
}

int list_get_data(List *l){
    return l->data;
}

List *list_get_next(List *l){
    return l->next;
}

List *list_prepend(List *l,int data){
    List *node = malloc(sizeof(List));
    node->next=l;
    node->data=data;
    return node;
}
List *list_add_after_first(List *l,int data){
    List *newnode = malloc(sizeof(List));

    newnode->data=data;
    newnode->next=NULL;
    if(l==NULL){
        return newnode;
    }
    List *temp=l->next;
    l->next=newnode;
    newnode->next=temp;
    return l;
}
List *list_merge(List *l1,List *l2){
    List *temp=NULL;
    temp=l1;
    while(temp->next!=NULL){
         temp=temp->next;
    }
   temp->next=l2;
   return l1;

}
