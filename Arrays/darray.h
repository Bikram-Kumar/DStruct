#pragma once

#include <stdlib.h>
#include "darrayutils.h"



// Dynamic Array for int
typedef struct DArray {
    int* arr; 
    
    size_t size;
    size_t capacity;
    
    void (*append) (struct DArray* this, int num);
    int (*get_at) (struct DArray* this, size_t index);
    void (*set_at) (struct DArray* this, size_t index, int num);
    
    void (*resize) (struct DArray* this, size_t new_size);
    void (*shrink_to_fit) (struct DArray* this);
    
    void (*destroy) (struct DArray* this);
} DArray;


// creates empty DArray of given size, and returns the pointer to created DArray
DArray* create_empty_darray_of_size (size_t);



// creates empty DArray of DARRAY_DEFAULT_SIZE, and returns the pointer to created DArray
DArray* create_empty_darray();



// creates DArray of given size, appends the passed integer and returns the pointer to created DArray
DArray* create_darray_of_size (size_t, int);


// creates DArray of DARRAY_DEFAULT_SIZE, appends the passed integer and returns the pointer to created DArray
DArray* create_darray (int);


// creates a DArray from given array and returns the pointer to created DArray. The given array is copied and NOT referenced by the DArray.
DArray* create_darray_from_array (int* arr_start, int* arr_end);


void darray_append (DArray*, int);
int darray_get_at (DArray*, size_t);
void darray_set_at (DArray*, size_t, int);
void darray_resize (DArray*, size_t);
void darray_shrink_to_fit (DArray*);
void darray_destroy (DArray*);


