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

char *sort_poem(struct poem_s *poem_data);

char *copy_poem(struct poem_s *poem_data);

void print_poem(struct poem_s *poem_data);

#endif //SORT_POEM_H