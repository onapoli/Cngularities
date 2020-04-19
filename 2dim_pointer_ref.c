#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    THIS IS A TRIVIAL SAMPLE TO SHARE A BUG I ENCOUNTERED WHILE PASSING AN EMPTY ALLOCATED
    char * POINTER TO A FUNCTION FOR FILLING IT INSIDE THAT SAME FUNCTION.

    IT TOOK ME A WHILE TO UNDERSTAND WHAT WAS HAPPENING, SO MAYBE IT CAN HELP SOMEBODY. 
*/

/*
    KEEP IN MIND THAT THIS IS NOT THE BEST WAY TO ACHIEVE THE RESULT,
    BUT I WAS TRYING TO DO SOMETHING SIMILAR.

    BEFORE FIGURING OUT WHY I WAS GETTING Seg. fault, I REALIZED THAT I COULD
    AVOID THE PROBLEM BY ALLOCATING MEMORY FOR copy INSIDE ft_copy AND
    return (copy) FILLED OUT.
    
    BUT THEN I WAS CURIOUS ABOUT WHY I RECEIVED AN ERROR THE OTHER WAY.
*/

void    ft_copy(char **copy, char *src)
{
    int i;

    i = 0;
    while (*src)
        (*copy)[i++] = *src++;
    /*
        I WAS USING *copy[i++], WHICH CAUSED A Seg. fault ERROR. 
        IT WAS INTERPRETED AS *(copy[i++]), INSTEAD OF copy[0][i++], 
        WHICH IS THE EXPRESSION I WANTED.
    */    
}

int     main(void)
{
    char *src;
    char *copy;
    int src_len;

    src = "Hello";
    src_len = strlen(src);
    if (!(copy = (char *)malloc(sizeof(char) * (src_len + 1))))
        return (-1);
    copy[src_len] = 0;
    ft_copy(&copy, src);
    printf("copy: %s\n", copy);
    free(copy);
    return (0);
}