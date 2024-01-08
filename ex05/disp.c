/*
** EPITECH PROJECT, 2024
** ppool04am
** File description:
** disp
*/

#include <stdio.h>

void disp_int_array(const int *array, size_t nmemb)
{
    for (size_t i = 0; i < nmemb; i++)
        printf("%d\n", array[i]);
}
