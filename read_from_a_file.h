#ifndef _READ_FROM_A_FILE_H_
#define _READ_FROM_A_FILE_H_

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "str_funcs.h"
#include "structures.h"

int            read_file                (char *ptr_array[], FILE *src_file);
size_t         get_file_size            (FILE *file_ptr);
size_t         read_entire_file         (char **buf, FILE *file_ptr);
size_t         get_string_from_buffer   (char** string_ptr, char** buf);
str_and_len**  create_ptr_array         (char **buf, int num_of_lines);

#endif