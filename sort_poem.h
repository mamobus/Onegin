#ifndef SORT_POEM_H
#define SORT_POEM_H

#include <stdio.h>
#include "str_funcs.h"
#include <assert.h>
#include <malloc.h>

char *copy_poem(char *sorted_p[], char *temp, FILE *poem);

char *sort_poem(char *sorted_p, char *temp, FILE *poem);

#endif //SORT_POEM_H