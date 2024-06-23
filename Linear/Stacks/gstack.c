#include "gstack.h"

GStack* create_gstack (int cap) {
    GStack* this = malloc(sizeof(GStack));
    this->arr = malloc(sizeof(void*) * cap);
    this->top = 0;
    this->capacity = cap;
    this->push = &gstack_push;
    this->pop = &gstack_pop;
    this->peek = &gstack_peek;
    this->destroy = &gstack_destroy;
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

void gstack_destroy (GStack* this) {
    free(this->arr);
    free(this);
}




