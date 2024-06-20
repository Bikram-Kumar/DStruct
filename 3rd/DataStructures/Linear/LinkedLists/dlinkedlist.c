
#include "dlinkedlist.h"



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





void dlinked_list_add(DLinkedList* this, DLinkedList* ll, int val) {
    init_dlinked_list(ll);
    ll->val = val;
    while (this->next != NULL) {
        this = this->next;
    }
    this->next = ll;
    ll->prev = this;
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

int dlinked_list_size(DLinkedList* this) {
    int size = 0;
    
    while (this != NULL) {
        this = this->next;
        size++;
    }
    return size;
}

