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

   


typedef struct BinaryTree {
    int val;
    struct BinaryTree* parent;
    struct BinaryTree* left;
    struct BinaryTree* right;
    
    void (*set_left) (struct BinaryTree*, struct BinaryTree*);
    void (*set_right) (struct BinaryTree*, struct BinaryTree*);
    int (*get_size) (struct BinaryTree*);
    void (*traverse_bfs) (struct BinaryTree*, struct BinaryTree**);
    void (*traverse_pre) (struct BinaryTree*, struct BinaryTree**);
    void (*traverse_in) (struct BinaryTree*, struct BinaryTree**);
    void (*traverse_post) (struct BinaryTree*, struct BinaryTree**);
    
    void (*destroy) (struct BinaryTree*);
    
} BinaryTree;


BinaryTree* create_binary_tree(int);

void binary_tree_set_left (BinaryTree*, BinaryTree*);
void binary_tree_set_right (BinaryTree*, BinaryTree*);
int binary_tree_get_size (BinaryTree*);
void binary_tree_traverse_bfs (BinaryTree*, BinaryTree**);
void binary_tree_traverse_pre (BinaryTree*, BinaryTree**);
void binary_tree_traverse_in (BinaryTree*, BinaryTree**);
void binary_tree_traverse_post (BinaryTree*, BinaryTree**);
void destroy_binary_tree (BinaryTree*);


// util functions
void binary_tree_traverse_in_add (BinaryTree*, BinaryTree**, int*); 
void binary_tree_traverse_post_add (BinaryTree*, BinaryTree**, int*); 




typedef struct {int val;} BinarySearchTree;
typedef struct {int val;} ThreadedBinaryTree;
typedef struct {int val;} Heap;
typedef struct {int val;} AVLTree;