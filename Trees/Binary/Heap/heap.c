
#include "heap.h"


Heap* create_heap(int val) {
    Heap* this = malloc(sizeof(Heap));
    
    this->btree = create_btree(val);
    this->btree->attached = this;
    
    this->get_val = &heap_get_val;
    this->set_val = &heap_set_val;
    this->get_parent = &heap_get_parent;
    this->get_left = &heap_get_left;
    this->set_left = &heap_set_left;
    this->get_right = &heap_get_right;
    this->set_right = &heap_set_right;
    this->get_size = &heap_get_size;
    this->get_root = &heap_get_root;
    this->get_last_parent = &heap_get_last_parent;
    this->sift_up = &heap_sift_up;
    this->sift_down = &heap_sift_down;
    this->push = &heap_push;
    this->traverse_bfs = &heap_traverse_bfs;
    this->traverse_pre = &heap_traverse_pre;
    this->traverse_in = &heap_traverse_in;
    this->traverse_post = &heap_traverse_post;
    this->swap_with_parent = &heap_swap_with_parent;
    this->destroy = &destroy_heap;
    
    return this;
}


int heap_get_val(Heap* this) {
    return this->btree->val;
}

void heap_set_val(Heap* this, int val) {
    this->btree->val = val;
}

Heap* heap_get_parent (Heap* this) {
    if (this->btree->parent == NULL) return NULL;
    return this->btree->parent->attached;
}




Heap* heap_get_left (Heap* this) {
    if (this->btree->left == NULL) return NULL;
    return this->btree->left->attached;
}

void heap_set_left (Heap* this, Heap* left) {
    this->btree->set_left(this->btree, left->btree);
}

Heap* heap_get_right (Heap* this) {
    if (this->btree->right == NULL) return NULL;
    return this->btree->right->attached;
}

void heap_set_right (Heap* this, Heap* right) {
    this->btree->set_right(this->btree, right->btree);
}


void heap_sift_up (Heap* this) {
 
    // heap condition satisfied, return
    if ((this->btree->parent == NULL) || (this->btree->parent->val >= this->btree->val)) return;
    
    
    heap_swap_with_parent(this);
        
    heap_sift_up(this);
    
}


void heap_sift_down (Heap* this) {
    Heap* max = this;
 
    if ((this->btree->left != NULL) && (this->btree->left->val > max->btree->val))     max = this->btree->left->attached;
    if ((this->btree->right != NULL) && (this->btree->right->val > max->btree->val))     max = this->btree->right->attached;
    
    // heap condition satisfied, return
    if (max == this) return;
    
    heap_swap_with_parent(max);
    
    heap_sift_down(this);
    
}


Heap* heap_get_root (Heap* this) {
    return btree_get_root(this->btree)->attached;
}


Heap* heap_get_last_parent (Heap* this) {
    GQueue* q = create_gqueue(this->get_size(this));
    q->enqueue(q, this);
    Heap* node = this;
    
    while (1) {
        node = q->dequeue(q);
        if ((node->btree->left == NULL) || (node->btree->right == NULL)) break;
        q->enqueue(q, node->get_left(node));
        q->enqueue(q, node->get_right(node));
    }
    
    return node;
}



Heap* heap_push (Heap* this, Heap* child) {
    
    Heap* last = this->get_last_parent(this);
    if (last->get_left(last) == NULL) {
        last->set_left(last, child);
    } else {
        last->set_right(last, child);
    }
    
    child->sift_up(child);
    
    return this->get_root(this);
    
}




void heap_traverse_bfs(Heap* this, Heap** arr) {
    int size = this->get_size(this);
    BTree** barr = malloc(sizeof(BTree*) * size);
    this->btree->traverse_bfs(this->btree, barr);
    
    for (int i = 0; i < size; i++) {
        arr[i] = barr[i]->attached;
    }
    
    free(barr);
}


void heap_traverse_pre(Heap* this, Heap** arr) {
    int size = this->get_size(this);
    BTree** barr = malloc(sizeof(BTree*) * size);
    this->btree->traverse_pre(this->btree, barr);
    
    for (int i = 0; i < size; i++) {
        arr[i] = barr[i]->attached;
    }
    
    free(barr);
}

void heap_traverse_in(Heap* this, Heap** arr) {
    int size = this->get_size(this);
    BTree** barr = malloc(sizeof(BTree*) * size);
    this->btree->traverse_in(this->btree, barr);
    
    for (int i = 0; i < size; i++) {
        arr[i] = barr[i]->attached;
    }
    
    free(barr);
}

void heap_traverse_post(Heap* this, Heap** arr) {
    int size = this->get_size(this);
    BTree** barr = malloc(sizeof(BTree*) * size);
    this->btree->traverse_post(this->btree, barr);
    
    for (int i = 0; i < size; i++) {
        arr[i] = barr[i]->attached;
    }
    
    free(barr);
}




int heap_get_size (Heap* this) {
    
    return this->btree->get_size(this->btree);
    
}



void heap_swap_with_parent (Heap* this) {
    
    btree_swap_with_parent(this->btree);
    
}

void destroy_heap(Heap* this) {
    
    if (this == NULL) return;
        
    this->destroy(this->get_left(this));
    this->destroy(this->get_right(this));
    
    
    free(this->btree);
    free(this);
}





