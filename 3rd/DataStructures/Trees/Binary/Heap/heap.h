#pragma once

#include "btree.h"


// Max Binary Heap
typedef struct Heap {
    BTree* btree;
    
    int (*get_val) (struct Heap*);
    void (*set_val) (struct Heap*, int val);
    
    struct Heap* (*get_parent) (struct Heap*);
    
    struct Heap* (*get_left) (struct Heap*);
    void (*set_left) (struct Heap*, struct Heap*);
    
    struct Heap* (*get_right) (struct Heap*);
    void (*set_right) (struct Heap*, struct Heap*);
    
    struct Heap* (*get_root) (struct Heap*);
    
    // the node with which the new node will be parented 
    struct Heap* (*get_last_parent) (struct Heap*);
    
    void (*sift_up) (struct Heap*);
    void (*sift_down) (struct Heap*);
    
    // push node into heap and return the new root
    struct Heap* (*push) (struct Heap*, struct Heap*);
    
    int (*get_size) (struct Heap*);
    
    void (*traverse_bfs) (struct Heap*, struct Heap**);
    void (*traverse_pre) (struct Heap*, struct Heap**);
    void (*traverse_in) (struct Heap*, struct Heap**);
    void (*traverse_post) (struct Heap*, struct Heap**);
    
    void (*swap_with_parent) (struct Heap*);
    
    void (*destroy) (struct Heap*);
    
} Heap;


Heap* create_heap(int val);

int heap_get_val(Heap*);
void heap_set_val(Heap*, int);

Heap* heap_get_parent(Heap*);

void heap_set_left(Heap*, Heap*);
Heap* heap_get_left(Heap*);

void heap_set_right(Heap*, Heap*);
Heap* heap_get_right(Heap*);

Heap* heap_get_root(Heap*);
Heap* heap_get_last_parent(Heap*);

void heap_sift_up(Heap*);
void heap_sift_down(Heap*);

Heap* heap_push(Heap*, Heap*);
    
int heap_get_size(Heap*);

void heap_traverse_bfs(Heap*, Heap**);
void heap_traverse_pre(Heap*, Heap**);
void heap_traverse_in(Heap*, Heap**);
void heap_traverse_post(Heap*, Heap**);

void heap_swap_with_parent(Heap*);

void destroy_heap(Heap*);

