#pragma once

#include <stdlib.h>


// Generic Stack
typedef struct GStack {
    void** arr; // stores pointer data of any type
    int top;
    int capacity;
    int (*push) (struct GStack*, void*);
    void* (*pop) (struct GStack*);
    void* (*peek) (struct GStack*);
    void (*destroy) (struct GStack*);
} GStack;

GStack* create_gstack (int);
int gstack_push (GStack*, void*);
void* gstack_pop (GStack*);
void* gstack_peek (GStack*);
void gstack_destroy (GStack*);
