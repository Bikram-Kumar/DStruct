#pragma once

#include <stdlib.h>


typedef struct Stack {
    int* arr;
    int top;
    int capacity;
    int (*push) (struct Stack*, int);
    int (*pop) (struct Stack*);
    int (*peek) (struct Stack*);
} Stack;

void init_stack (Stack*,int);
int stack_push (Stack*, int);
int stack_pop (Stack*);
int stack_peek (Stack*);




typedef struct Queue {
    int* arr;
    int front;
    int capacity;
    int size;
    int (*enqueue) (struct Queue*, int);
    int (*dequeue) (struct Queue*);
    int (*peek) (struct Queue*);
} Queue;

void init_queue (Queue*,int);
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

void init_deque (Deque*,int);
int deque_push_front (Deque*, int);
int deque_pop_front (Deque*);
int deque_peek_front (Deque*);
int deque_push_back (Deque*, int);
int deque_pop_back (Deque*);
int deque_peek_back (Deque*);










