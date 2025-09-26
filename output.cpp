#include "output.h"

void print_arr (str_and_len **ptr_array, int num_of_lines)
{
    for (int i = 0; i < num_of_lines; i++) {
        printf("\'%s\'\n", ptr_array[i]->str);
    }
}