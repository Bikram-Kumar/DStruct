#pragma once

#include <stdlib.h>


typedef struct Stack {
    int* arr;
    int top;
    int capacity;
    int (*push) (struct Stack*, int);
    int (*pop) (struct Stack*);
} Stack;

void init_stack (Stack*,int);
int stack_push (Stack*, int);
int stack_pop (Stack*);

typedef struct {int val;} Queue;
typedef struct {int val;} CircularQueue;
typedef struct {int val;} Dequeue;



