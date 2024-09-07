#pragma once

#include <stdlib.h>
#include <string.h>
#include "darrayutils.h"



// Dynamic Array for generic types
typedef struct GArray {
    void** arr; 
    
    size_t size;
    size_t capacity;
    
    void (*append) (struct GArray* this, void* ptr);
    void* (*get_at) (struct GArray* this, size_t index);
    void (*set_at) (struct GArray* this, size_t index, void* ptr);
    
    void (*resize) (struct GArray* this, size_t new_size);
    void (*shrink_to_fit) (struct GArray* this);
    
    void (*destroy) (struct GArray* this);
} GArray;


// creates empty GArray of given size, and returns the pointer to created GArray
GArray* create_empty_garray_of_size (size_t);



// creates empty GArray of DARRAY_DEFAULT_SIZE, and returns the pointer to created GArray
GArray* create_empty_garray();



// creates GArray of given size, appends the passed integer and returns the pointer to created GArray
GArray* create_garray_of_size (size_t, void*);


// creates GArray of DARRAY_DEFAULT_SIZE, appends the passed integer and returns the pointer to created GArray
GArray* create_garray (void*);


// creates a GArray from given array and returns the pointer to created GArray. The given array is copied and NOT referenced by the GArray.
GArray* create_garray_from_array (void** arr_start, void** arr_end);


void garray_append (GArray*, void*);
void* garray_get_at (GArray*, size_t);
void garray_set_at (GArray*, size_t, void*);
void garray_resize (GArray*, size_t);
void garray_shrink_to_fit (GArray*);
void garray_destroy (GArray*);

