#include "str_funcs.h"

int put_str(const char str[])
{
    assert(str != nullptr);

    for(int i = 0; str[i] != 0; ++i)
    {
        if (putchar(str[i]) == EOF) 
            return EOF;
    }
    putchar('\n');

    return str[0];
}   

char* str_chr(char *str, int ch)
{              
    assert(str != nullptr); 
    
    for(int i = 0; str[i] != 0; ++i)
    {
        if (str[i] == ch) 
            return &str[i];
    }
    return nullptr;
}

size_t str_length(const char *str) 
{
    assert(str != nullptr);

    size_t i = 0;

    for(; str[i] != 0; i++)
        ;

    return i;   
}

char *str_copy(char *dest, const char *src)
{
    assert((dest != 0) && (src != 0));
    
    size_t i = 0;

    for(; src[i] != 0; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = 0;

    return dest;
}

char *str_ncopy(char *dest, const char *src, size_t count)
{   
    assert((src != nullptr) && (dest != nullptr));

    size_t i = 0;

    for(; (src[i] != 0) && (i < count); i++)
    {
        dest[i] = src[i];
    }
    return dest;
} 

char *str_CAT(char *dest, const char *src)
{    
    assert((src != nullptr) && (dest != nullptr));

    size_t dest_length = str_length(dest); 

    for(size_t i = 0; src[i] != 0; i++)
    {
        dest[dest_length + i] = src[i];
    }
    return dest;
}

char *str_nCAT(char *dest, const char *src, const size_t count)
{
    assert((src != nullptr) && (dest != nullptr));

    size_t dest_length = str_length(dest); 

    for(size_t copy_count = 0; (copy_count < count); copy_count++)
    {
        if(src[copy_count] != 0)
            dest[dest_length + copy_count] = src[copy_count];
        else
        {
            dest[dest_length + copy_count] = 0;
            break;
        }
    }
    return dest;
}

char *f_get_s(char *str, const int count, FILE *file)
{
    assert((file != nullptr) && (str != nullptr));

    if(count == 0)
    return str;

    size_t i = 0;

    for(int temp_ch = 0; (temp_ch != (int) '\r') && (temp_ch != EOF) && (i < (count - 1)); i++)
    {
        temp_ch = fgetc(file);
        str[i] = (char) temp_ch;
        // (*(str + i)) = temp_ch;
    }
    str[i + 1] = 0;
    
    return str;
}

char *str_dup(const char *str)
{
    char *str_replica = (char*) malloc(str_length(str) + 1);

    str_copy(str_replica, str);

    return str_replica; 
}

FILE *get_line(FILE *file, char *dest, char separator)
{
    int temp_ch = 0;
    size_t i = 0;

    for(; ((temp_ch = getc(file)) != separator) && (temp_ch != EOF); i++)
    {
        dest[i] = temp_ch;
    }   
    dest[i] = 0;
    
    return file;
}

int str_alpha_cmpr(const char *str1, const char *str2)
{                                                                                                                                                                                                                                                                       
    assert(str1 != 0);
    assert(str1 != 0);

    for(size_t i = 0, j = 0; true;)
    {
        while((str1[i] != 0) && (isalpha(str1[i]) == 0))
        {
            i++;
        }
        while((str2[j] != 0) && (isalpha(str2[j]) == 0))
        {
            j++;
        }
        
        if((str1[i] == str2[j]) && (str1[i] != 0))
        {
            i++; 
            j++;
            continue;
        }
        if(str1[i] > str2[j])
        {
            return 1;
        }   
        if(str1[i] < str2[j])
        {
            return -1;
        }         
        if((str1[i] == str2[j]) && (str1[i] == 0))
        {
            return 0;   
        }
            
    }

}

//puts, strchr, strlen, strcpy, strncpy, strcat, strncat, fgets, strdup, getline - именно в таком порядке. 



//Разделять логические блоки
//циклы for
//double *a
//вопрос про size_t
//i++ ++i
