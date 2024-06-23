
#include "linkedlist.h"

LinkedList* init_linkedlist(LinkedList* this) {
    this->val = 0;
    this->next = NULL;
    this->add = &linkedlist_add;
    this->insert = &linkedlist_insert;
    this->remove = &linkedlist_remove;
    this->find = &linkedlist_find;
    this->size = &linkedlist_size;
    return this;
}



// adds the value to the list
// ll is an uninitialized LinkedList*, pass malloc(sizeof(LinkedList))

void linkedlist_add(LinkedList* this, LinkedList* ll, int val) {
    init_linkedlist(ll);
    ll->val = val;
    while (this->next != NULL) {
        this = this->next;
    }
    this->next = ll;
}



// inserts the value in the list at given index
void linkedlist_insert(LinkedList* this, LinkedList* ll, int index, int val) {
    if (index > this->size(this)) return;
    
    init_linkedlist(ll);
    ll->val = val;
    for (int i = 0; i < index-1; i++) {
        this = this->next;
    }
    ll->next = this->next;
    this->next = ll;
}





// removes the element at given index
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

