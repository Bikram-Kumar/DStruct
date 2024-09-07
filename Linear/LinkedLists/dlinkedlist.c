
#include "dlinkedlist.h"


// Allocate a new DLinkedList Node and return its pointer
DLinkedList* create_dlinkedlist(int val) {
    DLinkedList* this = malloc(sizeof(DLinkedList));

    this->prev = NULL;
    this->val = val;
    this->next = NULL;
    this->push_back = &dlinkedlist_push_back;
    this->push_front = &dlinkedlist_push_front;
    this->insert = &dlinkedlist_insert;
    this->insert_next = &dlinkedlist_insert_next;
    this->remove = &dlinkedlist_remove;
    this->remove_next = &dlinkedlist_remove_next;
    this->find = &dlinkedlist_find;
    this->size = &dlinkedlist_size;
    this->destroy = &destroy_dlinkedlist;
    return this;
}





// adds node to the end of list
void dlinkedlist_push_back(DLinkedList* this, DLinkedList* node) {
    while (this->next != NULL) {
        this = this->next;
    }
    this->next = node;
    node->prev = this;
}


// Adds `node` to the front of list. Return `node`.
DLinkedList* dlinkedlist_push_front(DLinkedList* this, DLinkedList* node) {
    while (this->prev != NULL) {
        this = this->prev;
    }
    this->prev = node;
    node->next = this;
    return node;
}




// inserts the node right next to this node in the list
void dlinkedlist_insert_next(DLinkedList* this, DLinkedList* node) {

    node->next = this->next;
    this->next->prev = node;
    this->next = node;
    node->prev = this;
}



// inserts the node in the list at given index
void dlinkedlist_insert(DLinkedList* this, DLinkedList* node, int index) {
    if (index > this->size(this)) return;
    
    for (int i = 0; i < index-1; i++) {
        this = this->next;
    }
    
    node->next = this->next;
    this->next->prev = node;
    this->next = node;
    node->prev = this;
}


// Removes the node at given index. If index is 0, `this` will be updated to `this->next`
void dlinkedlist_remove(DLinkedList* this, int index) {
    int size = this->size(this);
    if (size < index) return;
    
    if (index == 0) {
        this->next->prev = NULL;
        this->val = this->next->val;
        this->next = this->next->next;
        return;
    }
    
   
    for (int i = 0; i < index; i++) {
        this = this->next;
    }
    
    this->prev->next = this->next;
    if (this->next == NULL) return;
    this->next->prev = this->prev;
    free(this);
    
}



// removes `this->next` from the list
void dlinkedlist_remove_next (DLinkedList* this) {

    DLinkedList* next = this->next;
    this->next = next->next;
    this->next->prev = this;
    free(next);    

}


// finds first match and returns its index
int dlinkedlist_find(DLinkedList* this, int num) {
    int size = this->size(this);
    
    for (int i = 0; i < size; i++) {
        if (this->val == num) {
            return i;
        }
        this = this->next;
    }
    
    return -1;

}


// returns number of elements in the list
int dlinkedlist_size(DLinkedList* this) {
    int size = 0;
    
    while (this != NULL) {
        this = this->next;
        size++;
    }
    return size;
}




// destroy `this` and all `prev` nodes
void destroy_dlinkedlist_prev(DLinkedList* this) {
    if (this->prev != NULL) {
        destroy_dlinkedlist_prev(this->prev);
    }

    free(this);
}




// destroy `this` and all `next` nodes
void destroy_dlinkedlist_next(DLinkedList* this) {
    if (this->next != NULL) {
        destroy_dlinkedlist_next(this->next);
    }

    free(this);
}




// frees `this` and all `prev` and `next` nodes from memory
void destroy_dlinkedlist(DLinkedList* this) {

    destroy_dlinkedlist_prev(this->prev);
    destroy_dlinkedlist_next(this->next);

    free(this);
    
}

