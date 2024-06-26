
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
    
    GQueue* q = create_gqueue(this->size);
    
    
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
    
    GStack* s = create_gstack(this->size);
    
    
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



