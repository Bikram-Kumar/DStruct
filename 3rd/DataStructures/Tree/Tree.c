
#include "tree.h"


Tree* init_tree(Tree* this, int val, int degree) {
    this->val = val;
    this->parent = NULL;
    this->children = malloc(sizeof(Tree*) * degree);
    this->degree = degree;
    this->size = degree + 1;
    this->set_child = &tree_set_child;
    this->traverse_bfs = &tree_traverse_bfs;
    this->traverse_pre = &tree_traverse_pre;
    this->traverse_post = &tree_traverse_post;
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








BinaryTree* create_binary_tree (int val) {
    BinaryTree* this = malloc(sizeof(BinaryTree));
    this->val = val;
    this->parent = NULL;
    this->left = NULL;
    this->right = NULL;
    this->get_size = &binary_tree_get_size;
    this->traverse_bfs = &binary_tree_traverse_bfs;
    this->traverse_pre = &binary_tree_traverse_pre;
    this->traverse_in = &binary_tree_traverse_in;
    this->traverse_post = &binary_tree_traverse_post;
    
    return this;
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


