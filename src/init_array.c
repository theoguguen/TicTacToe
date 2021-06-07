/*
** EPITECH PROJECT, 2021
** TicTacToe
** File description:
** init_array
*/

#include "stumper.h"

void *bcalloc(size_t nmemb, size_t size)
{
    void *result = malloc(nmemb * size);

    if (result) {
        bmemset(result, 32, nmemb * size);
    }
    return result;
}

char **binit_array(size_t x, size_t y)
{
    char **array = binit_array_light(x);

    if (!array)
        return NULL;
    for (size_t i = 0; i < x; i++) {
        array[i] = bcalloc(sizeof(char), y + 1);
        array[i][y] = '\0';
        if (!array[i])
            return NULL;
    }
    array[x] = NULL;
    return array;
}

char **binit_array_light(size_t x)
{
    char **array = bcalloc(sizeof(char *), x + 1);

    if (!array)
        return NULL;
    array[x] = NULL;
    return array;
}

void *bmemset(void *s, int c, size_t n)
{
    unsigned char *ptr = s;

    for (size_t i = 0; i < n; i++) {
        *ptr = c;
        ptr++;
    }
    return s;
}

void bfree_array(char **src)
{
    if (!src)
        return;
    for (size_t i = 0; src[i]; i++) {
        free(src[i]);
    }
    free(src);
}