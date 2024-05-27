
#include "linked_list.h"

LinkedList* init_linked_list(LinkedList* this) {
    this->val = 0;
    this->next = NULL;
    this->add = &linked_list_add;
    this->insert = &linked_list_insert;
    this->remove = &linked_list_remove;
    this->find = &linked_list_find;
    this->size = &linked_list_size;
    return this;
}


DLinkedList* init_dlinked_list(DLinkedList* this) {
    this->prev = NULL;
    this->val = 0;
    this->next = NULL;
    this->add = &dlinked_list_add;
    this->insert = &dlinked_list_insert;
    this->remove = &dlinked_list_remove;
    this->find = &dlinked_list_find;
    this->size = &dlinked_list_size;
    return this;
}


// adds the value to the list
// ll is an uninitialized LinkedList*, pass malloc(sizeof(LinkedList))

void linked_list_add(LinkedList* this, LinkedList* ll, int val) {
    init_linked_list(ll);
    ll->val = val;
    while (this->next != NULL) {
        this = this->next;
    }
    this->next = ll;
}


void dlinked_list_add(DLinkedList* this, DLinkedList* ll, int val) {
    init_dlinked_list(ll);
    ll->val = val;
    while (this->next != NULL) {
        this = this->next;
    }
    this->next = ll;
    ll->prev = this;
}



// inserts the value in the list at given index
void linked_list_insert(LinkedList* this, LinkedList* ll, int index, int val) {
    if (index > this->size(this)) return;
    
    init_linked_list(ll);
    ll->val = val;
    for (int i = 0; i < index-1; i++) {
        this = this->next;
    }
    ll->next = this->next;
    this->next = ll;
}


void dlinked_list_insert(DLinkedList* this, DLinkedList* ll, int index, int val) {
    if (index > this->size(this)) return;
    
    init_dlinked_list(ll);
    ll->val = val;
    for (int i = 0; i < index-1; i++) {
        this = this->next;
    }
    
    ll->next = this->next;
    this->next->prev = ll;
    this->next = ll;
    ll->prev = this;
}




// removes the element at given index
void linked_list_remove(LinkedList* this, int index) {
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


void dlinked_list_remove(DLinkedList* this, int index) {
    int size = this->size(this);
    if (size < index) return;
    
    if (index == 0) {
        this->next->prev = NULL;
        this->val = this->next->val;
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
    
}






// finds first match and returns its index
int linked_list_find(LinkedList* this, int num) {
    int size = this->size(this);
    
    for (int i = 0; i < size; i++) {
        if (this->val == num) {
            return i;
        }
        this = this->next;
    }
    
    return -1;

}



int dlinked_list_find(DLinkedList* this, int num) {
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
int linked_list_size(LinkedList* this) {
    int size = 0;
    
    while (this != NULL) {
        this = this->next;
        size++;
    }
    return size;
}




int dlinked_list_size(DLinkedList* this) {
    int size = 0;
    
    while (this != NULL) {
        this = this->next;
        size++;
    }
    return size;
}



