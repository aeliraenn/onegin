#include "../inc/str_funcs.h"

int count_lines(char *buf) {
    assert(buf);

    int cnt = 0;
    int i = 0;
    while (buf[i] != EOF && buf[i] != '\0') {
        if (buf[i] == '\n') {
            cnt++;
        }
        i++;
    }

    return cnt;
}

char* my_strncpy (char *dest, const char *source, int lim) {
    assert(dest);
    assert(source);

    int copied = 0;
    char *pdest = dest;

    while ((copied++ < lim) && (*source != '\0')) {
        *dest++ = *source++;
    }

    if (copied <= lim) {
        *dest = '\0';
    }

    return pdest;
}

int my_rstrcmp(str_and_len *str1, str_and_len *str2)
{
    assert(str1);
    assert(str2);

    int i = (str1->len) - 1;
    int j = (str2->len) - 1;

    while (i >= 0 && j >= 0) {
        while (i >= 0 && !isalpha((str1->str)[i])) {
            i--;
        }
        while (j >= 0 && !isalpha((str2->str)[j])) {
            j--;
        }

        if (tolower((str1->str)[i]) > tolower((str2->str)[j])) {
            return 1;
        }
        else if (tolower((str1->str)[i]) < tolower((str2->str)[j])) {
            return -1;
        }

        i--;
        j--;
    }

    if (i == -1 && j == -1) return  0;
    if (i == -1)            return -1;
    if (j == -1)            return  1;
}

int my_strcmp(str_and_len *str1, str_and_len *str2)
{
    assert(str1);
    assert(str2);

    int i = 0;
    int j = 0;

    

    while ((str1->str)[i] != '\0' && (str2->str)[j] != '\0') {
        while ((str1->str)[i] != '\0' && !isalpha((str1->str)[i])) {
            i++;
        }
        while ((str2->str)[j] != '\0' && !isalpha((str2->str)[j])) {
            j++;
        }

        if (tolower((str1->str)[i]) > tolower((str2->str)[j])) {
            return 1;
        }
        if (tolower((str1->str)[i]) < tolower((str2->str)[j])) {
            return -1;
        }

        i++;
        j++;

        while ((str1->str)[i] != '\0' && !isalpha((str1->str)[i])) {
            i++;
        }
        while ((str2->str)[j] != '\0' && !isalpha((str2->str)[j])) {
            j++;
        }
    }
    if ((str1->str)[i] == '\0' && (str2->str)[j] == '\0') return  0;
    if ((str1->str)[i] == '\0')                    return -1;
    if ((str2->str)[j] == '\0')                    return  1;
}

char* my_strncpy1 (char *dest, const char *source, int lim) {
    assert(dest);
    assert(source);

    int copied = 0;
    char *pdest = dest;

    int i = 0;
    while ((copied < lim) && (source[i] != '\0')) {
        dest[i++] = source[i];
        copied++;
    }

    if (copied <= lim) {
        dest[i] = '\0';
    }

    return pdest;
}
            //  ������������ ���������� + ������� ��� �� ����� +
// ������� ��� ������� �� ������ ���������� ��� ������������ ����������
char* my_strncat(char *dest, const char *src, int lim) {
    assert(dest);
    assert(src);

    char *pdest = dest;
    while (*dest != '\0') {
        dest++;
    }

    int copied = 0;
    while ((++copied <= lim) && (*src != '\0')) {
        *dest++ = *src++;
    }
    return pdest;
}

char* my_strncat1 (char *dest, const char *src, int lim) {
    assert(dest);
    assert(src);

    char *pdest = dest;
    int i = 0;
    while (dest[i] != '\0') {
        i++;
    }

    int copied = 0;
    while ((copied < lim) && (src[i] != '\0')) {
        dest[i++] = src[i];
        copied++;
    }
    return pdest;
}

