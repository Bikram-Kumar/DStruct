#include "darray.h"



DArray* create_empty_darray_of_size (size_t size) {
    DArray* this = malloc(sizeof(DArray));
    this->size = 0;
    this->capacity = size;
    this->arr = malloc(sizeof(int) * size);
    
    this->append = &darray_append;
    this->get_at = &darray_get_at;
    this->set_at = &darray_set_at;
    this->resize = &darray_resize;
    this->shrink_to_fit = &darray_shrink_to_fit;
    this->destroy = &darray_destroy;
    
    return this;
}

DArray* create_empty_darray () {
    return create_empty_darray_of_size(DARRAY_DEFAULT_SIZE);
}


DArray* create_darray_of_size (size_t size, int num) {
    DArray* this = create_empty_darray_of_size(size);
    this->append(this, num);
    return this;

}


DArray* create_darray (int num) {
    DArray* this = create_empty_darray_of_size(DARRAY_DEFAULT_SIZE);
    this->append(this, num);
    return this;
}


DArray* create_darray_from_array (int* arr_start, int* arr_end) {
    DArray* this = create_empty_darray_of_size(arr_end - arr_start);
    memcpy(this->arr, arr_start, this->capacity);
    return this;
}


void darray_append (DArray* this, int num) {
    
    if (this->size >= this->capacity) {
        this->resize(this, darray_calculate_new_size(this->size));
    }
    
    this->arr[this->size] = num;
    
    this->size++;
    
}


int darray_get_at (DArray* this, size_t index) {
    return this->arr[index];
}


void darray_set_at (DArray* this, size_t index, int num) {
    this->arr[index] = num;
}


void darray_resize (DArray* this, size_t new_size) {
    this->arr = realloc(this->arr, sizeof(int) * new_size);
    this->capacity = new_size;
}

void darray_shrink_to_fit (DArray* this) {
    this->capacity = this->size;
    this->arr = realloc(this->arr, sizeof(int) * this->capacity);
}


void darray_destroy (DArray* this) {
    free(this->arr);
    free(this);
}






//utils

size_t darray_calculate_new_size(size_t current_size) {
    
    if (current_size <= ((DARRAY_DEFAULT_SIZE * 2) / 3)) return DARRAY_DEFAULT_SIZE;
    
    return (current_size + (current_size / 2));
}