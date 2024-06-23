#pragma once

#include <stdlib.h>


// Stack for int
typedef struct Stack {
    int* arr; 
    int top;
    int capacity;
    int (*push) (struct Stack*, int);
    int (*pop) (struct Stack*);
    int (*peek) (struct Stack*);
    void (*destroy) (struct Stack*);
} Stack;

Stack* create_stack (int);
int stack_push (Stack*, int);
int stack_pop (Stack*);
int stack_peek (Stack*);
void stack_destroy (Stack*);

