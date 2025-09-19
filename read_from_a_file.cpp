#include "read_from_a_file.h"

size_t get_file_size (FILE *file_ptr) {  //stat is unavailable on windows??
    assert(file_ptr);

    fseek(file_ptr, 0, SEEK_END);
    size_t file_size = (size_t)ftell(file_ptr);
    //rewind(file_ptr);
    fseek(file_ptr, 0, SEEK_SET);

    return file_size;
}

int read_file (char *ptr_array[], FILE *src_file)
{
    assert(ptr_array);
    assert(src_file);

    int i = 0;
    size_t line_size = 0;
    while (my_getline(&ptr_array[i], &line_size, src_file) != -1) {
        //printf("%s\n",  ptr_array[i]);
        i++;
    }

    return i; //returns the number of read lines
}

size_t read_entire_file (char **buf, FILE *file_ptr)
{
    assert(buf);
    assert(file_ptr);

    size_t file_size = get_file_size(file_ptr);
    printf("file size = %u\n", file_size);

    *buf = (char *)calloc(file_size + 1, sizeof(char));

    if (*buf == NULL) {
        printf("Memory allocation error\n");
        fclose(file_ptr);
        return 0;
    }

    size_t bytes_read = fread(*buf, sizeof(char), file_size, file_ptr);
    printf("bytes read = %u\n", bytes_read);

    int num_of_lines = count_lines(*buf);
    printf("num of lines = %d\n", num_of_lines);

    /*
    if (bytes_read != file_size) {
        printf("Error reading file\n");
        free(buf);
        fclose(file_ptr);
        return 0;
    }
    */

    *(*buf + file_size - num_of_lines) = '\0';

    return bytes_read;
}

char** create_ptr_array (char **buf, int num_of_lines)
{
    assert(buf);

    char **ptr_array = (char **)calloc(num_of_lines, sizeof(char*));
    if (ptr_array == NULL) {
        printf("Memory allocation error\n");
        return NULL;
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while ((*buf)[j] != '\0') {
        if ((*buf)[j] == '\n') {
            ptr_array[i] = (*buf) + k;
            (*buf)[j] = '\0';
            i++;
            k = j + 1;
        }
        j++;
    }

    return ptr_array;
}
