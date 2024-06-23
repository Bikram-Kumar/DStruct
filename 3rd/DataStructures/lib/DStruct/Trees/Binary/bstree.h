#pragma once

#include "btree.h"

typedef struct BSTree {
    BTree* btree;
    int (*get_val) (struct BSTree*);
    void (*set_val) (struct BSTree*, int val);
    
    struct BSTree* (*get_parent) (struct BSTree*);
    
    struct BSTree* (*get_left) (struct BSTree*);
    void (*set_left) (struct BSTree*, struct BSTree*);
    
    struct BSTree* (*get_right) (struct BSTree*);
    void (*set_right) (struct BSTree*, struct BSTree*);
    
    void (*add_to_tree) (struct BSTree*, struct BSTree*);
    int (*get_size) (struct BSTree*);
    
    void (*traverse_bfs) (struct BSTree*, struct BSTree**);
    void (*traverse_pre) (struct BSTree*, struct BSTree**);
    void (*traverse_in) (struct BSTree*, struct BSTree**);
    void (*traverse_post) (struct BSTree*, struct BSTree**);
    
    void (*destroy) (struct BSTree*);
    
} BSTree;


BSTree* create_bstree(int val);

int bstree_get_val(BSTree*);
void bstree_set_val(BSTree*, int);

BSTree* bstree_get_parent(BSTree*);

void bstree_set_left(BSTree*, BSTree*);
BSTree* bstree_get_left(BSTree*);

void bstree_set_right(BSTree*, BSTree*);
BSTree* bstree_get_right(BSTree*);

void bstree_add_to_tree(BSTree*, BSTree*);
    
int bstree_get_size(BSTree*);

void bstree_traverse_bfs(BSTree*, BSTree**);
void bstree_traverse_pre(BSTree*, BSTree**);
void bstree_traverse_in(BSTree*, BSTree**);
void bstree_traverse_post(BSTree*, BSTree**);

void destroy_bstree(BSTree*);
