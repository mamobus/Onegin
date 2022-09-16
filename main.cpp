#include <stdio.h>
#include "sort_poem.h"
#include "write_down_poem.h"

int main() 
{
    FILE *poem = fopen("c://Users//Anonim//Downloads//poem_sort//onegin.txt", "r");
    
    char *temp;
    char *sorted_p;

    sort_poem(sorted_p, temp, poem);

    wrtdwn_poem();
}