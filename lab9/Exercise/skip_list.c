#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "skip_list.h"

/*############## Helper functions ##################*/
int coin_flip(float p){
    double flip = (double)rand() / (double)RAND_MAX;
    if(flip < p) return 0;
    else return 1;
}

int calculate_level(float p){
    int level=1;
    while(coin_flip(p)==1 && level<MAX_LEVEL) level++;
    return level;
}

//function to print a skiplist
void skip_list_print(SkipList *list){
    SLNode *cur = list->head;
    while(cur!=NULL){
        printf("%p: ",cur);
        for(int i=0;i<cur->level;i++)
            printf("(%2d,%p)",cur->key,cur->forward[i]);
        printf("\n");
        cur = cur->forward[0];
    }
    printf("\n");
}

/*############## Node functions ##################*/
SLNode *skip_list_node_init(int key, int max_level){
    SLNode *node = malloc(sizeof(SLNode));
    node->key = key;
    node->level = 1;
    node->forward = malloc(sizeof(SLNode*)*max_level);
    for(int i=0;i<max_level;i++) node->forward[i]=NULL;
    return node;
}

/*############## Skiplist functions ##################*/

//Function to create a skiplist
SkipList *skip_list_init(float p, int max_level){
    SkipList *list = malloc(sizeof(SkipList));
    list->head=skip_list_node_init(INT_MIN,max_level);
    list->p = p;
    list->max_level = max_level;
    return list;
}

//Function to insert a new key to the skiplist
SkipList *skip_list_insert(SkipList *list,int key){
    /* EXERCISE */

    //1. Iterate through the list starting from the top level
    //Every time a NULL or value greater than the key is found drop by a level
    if(list->head==NULL ){
        list->head=skip_list_node_init(key, list->max_level);
        return list;
    }
    SLNode * current=list->head;
    SLNode ** previous=malloc(sizeof(SLNode)*list->head->level);
    int level=list->head->level;
    while(level>0){
        if(current->forward[level-1]==NULL || current->forward[level-1]->key>key){
           previous[level-1]=current;
            level--;

        }
        else{
            
            current=current->forward[level-1];
            
        }

    }

    SLNode * newnode=skip_list_node_init(key, list->max_level);
    int newlevel=calculate_level(list->p);
    int updatedlevel=newlevel;
    int currentlevel=list->head->level;

    if(newlevel>currentlevel){
        updatedlevel=currentlevel;
        for(int i=currentlevel;i<level;i++){
            list->head->forward[i]=newnode;
        }
        list->head->level=newlevel;
    }
    for(int i=0;i<updatedlevel;i++){
        newnode->forward[i]=previous[i]->forward[i];;
        previous[i]->forward[i]=newnode;
    }
    newnode->level=newlevel;
    free(previous);

    //2. We must also maintain an array of pointers for the "previous" nodes in the skiplist

    //3. Create a new node and fix the node level
    
   

    return list;
}

//Function to check if item exists in skiplist
int skip_list_search(SkipList *list, int key){
    /* EXERCISE */
    if(list->head==NULL){
        return 0;
    }

    SLNode * current=list->head;
    SLNode ** previous=malloc(sizeof(SLNode)*list->head->level);
    int level=list->head->level;
    while(level>0){
        if(current->forward[level-1]==NULL || current->forward[level-1]->key>key){
           previous[level-1]=current;
            level--;

        }
        else if(current->forward[level-1]->key==key){
            return 1;
        }
        else{
            
            current=current->forward[level-1];
            
        }

    }
    //1. Iterate through the list starting from the top level
    //Every time a NULL or value greater than the key is found drop by a level

    //2. Take one step to the right. We either find the value we are looking for or not
    return 0;
}

//Function to destroy a skiplist
void skip_list_destroy(SkipList *list){
    /* EXERCISE */
    free(list->head->forward);
    free(list->head);
    free(list);

}


