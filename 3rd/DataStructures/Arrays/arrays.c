
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

