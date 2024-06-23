#include "bstree.h"


BSTree* create_bstree(int val) {
    BSTree* this = malloc(sizeof(BSTree));
    
    this->btree = create_btree(val);
    this->btree->attached = this;
    
    this->get_val = &bstree_get_val;
    this->set_val = &bstree_set_val;
    this->get_parent = &bstree_get_parent;
    this->get_left = &bstree_get_left;
    this->set_left = &bstree_set_left;
    this->get_right = &bstree_get_right;
    this->set_right = &bstree_set_right;
    this->add_to_tree = &bstree_add_to_tree;
    this->traverse_bfs = &bstree_traverse_bfs;
    this->traverse_pre = &bstree_traverse_pre;
    this->traverse_in = &bstree_traverse_in;
    this->traverse_post = &bstree_traverse_post;
    this->get_size = &bstree_get_size;
    this->destroy = &destroy_bstree;
    
    return this;
}


int bstree_get_val(BSTree* this) {
    return this->btree->val;
}

void bstree_set_val(BSTree* this, int val) {
    this->btree->val = val;
}

BSTree* bstree_get_parent (BSTree* this) {
    if (this->btree->parent == NULL) return NULL;
    return this->btree->parent->attached;
}

BSTree* bstree_get_left (BSTree* this) {
    if (this->btree->left == NULL) return NULL;
    return this->btree->left->attached;
}

void bstree_set_left (BSTree* this, BSTree* left) {
    this->btree->set_left(this->btree, left->btree);
}

BSTree* bstree_get_right (BSTree* this) {
    if (this->btree->right == NULL) return NULL;
    return this->btree->right->attached;
}

void bstree_set_right (BSTree* this, BSTree* right) {
    this->btree->set_right(this->btree, right->btree);
}



void bstree_add_to_tree (BSTree* this, BSTree* child) {
    
    if (this->btree->val > child->btree->val) {
        if (this->get_left(this) == NULL) {
            this->set_left(this, child);
        } else {
            this->add_to_tree(this->get_left(this), child);
        }
    } else {
        if (this->get_right(this) == NULL) {
            this->set_right(this, child);
        } else {
            this->add_to_tree(this->get_right(this), child);
        }
    }
    
    
}




void bstree_traverse_bfs(BSTree* this, BSTree** arr) {
    int size = this->get_size(this);
    BTree** barr = malloc(sizeof(BTree*) * size);
    this->btree->traverse_bfs(this->btree, barr);
    
    for (int i = 0; i < size; i++) {
        arr[i] = barr[i]->attached;
    }
    
    free(barr);
}


void bstree_traverse_pre(BSTree* this, BSTree** arr) {
    int size = this->get_size(this);
    BTree** barr = malloc(sizeof(BTree*) * size);
    this->btree->traverse_pre(this->btree, barr);
    
    for (int i = 0; i < size; i++) {
        arr[i] = barr[i]->attached;
    }
    
    free(barr);
}

void bstree_traverse_in(BSTree* this, BSTree** arr) {
    int size = this->get_size(this);
    BTree** barr = malloc(sizeof(BTree*) * size);
    this->btree->traverse_in(this->btree, barr);
    
    for (int i = 0; i < size; i++) {
        arr[i] = barr[i]->attached;
    }
    
    free(barr);
}

void bstree_traverse_post(BSTree* this, BSTree** arr) {
    int size = this->get_size(this);
    BTree** barr = malloc(sizeof(BTree*) * size);
    this->btree->traverse_post(this->btree, barr);
    
    for (int i = 0; i < size; i++) {
        arr[i] = barr[i]->attached;
    }
    
    free(barr);
}




int bstree_get_size (BSTree* this) {
    
    return this->btree->get_size(this->btree);
    
}



void destroy_bstree(BSTree* this) {
    
    if (this == NULL) return;
        
    this->destroy(this->get_left(this));
    this->destroy(this->get_right(this));
    
    
    free(this->btree);
    free(this);
}