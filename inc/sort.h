#ifndef _SORT_H_
#define _SORT_H_

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "structures.h"

typedef int(*function_ptr)(str_and_len *, str_and_len *);

void bubble_sort (str_and_len **ptr_array, int num_of_lines, function_ptr cmp);
void swap (void* obj1, void* obj2, size_t obj_size);

#endif