#include "../inc/sort.h"

void swap(str_and_len** obj1, str_and_len** obj2) {
    assert(obj1);
    assert(obj2);
    
    str_and_len* tmp = *obj1;
    *obj1 = *obj2;
    *obj2 = tmp;

    return;
}

void bubble_sort(str_and_len** ptr_array, int num_of_lines, function_ptr cmp)
{
    assert(ptr_array);

    bool swapped = false;

    for (int i = 0; i < num_of_lines; i++) {
    swapped = false;
        for (int j = 0; j < num_of_lines - i - 1; j++) {
            if ((*cmp)(ptr_array[j], ptr_array[j + 1]) > 0) {
                swap(&ptr_array[j], &ptr_array[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    return;
}