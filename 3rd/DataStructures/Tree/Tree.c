
#include "tree.h"


Tree* create_tree(int val, int degree) {
    Tree* this = malloc(sizeof(Tree));
    this->val = val;
    this->parent = NULL;
    this->children = malloc(sizeof(Tree*) * degree);
    this->degree = degree;
    this->size = degree + 1;
    this->set_child = &tree_set_child;
    this->traverse_bfs = &tree_traverse_bfs;
    this->traverse_pre = &tree_traverse_pre;
    this->traverse_post = &tree_traverse_post;
    this->destroy = &destroy_tree;
    return this;
}




void tree_set_child(Tree* this, int index, Tree* child) {
    this->children[index] = child;
    child->parent = this;
    this->size += child->degree;
}



void tree_traverse_bfs(Tree* this, Tree** arr) {
    
    int count = 0;
    
    GQueue* q = init_gqueue(malloc(sizeof(GQueue)), this->size - 1);
    
    
    Tree* node;
    q->enqueue(q, this);
    
    while (q->size > 0) {
        
        node = q->dequeue(q);
        
        for (int i = 0; i < node->degree; i++) {
            q->enqueue(q, node->children[i]);
        }
        
        arr[count] = node;
        count++;
    }
    
    q->destroy(q);
    
    
}


void tree_traverse_pre(Tree* this, Tree** arr) {
    
    
    int count = 0;
    
    GStack* s = init_gstack(malloc(sizeof(GStack)), this->size - 1);
    
    
    Tree* node;
    s->push(s, this);
    
    while (s->top > 0) {
        
        node = s->pop(s);
        
        for (int i = node->degree-1; i >= 0; i--) {
            s->push(s, node->children[i]);
        }
        
        arr[count] = node;
        count++;
    }
    
    s->destroy(s);
    
    
}



void tree_traverse_post(Tree* this, Tree** arr) {
    
    int count = 0;
    tree_traverse_post_add_children(this, arr, &count);
    
}



void tree_traverse_post_add_children (Tree* this, Tree** arr, int* count) {
    
    if (this->degree == 0) {
        arr[*count] = this;
        (*count)++;
        return;
    }
    
    for (int i = 0; i < this->degree; i++) {
        tree_traverse_post_add_children(this->children[i], arr, count);
    }
    
    arr[*count] = this;
    (*count)++;
    
}



void destroy_tree(Tree* this) {
    
    for (int i = 0; i < this->degree; i++) {
        destroy_tree(this->children[i]);
    }
    
    free(this);
}





BinaryTree* create_binary_tree (int val) {
    BinaryTree* this = malloc(sizeof(BinaryTree));
    this->val = val;
    this->parent = NULL;
    this->left = NULL;
    this->right = NULL;
    this->set_left = &binary_tree_set_left;
    this->set_right = &binary_tree_set_right;
    this->get_size = &binary_tree_get_size;
    this->traverse_bfs = &binary_tree_traverse_bfs;
    this->traverse_pre = &binary_tree_traverse_pre;
    this->traverse_in = &binary_tree_traverse_in;
    this->traverse_post = &binary_tree_traverse_post;
    this->destroy = &destroy_binary_tree;
    
    return this;
}


void binary_tree_set_left(BinaryTree* this, BinaryTree* left) {
    
    this->left = left;
    left->parent = this;
    
}



void binary_tree_set_right(BinaryTree* this, BinaryTree* right) {
    
    this->right = right;
    right->parent = this;
    
}



int binary_tree_get_size(BinaryTree* t) {
    if (t == NULL) return 0;
   
    return (1 + binary_tree_get_size(t->left) + binary_tree_get_size(t->right));
}






void binary_tree_traverse_bfs(BinaryTree* this, BinaryTree** arr) {
    
    int count = 0;
    
    GQueue* q = init_gqueue(malloc(sizeof(GQueue)), this->get_size(this) - 1);
    
    
    BinaryTree* node;
    q->enqueue(q, this);
    
    while (q->size > 0) {
        
        node = q->dequeue(q);
        
        if (node->left != NULL) q->enqueue(q, node->left);
        if (node->right != NULL) q->enqueue(q, node->right);
    
        
        arr[count] = node;
        count++;
    }
    
    q->destroy(q);
    
    
}





void binary_tree_traverse_pre (BinaryTree* this, BinaryTree** arr) {
    
    int count = 0;
    
    GStack* s = init_gstack(malloc(sizeof(GStack)), this->get_size(this) - 1);
    
    
    BinaryTree* node;
    s->push(s, this);
    
    while (s->top > 0) {
        
        node = s->pop(s);
        
        if (node->right != NULL) s->push(s, node->right);
        if (node->left != NULL) s->push(s, node->left);
    
        
        arr[count] = node;
        count++;
    }
    
    s->destroy(s);
    
    
}






void binary_tree_traverse_in_add (BinaryTree* this, BinaryTree** arr, int* count) {
    
    if (this == NULL) return;
    binary_tree_traverse_in_add(this->left, arr, count);
    arr[*count] = this;
    (*count)++;
    binary_tree_traverse_in_add(this->right, arr, count);
    
}


void binary_tree_traverse_in(BinaryTree* this, BinaryTree** arr) {
    int count = 0;
    binary_tree_traverse_in_add(this, arr, &count);
}



void binary_tree_traverse_post_add (BinaryTree* this, BinaryTree** arr, int* count) {
    
    if (this == NULL) return;
    binary_tree_traverse_post_add(this->left, arr, count);
    binary_tree_traverse_post_add(this->right, arr, count);
    arr[*count] = this;
    (*count)++;
    
}


void binary_tree_traverse_post(BinaryTree* this, BinaryTree** arr) {
    int count = 0;
    binary_tree_traverse_post_add(this, arr, &count);
}



void destroy_binary_tree(BinaryTree* this) {
    if (this == NULL) return;
    
    destroy_binary_tree(this->left);
    destroy_binary_tree(this->right);
    free(this);
}