#ifndef STR_FUNCS_H
#define STR_FUNCS_H
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <math.h>

// @brief Printing the string.
int put_str(const char str[]);

// @brief Searching for the first occurrence of the character ch in the string str.
char* str_chr(char *str, int ch);

// @brief Returns the length of the string without \0.
size_t str_length(const char *str);

// @brief Copies the string src to dest.
char *str_copy(char *dest, const char *src);

// @brief Copies the first count chars from src  to dest .
char *str_ncopy(char *dest, const char *src,  size_t count);

// @brief Concatenates the string src to the end of dest.
char *str_CAT(char *dest, const char *src);

// @brief Concatenates the first count chars from src to dest.
char *str_nCAT(char *dest, const char *src,  size_t count);

// @brief Reads the first count chars to str from file.
char *f_get_s(char *str, int count, FILE *file);

// @brief Copying the string.
char *str_dup(const char *str);

// @brief A function that reads a line from a file.
FILE *get_line(FILE *stream, char *dest, char separator = 0);

#endif //STR_FUNCS_H