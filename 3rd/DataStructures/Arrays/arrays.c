
#include "arrays.h"



Stack* init_stack (Stack* this, int cap) {
    this->arr = malloc(sizeof(int) * cap);
    this->top = 0;
    this->capacity = cap;
    this->push = &stack_push;
    this->pop = &stack_pop;
    this->peek = &stack_peek;
    return this;
}


// returns -1 if stack is full, else the number of elements in stack
int stack_push (Stack* this, int val) {
    if (this->top == this->capacity) return -1;
    *(this->arr + this->top) = val;
    return (++this->top);
}


// returns -1 if stack is empty, else the top element
int stack_pop (Stack* this) {
    if (this->top == 0) return -1;
    this->top--;
    return *(this->arr + this->top);
}


// returns -1 if stack is empty, else the top element without removing it
int stack_peek (Stack* this) {
    if (this->top == 0) return -1;
    return *(this->arr + this->top - 1);
}






Queue* init_queue (Queue* this, int cap) {
    this->arr = malloc(sizeof(int) * cap);
    this->front = 0;
    this->capacity = cap;
    this->size = 0;
    this->enqueue = &queue_enqueue;
    this->dequeue = &queue_dequeue;
    this->peek = &queue_peek;
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





Deque* init_deque (Deque* this, int cap) {
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








GStack* init_gstack (GStack* this, int cap) {
    this->arr = malloc(sizeof(void*) * cap);
    this->top = 0;
    this->capacity = cap;
    this->push = &gstack_push;
    this->pop = &gstack_pop;
    this->peek = &gstack_peek;
    return this;
}


// returns -1 if gstack is full, else the number of elements in gstack
int gstack_push (GStack* this, void* val) {
    if (this->top == this->capacity) return -1;
    *(this->arr + this->top) = val;
    return (++this->top);
}


// returns NULL if gstack is empty, else the top element
void* gstack_pop (GStack* this) {
    if (this->top == 0) return NULL;
    this->top--;
    return *(this->arr + this->top);
}


// returns NULL if gstack is empty, else the top element without removing it
void* gstack_peek (GStack* this) {
    if (this->top == 0) return NULL;
    return *(this->arr + this->top - 1);
}









GQueue* init_gqueue (GQueue* this, int cap) {
    this->arr = malloc(sizeof(void*) * cap);
    this->front = 0;
    this->capacity = cap;
    this->size = 0;
    this->enqueue = &gqueue_enqueue;
    this->dequeue = &gqueue_dequeue;
    this->peek = &gqueue_peek;
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




