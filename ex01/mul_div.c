/*
** EPITECH PROJECT, 2024
** ppool04am
** File description:
** z
*/

#include <stdlib.h>

void mul_div_long(int a, int b, int *mul, int *div)
{
    if (mul != NULL)
        *mul = a * b;
    if (div != NULL)
        *div = (b) ? a / b : 42;
}

void mul_div_short(int *a, int *b)
{
    int res;

    if (a == NULL || b == NULL)
        return;
    res = (*b) ? *a / *b : 42;
    *a = res;
    *b = res;
}
