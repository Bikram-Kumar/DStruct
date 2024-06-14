
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




BinarySearchTree* create_binary_search_tree(int val) {
    BinarySearchTree* this = malloc(sizeof(BinarySearchTree));
    
    this->btree = create_binary_tree(val);
    this->btree->attached = this;
    
    this->get_val = &binary_search_tree_get_val;
    this->set_val = &binary_search_tree_set_val;
    this->get_parent = &binary_search_tree_get_parent;
    this->get_left = &binary_search_tree_get_left;
    this->set_left = &binary_search_tree_set_left;
    this->get_right = &binary_search_tree_get_right;
    this->set_right = &binary_search_tree_set_right;
    this->add_to_tree = &binary_search_tree_add_to_tree;
    this->traverse_bfs = &binary_search_tree_traverse_bfs;
    this->traverse_pre = &binary_search_tree_traverse_pre;
    this->traverse_in = &binary_search_tree_traverse_in;
    this->traverse_post = &binary_search_tree_traverse_post;
    this->get_size = &binary_search_tree_get_size;
    this->destroy = &destroy_binary_search_tree;
    
    return this;
}


int binary_search_tree_get_val(BinarySearchTree* this) {
    return this->btree->val;
}

void binary_search_tree_set_val(BinarySearchTree* this, int val) {
    this->btree->val = val;
}

BinarySearchTree* binary_search_tree_get_parent (BinarySearchTree* this) {
    if (this->btree->parent == NULL) return NULL;
    return this->btree->parent->attached;
}

BinarySearchTree* binary_search_tree_get_left (BinarySearchTree* this) {
    if (this->btree->left == NULL) return NULL;
    return this->btree->left->attached;
}

void binary_search_tree_set_left (BinarySearchTree* this, BinarySearchTree* left) {
    this->btree->set_left(this->btree, left->btree);
}

BinarySearchTree* binary_search_tree_get_right (BinarySearchTree* this) {
    if (this->btree->right == NULL) return NULL;
    return this->btree->right->attached;
}

void binary_search_tree_set_right (BinarySearchTree* this, BinarySearchTree* right) {
    this->btree->set_right(this->btree, right->btree);
}



void binary_search_tree_add_to_tree (BinarySearchTree* this, BinarySearchTree* child) {
    
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




void binary_search_tree_traverse_bfs(BinarySearchTree* this, BinarySearchTree** arr) {
    int size = this->get_size(this);
    BinaryTree** barr = malloc(sizeof(BinaryTree*) * size);
    this->btree->traverse_bfs(this->btree, barr);
    
    for (int i = 0; i < size; i++) {
        arr[i] = barr[i]->attached;
    }
    
    free(barr);
}


void binary_search_tree_traverse_pre(BinarySearchTree* this, BinarySearchTree** arr) {
    int size = this->get_size(this);
    BinaryTree** barr = malloc(sizeof(BinaryTree*) * size);
    this->btree->traverse_pre(this->btree, barr);
    
    for (int i = 0; i < size; i++) {
        arr[i] = barr[i]->attached;
    }
    
    free(barr);
}

void binary_search_tree_traverse_in(BinarySearchTree* this, BinarySearchTree** arr) {
    int size = this->get_size(this);
    BinaryTree** barr = malloc(sizeof(BinaryTree*) * size);
    this->btree->traverse_in(this->btree, barr);
    
    for (int i = 0; i < size; i++) {
        arr[i] = barr[i]->attached;
    }
    
    free(barr);
}

void binary_search_tree_traverse_post(BinarySearchTree* this, BinarySearchTree** arr) {
    int size = this->get_size(this);
    BinaryTree** barr = malloc(sizeof(BinaryTree*) * size);
    this->btree->traverse_post(this->btree, barr);
    
    for (int i = 0; i < size; i++) {
        arr[i] = barr[i]->attached;
    }
    
    free(barr);
}




int binary_search_tree_get_size (BinarySearchTree* this) {
    
    return this->btree->get_size(this->btree);
    
}



void destroy_binary_search_tree(BinarySearchTree* this) {
    
    if (this == NULL) return;
        
    this->destroy(this->get_left(this));
    this->destroy(this->get_right(this));
    
    
    free(this->btree);
    free(this);
}