int my_strlen (const char *str) {
    assert(str);

    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

int my_strlen1 (const char *str) {
    assert(str);

    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char* my_strcpy (char *dest, const char *source) {
    assert(dest);
    assert(source);

    char *pdest = dest;
    while (*source != '\0') {
        *dest++ = *source++;
    }
    return pdest;
}

char* my_strcpy1 (char *dest, const char *source) {
    assert(dest);
    assert(source);

    char *pdest = dest;

    int i = 0;
    while (source[i] != '\0') {
        dest[i++] = source[i];
    }

    return pdest;
}

char* my_strdup(const char *str)  {
    assert(str);

    char *ptr = (char *)calloc(my_strlen(str)+1, sizeof(char)); // +1 ��� '\0'   , calloc
    if (ptr != NULL) {
        my_strcpy(ptr, str);
    }
    return ptr;
}

char* my_strdup1(const char *str)  {
    assert(str);

    char *ptr = (char *)calloc(my_strlen(str)+1, sizeof(char)); // +1 ��� '\0'   , calloc
    if (ptr != NULL) {
        my_strcpy(ptr, str);
    }
    return ptr;
}

const char* my_strchr (const char *str, int target)  {
    assert(str);

    while ((*str!= '\0') && (*str != target)) {
        str++;
    }

    if (*str == target) {
        return str;
    }
    else {
        return NULL;
    }
}

const char* my_strchr1 (const char *str, int target)  {
    assert(str);

    int i = 0;
    while ((str[i] != '\0') && (str[i] != target)) {
        i++;
    }

    if (str[i] == target) {
        return str;
    }
    else {
        return NULL;
    }
}

char* my_strcat(char *dest, const char *src) {
    assert(dest);
    assert(src);

    char *pdest = dest;

    while (*dest++);  //finds the end of the destination string

    while (*src != '\0') {
        *dest++ = *src++;
    } //copies source string to the end of dest string

    return pdest;
}

char* my_strcat1 (char *dest, const char *src) {
    assert(dest);
    assert(src);

    char *pdest = dest;
    int i = 0;

    while (dest[i] != '\0') {
        i++;
    }

    while (src[i] != '\0') {
        dest[i++] = src[i];
    }

    return pdest;
}

int my_puts (char *str) {
    assert(str);

    while (*str != '\0') {
        putchar(*str);
        str++;
    }

    return ferror(stdout) ? EOF : 0;
}

int my_puts1 (char *str) {
    assert(str);

    int i = 0;

    while (str[i] != '\0') {
        putchar(str[i]);
        i++;
    }

    return ferror(stdout) ? EOF : 0;
}

int my_atoi (const char* str) {
    assert(str);

    int i = 0;
    int num = 0;

    int sign = 1;
    if (str[i] == '-') {
        sign = -1;
        i++;
    }

    for (; str[i] >= '0' && str[i] <='9'; i++) {
        num = 10 * num + (str[i] - '0');
    }

    return num * sign;
}

int my_atoi1 (const char* str) { // ������������ ����������
    assert(str);

    int num = 0;
    int sign = 1;
    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str >= '0' && *str <= '9') {   // while (*s >= '0' && *s++ <= '9'); will work??
        num = 10 * num + (*str - '0');
        str++;
    }
    return num * sign;
}

char* my_fgets (char *str, int lim, FILE *file) {
    assert(str);
    assert(file);

    char symbol = 0;
    char *ptr_str = str;

    while ((--lim > 0) && (symbol = getc(file)) != EOF) {
        if ((*ptr_str++ = symbol) == '\n') {
            break;
        }
    }

    *ptr_str = '\0';

    return (symbol == EOF && ptr_str == str) ? NULL : str;
}

char* my_fgets1 (char *str, int lim, FILE *file) {
    assert(str);
    assert(file);

    char symbol = getc(file);
    char *ptr_str = str;

    while ((lim >= 0) && (symbol != EOF)) {
        *ptr_str = symbol;

        if (*ptr_str == '\n') {
            ptr_str++;
            break;
        }

        lim--;
        ptr_str++;
    }

    *ptr_str = '\0';

    return (symbol == EOF && ptr_str == str) ? NULL : str;
}

ssize_t my_getline (char **lineptr, size_t *len, FILE *stream) {
    assert(lineptr);
    assert(len);
    assert(stream);

    if (*lineptr == NULL || *len == 0) {
        *len = 100;  // initial buffer size if no buffer is provided
        *lineptr = (char *)calloc(*len, sizeof(char));
        if (*lineptr == NULL) {
            perror("Error: calloc couldn\'t allocate space\n");
            return -1;
        }
    }

    size_t pos = 0;
    int symbol = 0;

    while ((symbol = fgetc(stream)) != EOF) {
        if (pos + 1 >= *len) { //checks if we need to resize the buffer
            size_t new_size = 2 * (*len);
            char *new_ptr = (char *)realloc(*lineptr, new_size);
            if (new_ptr == NULL) {
                perror("Error: realloc couldn\'t allocate space\n");
                return -1;
            }
            *lineptr = new_ptr;
            *len = new_size;
        }

        (*lineptr)[pos++] = (char)symbol;

        if (symbol == '\n') {
            break;
        }
    }

    if ((pos < *len - 1) || (pos == *len)) {
        size_t new_size = pos + 1;
        char *new_ptr = (char *)realloc(*lineptr, new_size);
        if (new_ptr == NULL) {
            perror("Error: realloc coldn\'t allocate space\n");
            return -1;
        }
        *lineptr = new_ptr;
        *len = new_size;
    }

    (*lineptr)[pos] = '\0';

    if (pos == 0 || symbol == EOF) {
        return -1;
    }

    return (ssize_t)pos;
}
