#include "btree.h"

BTree* create_btree (int val) {
    BTree* this = malloc(sizeof(BTree));
    this->val = val;
    this->parent = NULL;
    this->left = NULL;
    this->right = NULL;
    this->set_left = &btree_set_left;
    this->set_right = &btree_set_right;
    this->get_size = &btree_get_size;
    this->get_root = &btree_get_root;
    this->traverse_bfs = &btree_traverse_bfs;
    this->traverse_pre = &btree_traverse_pre;
    this->traverse_in = &btree_traverse_in;
    this->traverse_post = &btree_traverse_post;
    this->swap_with_parent = &btree_swap_with_parent;
    this->destroy = &destroy_btree;
    
    return this;
}



void btree_set_left(BTree* this, BTree* left) {
    
    this->left = left;
    if (left != NULL) left->parent = this;
    
}



void btree_set_right(BTree* this, BTree* right) {
    
    this->right = right;
    if (right != NULL) right->parent = this;
    
}


BTree* btree_get_root(BTree* this) {
    
    if (this->parent == NULL) return this;
    return btree_get_root(this->parent);
    
}

int btree_get_size(BTree* t) {
    if (t == NULL) return 0;
   
    return (1 + btree_get_size(t->left) + btree_get_size(t->right));
}






void btree_traverse_bfs(BTree* this, BTree** arr) {
    
    int count = 0;
    
    GQueue* q = create_gqueue(this->get_size(this));
    
    
    BTree* node;
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





void btree_traverse_pre (BTree* this, BTree** arr) {
    
    int count = 0;
    
    GStack* s = create_gstack(this->get_size(this));
    
    
    BTree* node;
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






void btree_traverse_in_add (BTree* this, BTree** arr, int* count) {
    
    if (this == NULL) return;
    btree_traverse_in_add(this->left, arr, count);
    arr[*count] = this;
    (*count)++;
    btree_traverse_in_add(this->right, arr, count);
    
}


void btree_traverse_in(BTree* this, BTree** arr) {
    int count = 0;
    btree_traverse_in_add(this, arr, &count);
}



void btree_traverse_post_add (BTree* this, BTree** arr, int* count) {
    
    if (this == NULL) return;
    btree_traverse_post_add(this->left, arr, count);
    btree_traverse_post_add(this->right, arr, count);
    arr[*count] = this;
    (*count)++;
    
}


void btree_traverse_post(BTree* this, BTree** arr) {
    int count = 0;
    btree_traverse_post_add(this, arr, &count);
}



void btree_swap_with_parent(BTree* this) {
    // temp values
    BTree* parent = this->parent;
    BTree* left = this->left;
    BTree* right = this->right;
    
    if (parent->parent == NULL) {
        this->parent = NULL;
    } else if (parent->parent->left == parent) {
        btree_set_left(parent->parent, this);
    } else {
        btree_set_right(parent->parent, this);
    }
    
    if (parent->left == this) {
        this->set_left(this, parent);
        this->set_right(this, parent->right);
    } else {
        this->set_right(this, parent);
        this->set_left(this, parent->left);
    }
    
    parent->set_left(parent, left);
    parent->set_right(parent, right);
    
    
}





void destroy_btree(BTree* this) {
    if (this == NULL) return;
    
    destroy_btree(this->left);
    destroy_btree(this->right);
    free(this);
}

