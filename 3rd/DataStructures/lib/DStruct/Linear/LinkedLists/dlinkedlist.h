#pragma once

#include <stddef.h>

   

// DoublyLinkedList
typedef struct DLinkedList {
    
    struct DLinkedList* prev;
    int val;
    struct DLinkedList* next;
    
    void (*add) (struct DLinkedList*, struct DLinkedList*, int);
    void (*insert) (struct DLinkedList*, struct DLinkedList*, int, int);
    void (*remove) (struct DLinkedList*, int);
    int (*find) (struct DLinkedList*, int);
    
    int (*size) (struct DLinkedList*);
    
} DLinkedList;



DLinkedList* init_dlinkedlist(DLinkedList*);

void dlinkedlist_add(DLinkedList*,DLinkedList*,int);
void dlinkedlist_insert(DLinkedList*,DLinkedList*,int,int);
void dlinkedlist_remove(DLinkedList*,int);
int dlinkedlist_find(DLinkedList*,int);

int dlinkedlist_size(DLinkedList*);
   

