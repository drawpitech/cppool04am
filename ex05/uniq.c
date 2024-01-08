/*
** EPITECH PROJECT, 2024
** ppool04am
** File description:
** uniq
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static
bool is_in_arr(
    const void *array, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *))
{
    const uint8_t *ptr = array;

    for (size_t i = 0; i < nmemb; i++)
        if (compar(ptr + i * size, ptr + nmemb * size) == 0)
            return true;
    return false;
}

static
int compare_int(const void *a, const void *b)
{
    return (*(const int *)a - *(const int *)b);
}

size_t uniq_array(
    void *array, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *))
{
    uint8_t *ptr = array;
    uint8_t *dup = malloc(size * nmemb);
    size_t i = 0;

    memcpy(dup, array, size * nmemb);
    for (size_t j = 0; j < nmemb; j++) {
        if (is_in_arr(dup, j, size, compar))
            continue;
        for (size_t x = 0; x < size; x++)
            ptr[i * size + x] = ptr[j * size + x];
        i += 1;
    }
    return i;
}

size_t uniq_int_array(int *array, size_t nmemb)
{
    return uniq_array(array, nmemb, sizeof(int), &compare_int);
}
