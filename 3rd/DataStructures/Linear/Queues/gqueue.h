#pragma once

#include <stdlib.h>


// Generic Queue
typedef struct GQueue {
    void** arr; // stores pointer data of any type
    int front;
    int capacity;
    int size;
    int (*enqueue) (struct GQueue*, void*);
    void* (*dequeue) (struct GQueue*);
    void* (*peek) (struct GQueue*);
    void (*destroy) (struct GQueue*);
} GQueue;

GQueue* create_gqueue (int);
int gqueue_enqueue (GQueue*, void*);
void* gqueue_dequeue (GQueue*);
void* gqueue_peek (GQueue*);
void gqueue_destroy (GQueue*);


