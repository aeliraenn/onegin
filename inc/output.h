#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "sort.h"
#include "str_funcs.h"
#include "structures.h"

void print_arr (str_and_len **ptr_array, int num_of_lines);
void print_arr_to_file (str_and_len **ptr_array, int num_of_lines, const char* filename);
void create_output_file (str_and_len **ptr_array, int num_of_lines, const char* filename);

#endif