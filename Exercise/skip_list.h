#ifndef K08_DEV_SKIP_LIST_H
#define K08_DEV_SKIP_LIST_H

#define MAX_LEVEL 5

typedef struct skip_list_node{
    int key;
    int level;
    struct skip_list_node **forward;
}SLNode;

typedef struct skip_list{
    SLNode *head;
    float p;
    int max_level;
}SkipList;

/*############## Helper functions ##################*/
int coin_flip(float p);
int calculate_level(float p);
void skip_list_print(SkipList *list);

/*############## Node functions ##################*/
//Function to create a new node
SLNode *skip_list_node_init(int key, int max_level);
//Function to set the level of a new node based on coin flips
SLNode *skip_list_node_fix_level(SLNode *node, SLNode **previous, SkipList **list, int cur_level);

/*############## Skiplist functions ##################*/

//Function to create a skiplist
SkipList *skip_list_init(float p, int max_level);
//Function to insert a new key to the skiplist
SkipList *skip_list_insert(SkipList *list,int key);
//Function to check if item exists in skiplist
int skip_list_search(SkipList *list,int key);
//Function to destroy a skiplist
void skip_list_destroy(SkipList *list);


#endif //K08_DEV_SKIP_LIST_H
