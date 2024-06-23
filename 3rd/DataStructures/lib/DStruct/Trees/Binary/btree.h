#pragma once

#include <stdlib.h>
#include "gstack.h"
#include "gqueue.h"

// Binary Tree
typedef struct BTree {
    int val;
    struct BTree* parent;
    struct BTree* left;
    struct BTree* right;
    
    // this property can be used to attach other structs with this one
    void* attached; 
    
    void (*set_left) (struct BTree*, struct BTree*);
    void (*set_right) (struct BTree*, struct BTree*);
    int (*get_size) (struct BTree*);
    struct BTree* (*get_root) (struct BTree*);
    void (*traverse_bfs) (struct BTree*, struct BTree**);
    void (*traverse_pre) (struct BTree*, struct BTree**);
    void (*traverse_in) (struct BTree*, struct BTree**);
    void (*traverse_post) (struct BTree*, struct BTree**);
    void (*swap_with_parent) (struct BTree*);
    
    void (*destroy) (struct BTree*);
    
    
} BTree;


BTree* create_btree(int);

void btree_set_left (BTree*, BTree*);
void btree_set_right (BTree*, BTree*);
int btree_get_size (BTree*);
BTree* btree_get_root(BTree*);
void btree_traverse_bfs (BTree*, BTree**);
void btree_traverse_pre (BTree*, BTree**);
void btree_traverse_in (BTree*, BTree**);
void btree_traverse_post (BTree*, BTree**);
void btree_swap_with_parent (BTree*);
void destroy_btree (BTree*);


// util functions
void btree_traverse_in_add (BTree*, BTree**, int*); 
void btree_traverse_post_add (BTree*, BTree**, int*); 

