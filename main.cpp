#include <stdio.h>
#include "poem_funcs.h"

int main() 
{
    struct poem_s poem_data;

    poem_data.poem_file = fopen("C://Users//Anonim//Downloads//Onegin-main//onegin.txt", "r"); 
    fseek(poem_data.poem_file, 0l, SEEK_END);
    poem_data.poem_length = ftell(poem_data.poem_file);
    fseek(poem_data.poem_file, 0l, SEEK_SET);   
    
    poem_data.strs     = (char* ) malloc(poem_data.poem_length + 1);
    poem_data.str_ptrs = (char**) malloc(poem_data.poem_length + 1);
    poem_data.str_ptrs[0] = poem_data.strs;

    copy_poem(&poem_data);
    
    quick_sort_poem(poem_data.str_ptrs, 0, poem_data.poem_p_length);

    print_poem(&poem_data);

    write_poem(&poem_data);

    free(poem_data.strs);
    free(poem_data.str_ptrs);

    return 0;
}
