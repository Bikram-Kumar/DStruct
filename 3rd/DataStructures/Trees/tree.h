#pragma once

#include <stdlib.h>
#include "gstack.h"
#include "gqueue.h"


typedef struct Tree {
    int val;
    struct Tree* parent;
    struct Tree** children;
    int degree; // num of children
    int size;
    void (*set_child) (struct Tree*, int, struct Tree*);
    void (*traverse_bfs) (struct Tree*, struct Tree**);
    void (*traverse_pre) (struct Tree*, struct Tree**);
    void (*traverse_post) (struct Tree*, struct Tree**);
    void (*destroy) (struct Tree*);
} Tree;

Tree* create_tree (int, int);
void tree_set_child (Tree*, int, Tree*);
void tree_traverse_bfs (Tree*, Tree**);
void tree_traverse_pre (Tree*, Tree**);
void tree_traverse_post (Tree*, Tree**);
void destroy_tree (Tree*);

void tree_traverse_post_add_children (Tree*, Tree**, int*); // util for tree_traverse_post







typedef struct {int val;} AVLTree;