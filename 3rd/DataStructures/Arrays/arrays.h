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
} Stack;

Stack* init_stack (Stack*,int);
int stack_push (Stack*, int);
int stack_pop (Stack*);
int stack_peek (Stack*);



// Queue for int
typedef struct Queue {
    int* arr; 
    int front;
    int capacity;
    int size;
    int (*enqueue) (struct Queue*, int);
    int (*dequeue) (struct Queue*);
    int (*peek) (struct Queue*);
} Queue;

Queue* init_queue (Queue*,int);
int queue_enqueue (Queue*, int);
int queue_dequeue (Queue*);
int queue_peek (Queue*);










typedef struct Deque {
    int* arr;
    int front;
    int capacity;
    int size;
    int (*push_front) (struct Deque*, int);
    int (*pop_front) (struct Deque*);
    int (*peek_front) (struct Deque*);
    int (*push_back) (struct Deque*, int);
    int (*pop_back) (struct Deque*);
    int (*peek_back) (struct Deque*);
} Deque;

Deque* init_deque (Deque*,int);
int deque_push_front (Deque*, int);
int deque_pop_front (Deque*);
int deque_peek_front (Deque*);
int deque_push_back (Deque*, int);
int deque_pop_back (Deque*);
int deque_peek_back (Deque*);








// Generic Stack
typedef struct GStack {
    void** arr; // stores pointer data of any type
    int top;
    int capacity;
    int (*push) (struct GStack*, void*);
    void* (*pop) (struct GStack*);
    void* (*peek) (struct GStack*);
} GStack;

GStack* init_gstack (GStack*,int);
int gstack_push (GStack*, void*);
void* gstack_pop (GStack*);
void* gstack_peek (GStack*);



// Generic Queue
typedef struct GQueue {
    void** arr; // stores pointer data of any type
    int front;
    int capacity;
    int size;
    int (*enqueue) (struct GQueue*, void*);
    void* (*dequeue) (struct GQueue*);
    void* (*peek) (struct GQueue*);
} GQueue;

GQueue* init_gqueue (GQueue*,int);
int gqueue_enqueue (GQueue*, void*);
void* gqueue_dequeue (GQueue*);
void* gqueue_peek (GQueue*);










