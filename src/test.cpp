#include <stdio.h>
#include <ctype.h>
#include <assert.h>

#include "../inc/structures.h"

int my_rstrcmp(str_and_len *str1, str_and_len *str2)
{
    assert(str1);
    assert(str2);

    size_t i = (str1->len) - 1;
    size_t j = (str2->len) - 1;

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

int main() 
{
    str_and_len s1 = {"aacb!", 4};
    str_and_len s2 = {"bbbb!,", 4};

    printf("%d", my_rstrcmp(&s1, &s2));
    
    return 0;
}
