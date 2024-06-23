#pragma once

#include <stdlib.h>




typedef struct Deque {
    int* arr;
    int front;
    int capacity;
    int size;
    int (*push_front) (struct Deque*, int);
    int (*pop_front) (struct Deque*);
    int (*peek_front) (struct Deque*);
    int (*push_back) (struct Deque*, int);
    int (*pop_back) (struct Deque*);
    int (*peek_back) (struct Deque*);
    void (*destroy) (struct Deque*);
} Deque;

Deque* create_deque (int);
int deque_push_front (Deque*, int);
int deque_pop_front (Deque*);
int deque_peek_front (Deque*);
int deque_push_back (Deque*, int);
int deque_pop_back (Deque*);
int deque_peek_back (Deque*);
void deque_destroy (Deque*);

