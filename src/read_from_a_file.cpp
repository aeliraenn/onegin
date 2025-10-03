#include "../inc/read_from_a_file.h"


size_t get_file_size (FILE *file_ptr) {  //stat is unavailable on windows??
    assert(file_ptr);

    fseek(file_ptr, 0, SEEK_END);
    size_t file_size = (size_t)ftell(file_ptr);
    fseek(file_ptr, 0, SEEK_SET);

    return file_size;
}

size_t read_entire_file (char **buf)
{
    assert(buf);
    
    FILE *file_ptr = fopen("input.txt", "r");
    assert(file_ptr);

    size_t file_size = get_file_size(file_ptr);
    printf("file size = %zu\n", file_size);

    *buf = (char *)calloc(file_size + 1, sizeof(char));

    if (*buf == NULL) {
        printf("Memory allocation error\n");
        fclose(file_ptr);
        return 0;
    }

    size_t bytes_read = fread(*buf, sizeof(char), file_size, file_ptr);
    assert(buf);
    printf("bytes read = %zu\n", bytes_read);

    int num_of_lines = count_lines(*buf);
    printf("num of lines = %d\n", num_of_lines);

    #ifdef __WIN32
    *(*buf + file_size - num_of_lines) = '\0';
    #else 
    *(*buf + file_size) = '\0';
    #endif 
    
    int file_close_returned = fclose(file_ptr);
    if (file_close_returned != 0) {
        printf("Error closing input file\n");
    }

    return bytes_read;
}

size_t get_string_from_buffer(char** string_ptr, char** buf) 
{
    assert(string_ptr);
    assert(buf);

    *string_ptr = *buf;

    size_t string_len = 0;
    while(**buf != '\0' && **buf != '\n') {
        (*buf)++;
        string_len++;
    }
    if (**buf == '\n') string_len++;

    **buf = '\0';
    (*buf)++;
    
    return string_len;
}

str_and_len** create_ptr_array (char **buf, int num_of_lines)
{
    assert(buf);

    str_and_len **ptr_array = (str_and_len**)calloc(num_of_lines, sizeof(str_and_len*));
    if (ptr_array == NULL) {
        printf("Memory allocation error\n");
        return NULL;
    }


    /*
    int i = 0;
    int j = 0;
    int k = 0;

    while ((*buf)[j] != '\0') {
        if ((*buf)[j] == '\n') {
            printf("creating ptr_array\n");
            ptr_array[i]->str = (*buf) + k;
            ptr_array[i]->len = j - k;
            (*buf)[j] = '\0';
            i++;
            k = j + 1;
        }
        j++;
    }

    */

    for (int i = 0; i < num_of_lines; i++) {
        ptr_array[i] = (str_and_len*)calloc(1, sizeof(str_and_len));
        assert(ptr_array[i]);
        
        ptr_array[i]->len = get_string_from_buffer(&(ptr_array[i]->str), buf);
        
        //printf("len of \'%s\' = %zu\n", ptr_array[i]->str, ptr_array[i]->len);
    }

    return ptr_array;
}
