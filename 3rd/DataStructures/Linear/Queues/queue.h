#pragma once

#include <stdlib.h>


// Queue for int
typedef struct Queue {
    int* arr; 
    int front;
    int capacity;
    int size;
    int (*enqueue) (struct Queue*, int);
    int (*dequeue) (struct Queue*);
    int (*peek) (struct Queue*);
    void (*destroy) (struct Queue*);
} Queue;

Queue* create_queue (int);
int queue_enqueue (Queue*, int);
int queue_dequeue (Queue*);
int queue_peek (Queue*);
void queue_destroy (Queue*);


