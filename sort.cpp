#include "sort.h"

void swap (void* obj1, void* obj2, size_t obj_size) {
    assert(obj1);
    assert(obj2);

    void* tmp = calloc(1, obj_size);
    assert(tmp);

    memcpy(tmp, obj1, obj_size);
    memcpy(obj1, obj2, obj_size);
    memcpy(obj2, tmp, obj_size);

    free(tmp);
}

void bubble_sort(str_and_len** ptr_array, int num_of_lines, function_ptr cmp)
{
    assert(ptr_array);

    bool swapped = false;

    for (int i = 0; i < num_of_lines - 1; i++) {
    swapped = false;
        for (int j = 0; j < num_of_lines - i - 1; j++) {
            if ((*cmp)(ptr_array[j], ptr_array[j + 1]) > 0) {
                swap(ptr_array[j], ptr_array[j + 1], sizeof(str_and_len*));
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}