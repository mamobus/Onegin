#include "poem_funcs.h"

void sort_poem(struct poem_s *poem_data)
{
    assert(poem_data != nullptr);
    assert(poem_data->str_ptrs != nullptr);

    printf("lines num: %d\n", poem_data->poem_p_length);

    for(size_t i = 0; i < poem_data->poem_p_length; i++)
    {
        for(size_t cur_num = 0; cur_num < poem_data->poem_p_length - 1; cur_num++)
        {
            if(str_alpha_cmpr(poem_data->str_ptrs[cur_num], poem_data->str_ptrs[cur_num + 1]) == 1) 
            {
                char *temp_p = poem_data->str_ptrs[cur_num];
                poem_data->str_ptrs[cur_num] = poem_data->str_ptrs[cur_num + 1];
                poem_data->str_ptrs[cur_num + 1] = temp_p;
            } 
        }   
    }
    return;
}

void quick_sort_poem(char **str_ptrs, size_t low, size_t high)
{   
    if(low < high)
    {
        size_t middle = devide(str_ptrs, low, high);

        quick_sort_poem(str_ptrs, low, middle);
        quick_sort_poem(str_ptrs, middle + 1, high);
    }
}

size_t devide(char **str_ptrs, size_t low, size_t high)
{
    char *middle = str_ptrs[(low + high) / 2];

    while(true)
    {
        while(str_alpha_cmpr(str_ptrs[low], middle) < 0)
        {
            low++;
        }

        while(str_alpha_cmpr(str_ptrs[high], middle) > 0)
        {
            high--;
        }

        if(low >= high) 
            return high;

        char *temp = str_ptrs[low];
        str_ptrs[low] = str_ptrs[high];
        str_ptrs[high] = temp;
        low += 1; high -= 1;

        if(low >= high) 
            return high;
    }
}

void copy_poem(struct poem_s *poem_data)
{
    assert(poem_data->poem_file != 0);
    assert(poem_data->strs      != 0);
    assert(poem_data->str_ptrs  != 0);

    fread(poem_data->strs, 1, poem_data->poem_length, poem_data->poem_file);

    poem_data->strs[poem_data->poem_length + 1] = 0;

    for(size_t count = 0; count < poem_data->poem_length; count++)
    {
        if(poem_data->strs[count] == '\n')
        {
            poem_data->strs[count] = 0;
            poem_data->poem_p_length++;
            poem_data->str_ptrs[poem_data->poem_p_length] = poem_data->strs + count + 1;
        }
    }
} 

void print_poem(struct poem_s *poem_data)
{
    printf("p length = %d\n", poem_data->poem_p_length);

    for(size_t count = 0; count < poem_data->poem_p_length + 1; count++)
    {
        printf("%d: %s \n", count, poem_data->str_ptrs[count]);
    }
}

void write_poem(struct poem_s *poem_data)
{
    FILE *out_f = fopen("C://Users//Anonim//Downloads//Onegin-main//onegin_sorted.txt", "w");
    for(size_t i = 0; i < poem_data->poem_p_length + 1; i++)
    {
        fputs(poem_data->str_ptrs[i], out_f);
        char temp_ch = poem_data->str_ptrs[i][strlen(poem_data->str_ptrs[i]) - 1];
        if((temp_ch != '\n') && (temp_ch != '\r'))
            fputc('\n', out_f);
    }
}