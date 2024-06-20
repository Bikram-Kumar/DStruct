#include "queue.h"

Queue* create_queue (int cap) {
    Queue* this = malloc(sizeof(Queue));
    this->arr = malloc(sizeof(int) * cap);
    this->front = 0;
    this->capacity = cap;
    this->size = 0;
    this->enqueue = &queue_enqueue;
    this->dequeue = &queue_dequeue;
    this->peek = &queue_peek;
    this->destroy = &queue_destroy;
    return this;
}


// returns -1 if queue is full, else the number of elements in queue
int queue_enqueue (Queue* this, int val) {
    
    if (this->size == this->capacity) return -1;
    
    int offset = (this->front + this->size) % this->capacity;
    *(this->arr + offset) = val;

    return (++this->size);
}


// returns -1 if queue is empty, else the front element
int queue_dequeue (Queue* this) {
    
    if (this->size == 0) return -1;
    
    int val =  *(this->arr + this->front);
    
    this->front++;
    if (this->front == this->capacity) {
        this->front = 0;
    }
    
    this->size--;
    return val;
}


// returns -1 if queue is empty, else the front element without removing it
int queue_peek (Queue* this) {
    
    if (this->size == 0) return -1;
    
    return *(this->arr + this->front);
}

void queue_destroy (Queue* this) {
    free(this->arr);
    free(this);
}



