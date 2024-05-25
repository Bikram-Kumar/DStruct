
#include "arrays.h"



void init_stack (Stack* this, int cap) {
    this->arr = malloc(sizeof(int) * cap);
    this->top = 0;
    this->capacity = cap;
    this->push = &stack_push;
    this->pop = &stack_pop;
}


// returns -1 if stack is full, else the number of elements in stack
int stack_push (Stack* this, int val) {
    if (this->top == this->capacity) return -1;
    *(this->arr + this->top) = val;
    return(++this->top);
}


// returns -1 if stack is empty, else the top element
int stack_pop (Stack* this) {
    if (this->top == 0) return -1;
    this->top--;
    return *(this->arr + this->top);
}






void init_queue (Queue* this, int cap) {
    this->arr = malloc(sizeof(int) * cap);
    this->front = 0;
    this->capacity = cap;
    this->size = 0;
    this->enqueue = &queue_enqueue;
    this->dequeue = &queue_dequeue;
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

