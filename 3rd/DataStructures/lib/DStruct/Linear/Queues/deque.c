#include "deque.h"

Deque* create_deque (int cap) {
    Deque* this = malloc(sizeof(Deque));
    this->arr = malloc(sizeof(int) * cap);
    this->front = 0;
    this->capacity = cap;
    this->size = 0;
    this->push_front = &deque_push_front;
    this->pop_front = &deque_pop_front;
    this->peek_front = &deque_peek_front;
    this->push_back = &deque_push_back;
    this->pop_back = &deque_pop_back;
    this->peek_back = &deque_peek_back;
    this->destroy = &deque_destroy;
    return this;
}


// returns -1 if deque is full, else the number of elements in deque
int deque_push_front (Deque* this, int val) {
    
    if (this->size == this->capacity) return -1;
    
    this->front = (this->front == 0) ? (this->capacity-1) : (this->front-1);
    
    *(this->arr + this->front) = val;

    return (++this->size);
}


// returns -1 if deque is empty, else the front element
int deque_pop_front (Deque* this) {
    
    if (this->size == 0) return -1;
    
    int val =  *(this->arr + this->front);
    
    this->front = (this->front == (this->capacity - 1)) ? 0 : (this->front+1);
    
    this->size--;
    return val;
}


// returns -1 if deque is empty, else the front element without removing it
int deque_peek_front (Deque* this) {
    
    if (this->size == 0) return -1;
    
    return *(this->arr + this->front);
}


// returns -1 if deque is full, else the number of elements in deque
int deque_push_back (Deque* this, int val) {
    
    if (this->size == this->capacity) return -1;
    
    int offset = (this->front + this->size) % this->capacity;
    *(this->arr + offset) = val;

    return (++this->size);
}


// returns -1 if deque is empty, else the back element
int deque_pop_back (Deque* this) {
    
    if (this->size == 0) return -1;
    this->size--;
    
    int val =  *(this->arr + ((this->front + this->size) % this->capacity));
    
    return val;
}

// returns -1 if deque is empty, else the back element without removing it
int deque_peek_back (Deque* this) {
    
    if (this->size == 0) return -1;
    int val =  *(this->arr + ((this->front + this->size - 1) % this->capacity));
    
    return val;
}


void deque_destroy (Deque* this) {
    free(this->arr);
    free(this);
}

