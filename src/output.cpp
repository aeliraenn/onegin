#include "../inc/output.h"


void print_arr (str_and_len **ptr_array, int num_of_lines)
{
    for (int i = 0; i < num_of_lines; i++) {
        printf("\'%s\'\n", ptr_array[i]->str);
    }

    return;
}

void print_arr_to_file (str_and_len **ptr_array, int num_of_lines, FILE* output_file)
{
    assert(ptr_array);
    assert(output_file);

    for (int i = 0; i < num_of_lines; i++) {
        fprintf(output_file, "\'%s\'\n", ptr_array[i]->str);
    }

    return;
}

void create_output_file (str_and_len **ptr_array, int num_of_lines, const char* filename)
{
    FILE* output_file = fopen(filename, "w");
    assert(output_file);

    fprintf(output_file, sep "unsorted array of pointers\n" sep);
    print_arr_to_file(ptr_array, num_of_lines, output_file);
    
    bubble_sort(ptr_array, num_of_lines, &my_strcmp);
    fprintf(output_file, sep "array of pointers alphabetically sorted\n" sep);
    print_arr_to_file(ptr_array, num_of_lines, output_file);

    //bubble_sort(ptr_array, num_of_lines, &my_rstrcmp);
    qsort(ptr_array, num_of_lines, sizeof(str_and_len*), &my_rstrcmp);
    fprintf(output_file, sep "array of pointers rhyme-based sorted\n" sep);
    print_arr_to_file(ptr_array, num_of_lines, output_file);

    int file_close_returned = fclose(output_file);
    if (file_close_returned != 0) {
        printf("Error closing output file\n");
    }

    return;
}