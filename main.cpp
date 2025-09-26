#include <stdio.h>
#include <stdlib.h>

#include "str_funcs.h"
#include "sort.h"
#include "read_from_a_file.h"
#include "output.h"

int main()
{
    char *buf = NULL;
    read_entire_file(&buf);

    //printf("%s\n", buf);

    int num_of_lines = count_lines(buf);
    printf("num of lines in main = %d\n", num_of_lines);

    str_and_len **ptr_array = create_ptr_array(&buf, num_of_lines);
    //sprintf("array of pointers created\n");
    //print_arr(ptr_array, num_of_lines);

    bubble_sort(ptr_array, num_of_lines, &my_strcmp);
    sprintf("array of pointers alphabetically sorted\n");
    print_arr(ptr_array, num_of_lines);

    bubble_sort(ptr_array, num_of_lines, &my_rstrcmp);
    sprintf("array of pointers rhyme-based sorted\n");
    print_arr(ptr_array, num_of_lines);

    return 0;
}
