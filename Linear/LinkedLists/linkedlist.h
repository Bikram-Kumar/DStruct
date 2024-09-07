#pragma once

#include <stdlib.h>

typedef struct LinkedList {
    int val;
    struct LinkedList* next;
    
    // adds node to the list
    void (*add) (struct LinkedList* this, struct LinkedList* node);

    // inserts the node right next to this node in the list
    void (*insert_next) (struct LinkedList* this, struct LinkedList* node);

    // inserts the node in the list at given index
    void (*insert) (struct LinkedList* this, struct LinkedList* node, int index);

    // removes the node at given index
    void (*remove) (struct LinkedList* this, int index);

    // removes this->next from the list
    void (*remove_next) (struct LinkedList* this);

    // finds first match and returns its index
    int (*find) (struct LinkedList*, int num);

    // returns number of elements in the list
    int (*size) (struct LinkedList* this);

    // frees this and all next nodes
    void (*destroy) (struct LinkedList* this);
    
} LinkedList;


LinkedList* create_linkedlist(int val);

void linkedlist_add(LinkedList* this, LinkedList* node);
void linkedlist_insert_next(LinkedList* this, LinkedList* node);
void linkedlist_insert(LinkedList* this, LinkedList* node, int index);
void linkedlist_remove(LinkedList* this, int index);
void linkedlist_remove_next (LinkedList* this);
int linkedlist_find(LinkedList* this, int num);

int linkedlist_size(LinkedList* this);
void destroy_linkedlist(LinkedList* this);
   