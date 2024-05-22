
#pragma once

#include <stddef.h>

typedef struct {
    int val;
    struct LinkedList* next;
} LinkedList;

typedef struct {} DoublyLinkedList;

void init_linked_list(LinkedList*);
