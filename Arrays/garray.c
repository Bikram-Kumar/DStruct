#include "garray.h"



GArray* create_empty_garray_of_size (size_t size) {
    GArray* this = malloc(sizeof(GArray));
    this->size = 0;
    this->capacity = size;
    this->arr = malloc(sizeof(void*) * size);
    
    this->append = &garray_append;
    this->get_at = &garray_get_at;
    this->set_at = &garray_set_at;
    this->resize = &garray_resize;
    this->shrink_to_fit = &garray_shrink_to_fit;
    this->destroy = &garray_destroy;
    
    return this;
}

GArray* create_empty_garray () {
    return create_empty_garray_of_size(DARRAY_DEFAULT_SIZE);
}


GArray* create_garray_of_size (size_t size, void* ptr) {
    GArray* this = create_empty_garray_of_size(size);
    this->append(this, ptr);
    return this;

}


GArray* create_garray (void* ptr) {
    GArray* this = create_empty_garray_of_size(DARRAY_DEFAULT_SIZE);
    this->append(this, ptr);
    return this;
}


GArray* create_garray_from_array (void** arr_start, void** arr_end) {
    GArray* this = create_empty_garray_of_size(arr_end - arr_start);
    memcpy(this->arr, arr_start, this->capacity);
    return this;
}


void garray_append (GArray* this, void* ptr) {
    
    if (this->size >= this->capacity) {
        this->resize(this, darray_calculate_new_size(this->size));
    }
    
    this->arr[this->size] = ptr;
    
    this->size++;
    
}


void* garray_get_at (GArray* this, size_t index) {
    return this->arr[index];
}


void garray_set_at (GArray* this, size_t index, void* ptr) {
    this->arr[index] = ptr;
}


void garray_resize (GArray* this, size_t new_size) {
    this->arr = realloc(this->arr, sizeof(void*) * new_size);
    this->capacity = new_size;
}

void garray_shrink_to_fit (GArray* this) {
    this->capacity = this->size;
    this->arr = realloc(this->arr, sizeof(void*) * this->capacity);
}


void garray_destroy (GArray* this) {
    free(this->arr);
    free(this);
}

