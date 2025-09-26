#include "sort.h"

void swap (void* obj1, void* obj2, size_t obj_size) {
    assert(obj1);
    assert(obj2);

    /*  //govno
    void* tmp = calloc(1, obj_size);
    assert(tmp);

    memcpy(tmp, obj1, obj_size);
    memcpy(obj1, obj2, obj_size);
    memcpy(obj2, tmp, obj_size);

    free(tmp);
    */
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
                str_and_len* tmp = NULL;
                tmp = ptr_array[j];
                ptr_array[j] = ptr_array[j + 1];
                ptr_array[j + 1] = tmp;
                
                //swap(ptr_array[j], ptr_array[j + 1], sizeof(str_and_len*));
                //printf("swapped: \'%s\', \'%s\'\n", ptr_array[j]->str, ptr_array[j + 1]->str);
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    return;
}