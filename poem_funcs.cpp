#include "poem_funcs.h"

bool str_cmpr(const char *str1, const char *str2)
{
    for(size_t num = 0; (str1[num] == 0) || (str2[num] == 0) ; num++)
    {
        if(str1[num] > str2[num])
            return false;
    }
    return true;
}



char *sort_poem(struct poem_s *poem_data)
{
    assert(poem_data != nullptr);
    assert(poem_data->str_ptrs != nullptr);

    printf("lines num: %d\n", poem_data->poem_p_length);

    for(size_t i = 0; i < poem_data->poem_p_length; i++)
    {
        for(size_t cur_num = 0; cur_num < poem_data->poem_p_length - 1; cur_num++)
        {
            if((isalpha(*poem_data->str_ptrs[cur_num])) && (strcmp(poem_data->str_ptrs[cur_num], poem_data->str_ptrs[cur_num + 1]) == 1)) 
            {
                char *temp_p = poem_data->str_ptrs[cur_num];
                poem_data->str_ptrs[cur_num] = poem_data->str_ptrs[cur_num + 1];
                poem_data->str_ptrs[cur_num + 1] = temp_p;
            } 
        }   
    }

    return *poem_data->str_ptrs;
}

char *copy_poem(struct poem_s *poem_data)
{
    assert(poem_data->poem_file != 0);
    assert(poem_data->strs      != 0);
    assert(poem_data->str_ptrs  != 0);
    printf("asserts passed\n");

    fread(poem_data->strs, 1, poem_data->poem_length, poem_data->poem_file);
    printf("fread passed\n");
    poem_data->strs[poem_data->poem_length] = 0;
    // printf("%s\n", poem_data->strs);

    for(size_t count = 0; count < poem_data->poem_length; count++)
    {
        if(poem_data->strs[count] == '\n')
        {
            poem_data->strs[count] = 0;
            poem_data->poem_p_length++;
            poem_data->str_ptrs[poem_data->poem_p_length] = poem_data->strs + count + 1;
        }
    }
    printf("zeroing passed\n");
    printf("%s\n", poem_data->strs);
} 

void print_poem(struct poem_s *poem_data)
{
    printf("p length = %d\n", poem_data->poem_p_length);

    for(size_t count = 0; count < poem_data->poem_p_length; count++)
    {
        printf("%d: %s\n", count, poem_data->str_ptrs[count]);
    }
}