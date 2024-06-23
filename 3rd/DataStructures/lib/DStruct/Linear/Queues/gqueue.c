#include "gqueue.h"





GQueue* create_gqueue (int cap) {
    GQueue* this = malloc(sizeof(GQueue));
    this->arr = malloc(sizeof(void*) * cap);
    this->front = 0;
    this->capacity = cap;
    this->size = 0;
    this->enqueue = &gqueue_enqueue;
    this->dequeue = &gqueue_dequeue;
    this->peek = &gqueue_peek;
    this->destroy = &gqueue_destroy;
    return this;
}


// returns -1 if gqueue is full, else the number of elements in gqueue
int gqueue_enqueue (GQueue* this, void* val) {
    
    if (this->size == this->capacity) return -1;
    
    int offset = (this->front + this->size) % this->capacity;
    *(this->arr + offset) = val;

    return (++this->size);
}


// returns NULL if gqueue is empty, else the front element
void* gqueue_dequeue (GQueue* this) {
    
    if (this->size == 0) return NULL;
    
    void* val =  *(this->arr + this->front);
    
    this->front++;
    if (this->front == this->capacity) {
        this->front = 0;
    }
    
    this->size--;
    return val;
}


// returns NULL if gqueue is empty, else the front element without removing it
void* gqueue_peek (GQueue* this) {
    
    if (this->size == 0) return NULL;
    
    return *(this->arr + this->front);
}

void gqueue_destroy (GQueue* this) {
    free(this->arr);
    free(this);
}


