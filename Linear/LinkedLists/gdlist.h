#pragma once

#include <stdlib.h>

   

// Generic Doubly Linked List
typedef struct GDList {
    
    struct GDList* prev;
    void* val;
    struct GDList* next;

    
    // adds node to the end of list
    void (*push_back) (struct GDList* this, struct GDList* node);

    // Adds `node` to the front of list. Return `node` which is the new head of list
    struct GDList* (*push_front) (struct GDList* this, struct GDList* node);

    // inserts the node right next to this node in the list
    void (*insert_next) (struct GDList* this, struct GDList* node);

    // inserts the node in the list at given index
    void (*insert) (struct GDList* this, struct GDList* node, int index);

    // removes the node at given index
    void (*remove) (struct GDList* this, int index);

    // removes this->next from the list
    void (*remove_next) (struct GDList* this);

    // finds first match and returns its index
    int (*find) (struct GDList*, void* val);

    // returns number of elements in the list
    int (*size) (struct GDList* this);

    // frees this and all next nodes
    void (*destroy) (struct GDList* this);
        
} GDList;


   
GDList* create_gdlist(void* val);

void gdlist_push_back(GDList* this, GDList* node);
GDList* gdlist_push_front(GDList* this, GDList* node);
void gdlist_insert_next(GDList* this, GDList* node);
void gdlist_insert(GDList* this, GDList* node, int index);
void gdlist_remove(GDList* this, int index);
void gdlist_remove_next (GDList* this);
int gdlist_find(GDList* this, void* val);

int gdlist_size(GDList* this);

void destroy_gdlist(GDList* this);

void destroy_gdlist_prev(GDList* this);
void destroy_gdlist_next(GDList* this);
