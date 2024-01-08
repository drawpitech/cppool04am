/*
** EPITECH PROJECT, 2024
** ppool04am
** File description:
** uniq
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static
bool is_in_arr(const int *array, size_t nmemb, int value)
{
    for (size_t i = 0; i < nmemb; i++)
        if (array[i] == value)
            return true;
    return false;
}

size_t uniq_int_array(int *array, size_t nmemb)
{
    int *dup = malloc(sizeof(int) * nmemb);
    size_t i = 0;

    memcpy(dup, array, sizeof(int) * nmemb);
    for (size_t j = 0; j < nmemb; j++) {
        if (!is_in_arr(dup, j, array[j])) {
            array[i] = array[j];
            i += 1;
        }
    }
    return i;
}
