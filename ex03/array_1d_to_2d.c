/*
** EPITECH PROJECT, 2024
** ppool04am
** File description:
** array_1d_to_2d
*/

#include <stdlib.h>
#include <string.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    if (res == NULL || array == NULL)
        return;
    *res = malloc(sizeof(int *) * height);
    for (size_t i = 0; i < height; i++) {
        (*res)[i] = malloc(sizeof(int) * width);
        memcpy((*res)[i], array + (i * width), width * sizeof(int));
    }
}

void array_2d_free(int **array, size_t height, size_t width)
{
    if (array == NULL)
        return;
    for (size_t i = 0; i < height; i++)
        if (array[i] != NULL)
            free(array[i]);
    free(array);
}
