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

typedef struct {int val;} DoublyLinkedList;

void init_linked_list(LinkedList*);

void linked_list_add(LinkedList*,LinkedList*,int);
void linked_list_insert(LinkedList*,LinkedList*,int,int);
void linked_list_remove(LinkedList*,int);
int linked_list_find(LinkedList*,int);

int linked_list_size(LinkedList*);
   

