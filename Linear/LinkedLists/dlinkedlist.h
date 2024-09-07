#pragma once

#include <stdlib.h>

   

// DoublyLinkedList
typedef struct DLinkedList {
    
    struct DLinkedList* prev;
    int val;
    struct DLinkedList* next;

    
    // adds node to the end of list
    void (*push_back) (struct DLinkedList* this, struct DLinkedList* node);

    // adds node to the front of list
    void (*push_front) (struct DLinkedList* this, struct DLinkedList* node);

    // inserts the node right next to this node in the list
    void (*insert_next) (struct DLinkedList* this, struct DLinkedList* node);

    // inserts the node in the list at given index
    void (*insert) (struct DLinkedList* this, struct DLinkedList* node, int index);

    // removes the node at given index
    void (*remove) (struct DLinkedList* this, int index);

    // removes this->next from the list
    void (*remove_next) (struct DLinkedList* this);

    // finds first match and returns its index
    int (*find) (struct DLinkedList*, int num);

    // returns number of elements in the list
    int (*size) (struct DLinkedList* this);

    // frees this and all next nodes
    void (*destroy) (struct DLinkedList* this);
        
} DLinkedList;


   
DLinkedList* create_dlinkedlist(int val);

void dlinkedlist_push_back(DLinkedList* this, DLinkedList* node);
void dlinkedlist_push_front(DLinkedList* this, DLinkedList* node);
void dlinkedlist_insert_next(DLinkedList* this, DLinkedList* node);
void dlinkedlist_insert(DLinkedList* this, DLinkedList* node, int index);
void dlinkedlist_remove(DLinkedList* this, int index);
void dlinkedlist_remove_next (DLinkedList* this);
int dlinkedlist_find(DLinkedList* this, int num);

int dlinkedlist_size(DLinkedList* this);

void destroy_dlinkedlist(DLinkedList* this);

void destroy_dlinkedlist_prev(DLinkedList* this);
void destroy_dlinkedlist_next(DLinkedList* this);
