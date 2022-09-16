#include <stdio.h>
#include "sort_poem.h"
#include "write_down_poem.h"

int main() 
{
    FILE *poem = fopen("test.txt", "r+w");
    
    char temp[200000];
    char *sorted_p[10000];

    copy_poem(sorted_p, temp, poem);

    for(size_t i = 0; sorted_p[i] != 0; i++)
        printf("%s", sorted_p[i]);

    wrtdwn_poem();
}