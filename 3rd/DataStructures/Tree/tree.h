#pragma once

#include <stddef.h>
#include <stdlib.h>
#include "../Arrays/arrays.h"


typedef struct Tree {
    int val;
    struct Tree* parent;
    struct Tree** children;
    int degree; // num of children
    int size;
    void (*set_child) (struct Tree*, int, struct Tree*);
    void (*traverse_bfs) (struct Tree*, struct Tree**);
    void (*traverse_pre) (struct Tree*);
    void (*traverse_post) (struct Tree*);
} Tree;

Tree* init_tree (Tree*, int, int);
void tree_set_child (Tree*, int, Tree*);
void tree_traverse_bfs (Tree*, Tree**);
void tree_traverse_pre (Tree*);
void tree_traverse_post (Tree*);



typedef struct {int val;} BinaryTree;
typedef struct {int val;} BinarySearchTree;
typedef struct {int val;} ThreadedBinaryTree;
typedef struct {int val;} Heap;
typedef struct {int val;} AVLTree;