#include <stdio.h>
#include "poem_funcs.h"

int compare(const void *str1, const void *str2);

int main() 
{
    printf("main started\n");
    struct poem_s poem_data;

    poem_data.poem_file = fopen("C://Users//Anonim//Downloads//Onegin-main//onegin2.txt", "r"); 
    fseek(poem_data.poem_file, 0l, SEEK_END);
    poem_data.poem_length = ftell(poem_data.poem_file);
    fseek(poem_data.poem_file, 0l, SEEK_SET);   
    
    poem_data.strs     = (char* ) malloc(poem_data.poem_length + 1);
    poem_data.str_ptrs = (char**) malloc(poem_data.poem_length + 1);
    poem_data.str_ptrs[0] = poem_data.strs;
    printf("%p %p %d\n", poem_data.strs, poem_data.str_ptrs, poem_data.poem_length);

    copy_poem(&poem_data);
    printf("copy passed\n");
    

    sort_poem(&poem_data);

    print_poem(&poem_data);

    free(poem_data.strs);
    free(poem_data.str_ptrs);

    return 0;
}
