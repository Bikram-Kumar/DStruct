
#include "linked_list.h"

void init_linked_list(LinkedList* ll) {
    ll->val = 0;
    ll->next = NULL;
    ll->add = &linked_list_add;
    ll->insert = &linked_list_insert;
    ll->remove = &linked_list_remove;
    ll->find = &linked_list_find;
    ll->size = &linked_list_size;
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


// returns number of elements in the list
int linked_list_size(LinkedList* this) {
    int size = 0;
    
    while (this != NULL) {
        this = this->next;
        size++;
    }
    return size;
}



