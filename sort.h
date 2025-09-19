#ifndef _SORT_H_
#define _SORT_H_

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int(*function_ptr)(char *, char *);

void bubble_sort (char **ptr_array, int num_of_lines, function_ptr cmp);

#endif