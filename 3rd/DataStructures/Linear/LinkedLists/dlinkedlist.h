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



DLinkedList* init_dlinked_list(DLinkedList*);

void dlinked_list_add(DLinkedList*,DLinkedList*,int);
void dlinked_list_insert(DLinkedList*,DLinkedList*,int,int);
void dlinked_list_remove(DLinkedList*,int);
int dlinked_list_find(DLinkedList*,int);

int dlinked_list_size(DLinkedList*);
   

