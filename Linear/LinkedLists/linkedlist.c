
#include "linkedlist.h"

LinkedList* create_linkedlist(int val) {
    LinkedList* this = malloc(sizeof(LinkedList));
    this->val = val;
    this->next = NULL;
    this->add = &linkedlist_add;
    this->insert = &linkedlist_insert;
    this->insert_next = &linkedlist_insert_next;
    this->remove = &linkedlist_remove;
    this->remove_next = &linkedlist_remove_next;
    this->find = &linkedlist_find;
    this->size = &linkedlist_size;
    this->destroy = &destroy_linked_list;
    return this;
}



// adds node to the list
void linkedlist_add(LinkedList* this, LinkedList* node) {
    while (this->next != NULL) {
        this = this->next;
    }
    this->next = node;
}




// inserts the node right next to this node in the list
void linkedlist_insert_next(LinkedList* this, LinkedList* node) {

    node->next = this->next;
    this->next = node;
}



// inserts the node in the list at given index
void linkedlist_insert(LinkedList* this, LinkedList* node, int index) {
    if (index > this->size(this)) return;
    
    for (int i = 0; i < index-1; i++) {
        this = this->next;
    }
    node->next = this->next;
    this->next = node;
}





// removes the node at given index
void linkedlist_remove(LinkedList* this, int index) {
    int size = this->size(this);
    if (size < index) return;
    
    if (index == 0) {
        this->val = this->next->val;
        this->next = this->next->next;
        return;
    }
    
   
    LinkedList* prev;
    for (int i = 0; i < index; i++) {
        prev = this;
        this = this->next;
    }
    
    prev->next = this->next;
    
}




// removes this->next from the list
void linkedlist_remove_next (LinkedList* this) {

    LinkedList* next = this->next;
    this->next = this->next->next;
    free(next);    

}







// finds first match and returns its index
int linkedlist_find(LinkedList* this, int num) {
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
int linkedlist_size(LinkedList* this) {
    int size = 0;
    
    while (this != NULL) {
        this = this->next;
        size++;
    }
    return size;
}


// frees this and all next nodes
void destroy_linked_list(LinkedList* this) {
    
    if (this->next != NULL) {
        destroy_linked_list(this->next);
    }

    free(this);
    
}


