#pragma once

#include <stddef.h>


#ifndef DARRAY_DEFAULT_SIZE
    #define DARRAY_DEFAULT_SIZE 10
#endif

size_t darray_calculate_new_size(size_t current_size);
