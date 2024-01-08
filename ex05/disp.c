/*
** EPITECH PROJECT, 2024
** ppool04am
** File description:
** disp
*/

#include <stdint.h>
#include <stdio.h>

void disp_int_array(const int *array, size_t nmemb)
{
    for (size_t i = 0; i < nmemb; i++)
        printf("%d\n", array[i]);
}

void disp_array(
    const void *array, size_t nmemb, size_t size,
    void (*print)(const void *))
{
    const uint8_t *ptr = array;

    for (size_t i = 0; i < nmemb; i++)
        print(ptr + size * i);
}
