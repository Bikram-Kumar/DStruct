#pragma once

#include <stddef.h>

typedef struct {
    int val;
    struct LinkedList* next;
} LinkedList;

typedef struct {int val} DoublyLinkedList;

void init_linked_list(LinkedList*);
