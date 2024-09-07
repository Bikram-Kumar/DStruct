
#include "gdlist.h"


// Allocate a new GDList Node and return its pointer
GDList* create_gdlist(void* val) {
    GDList* this = malloc(sizeof(GDList));

    this->prev = NULL;
    this->val = val;
    this->next = NULL;
    this->push_back = &gdlist_push_back;
    this->push_front = &gdlist_push_front;
    this->insert = &gdlist_insert;
    this->insert_next = &gdlist_insert_next;
    this->remove = &gdlist_remove;
    this->remove_next = &gdlist_remove_next;
    this->find = &gdlist_find;
    this->size = &gdlist_size;
    this->destroy = &destroy_gdlist;
    return this;
}





// adds node to the end of list
void gdlist_push_back(GDList* this, GDList* node) {
    while (this->next != NULL) {
        this = this->next;
    }
    this->next = node;
    node->prev = this;
}


// Adds `node` to the front of list. Return `node`.
GDList* gdlist_push_front(GDList* this, GDList* node) {
    while (this->prev != NULL) {
        this = this->prev;
    }
    this->prev = node;
    node->next = this;
    return node;
}




// inserts the node right next to this node in the list
void gdlist_insert_next(GDList* this, GDList* node) {

    node->next = this->next;
    this->next->prev = node;
    this->next = node;
    node->prev = this;
}



// inserts the node in the list at given index
void gdlist_insert(GDList* this, GDList* node, int index) {
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
void gdlist_remove(GDList* this, int index) {
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
void gdlist_remove_next (GDList* this) {

    GDList* next = this->next;
    this->next = next->next;
    this->next->prev = this;
    free(next);    

}


// finds first match and returns its index
int gdlist_find(GDList* this, void* val) {
    int size = this->size(this);
    
    for (int i = 0; i < size; i++) {
        if (this->val == val) {
            return i;
        }
        this = this->next;
    }
    
    return -1;

}


// returns number of elements in the list
int gdlist_size(GDList* this) {
    int size = 0;
    
    while (this != NULL) {
        this = this->next;
        size++;
    }
    return size;
}




// destroy `this` and all `prev` nodes
void destroy_gdlist_prev(GDList* this) {
    if (this->prev != NULL) {
        destroy_gdlist_prev(this->prev);
    }

    free(this);
}




// destroy `this` and all `next` nodes
void destroy_gdlist_next(GDList* this) {
    if (this->next != NULL) {
        destroy_gdlist_next(this->next);
    }

    free(this);
}




// frees `this` and all `prev` and `next` nodes from memory
void destroy_gdlist(GDList* this) {

    destroy_gdlist_prev(this->prev);
    destroy_gdlist_next(this->next);

    free(this);
    
}

