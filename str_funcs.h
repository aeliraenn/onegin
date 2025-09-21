#ifndef _STR_FUNCS_H_
#define _STR_FUNCS_H_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

#include "structures.h"

#define sep "\n-------------------------------------------------------------------------\n\n"
#define sprintf(A) printf(sep A sep)

int         count_lines  (char *buf);
int         my_strcmp    (str_and_len *str1, str_and_len *str2);
int         my_rstrcmp   (str_and_len *str1, str_and_len *str2);
char*       my_strncpy   (char *dest, const char *source, int lim);
char*       my_strncpy1  (char *dest, const char *source, int lim);
char*       my_strncat   (char *dest, const char *src, int lim);
char*       my_strncat1  (char *dest, const char *src, int lim);
int         my_strlen    (const char *str );
int         my_strlen1   (const char *str);
char*       my_strcpy    (char *dest, const char *source);
char*       my_strcpy1   (char *dest, const char *source);
char*       my_strdup    (const char *str);
char*       my_strdup1   (const char *str);
const char* my_strchr    (const char *str, int target);
const char* my_strchr1   (const char *str, int target);
char*       my_strcat    (char *dest, const char *src);
char*       my_strcat1   (char *dest, const char *src);
int         my_puts      (char *str);
int         my_puts1     (char *str);
int         my_atoi      (const char* str);
int         my_atoi1     (const char* str);
char*       my_fgets     (char *str, int lim, FILE *file);
char*       my_fgets1    (char *str, int lim, FILE *file);
ssize_t     my_getline   (char **lineptr, size_t *len, FILE *stream);


#endif