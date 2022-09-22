#ifndef SORT_POEM_H
#define SORT_POEM_H

#include <stdio.h>
#include "str_funcs.h"
#include <assert.h>
#include <malloc.h>
#include<string.h>
#include <ctype.h>

struct poem_s
{
    char *strs = 0;
    char **str_ptrs = 0;
    FILE *poem_file = 0;
    size_t poem_length = 0;
    size_t poem_p_length = 0;
};

/**
 * bubble- sorts the poem in alphabetical order 
 * 
 * @param poem_data a pointer to a struct of type poem_s
 * 
 * @return Nothing.
 */
void sort_poem(struct poem_s *poem_data);

/**
 * quick- sorts the poem in alphabetical order 
 * 
 * @param str_ptrs the array of strings
 * @param low the index of the first element in the array
 * @param high the last index of the array
 */
void quick_sort_poem(char **str_ptrs, size_t low, size_t high);

/**
 * takes a pointer to an array of pointers to strings, and two indexes, and sorts an array 
 * using str_alpha_cmpr
 * 
 * @param str_ptrs The array of pointers to strings.
 * @param low The lowest index of the array to be sorted.
 * @param high the highest index of the last element in the array
 * 
 * @return The index of the last element in the left subarray.
 */
size_t devide(char **str_ptrs, size_t low, size_t high);

/**
 * reads the poem file into the `strs` array, then it replaces all the newline characters
 * with null characters, and then it sets the `str_ptrs` array to point to the start of each line
 * 
 * @param poem_data A pointer to a struct that contains the poem data.
 */
void copy_poem(struct poem_s *poem_data);

/**
 * prints the sorted poem to the console
 * 
 * @param poem_data a pointer to a struct poem_s
 */
void print_poem(struct poem_s *poem_data);

/**
 * writes the sorted poem to a file
 * 
 * @param poem_data a pointer to a struct containing the poem data
 */
void write_poem(struct poem_s *poem_data);

#endif //SORT_POEM_H


