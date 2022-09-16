#include "sort_poem.h"

char *sort_poem(char *sorted_p, char *temp, FILE *poem)
{
    assert(poem != nullptr);

    
}

char *copy_poem(char *sorted_p[], char *temp, FILE *poem)
{
    assert(poem != nullptr);

    sorted_p[0] = temp;
    size_t count = 0;
    size_t p_count = 0;

    for(int temp_ch = 0; (temp_ch = getc(poem)) != EOF; count++)
    {
        temp[count] = temp_ch;

        if(temp_ch == '\n')
        {
            sorted_p[p_count] = (char*) (count + 1);
            p_count++;
            count++;
            temp[count] = 0;
        }
    }
    return temp;
}