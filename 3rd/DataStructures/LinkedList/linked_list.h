#pragma once

#include <stddef.h>

typedef struct LinkedList {
    int val;
    struct LinkedList* next;
    
    void (*add) (struct LinkedList*, struct LinkedList*, int);
    void (*insert) (struct LinkedList*, struct LinkedList*, int, int);
    void (*remove) (struct LinkedList*, int);
    int (*find) (struct LinkedList*, int);
    
    int (*size) (struct LinkedList*);
    
} LinkedList;


void init_linked_list(LinkedList*);

void linked_list_add(LinkedList*,LinkedList*,int);
void linked_list_insert(LinkedList*,LinkedList*,int,int);
void linked_list_remove(LinkedList*,int);
int linked_list_find(LinkedList*,int);

int linked_list_size(LinkedList*);
   
   
   
   

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



void init_dlinked_list(DLinkedList*);

void dlinked_list_add(DLinkedList*,DLinkedList*,int);
void dlinked_list_insert(DLinkedList*,DLinkedList*,int,int);
void dlinked_list_remove(DLinkedList*,int);
int dlinked_list_find(DLinkedList*,int);

int dlinked_list_size(DLinkedList*);
   


