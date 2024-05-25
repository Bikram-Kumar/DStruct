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




typedef struct Queue {
    int* arr;
    int front;
    int capacity;
    int size;
    int (*enqueue) (struct Queue*, int);
    int (*dequeue) (struct Queue*);
} Queue;

void init_queue (Queue*,int);
int queue_enqueue (Queue*, int);
int queue_dequeue (Queue*);





typedef struct {int val;} CircularQueue;
typedef struct {int val;} Dequeue;



