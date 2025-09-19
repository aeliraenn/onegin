#include "sort.h"

void bubble_sort(char** ptr_array, int num_of_lines, function_ptr cmp)
{
    assert(ptr_array);

    bool swapped = false;
    char *tmp = NULL;

    for (int i = 0; i < num_of_lines - 1; i++) {
    swapped = false;
        for (int j = 0; j < num_of_lines - i - 1; j++) {
            if ((*cmp)(ptr_array[j], ptr_array[j + 1]) > 0) {
                tmp = ptr_array[j];
                ptr_array[j] = ptr_array[j + 1];
                ptr_array[j + 1] = tmp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}