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


LinkedList* init_linkedlist(LinkedList*);

void linkedlist_add(LinkedList*,LinkedList*,int);
void linkedlist_insert(LinkedList*,LinkedList*,int,int);
void linkedlist_remove(LinkedList*,int);
int linkedlist_find(LinkedList*,int);

int linkedlist_size(LinkedList*);
   