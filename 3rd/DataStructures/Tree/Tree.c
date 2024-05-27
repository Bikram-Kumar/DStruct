
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


void tree_traverse_pre(Tree* this) {
    
    
    
    
    
}




void tree_traverse_post(Tree* this) {
    
    
    
    
    
}



