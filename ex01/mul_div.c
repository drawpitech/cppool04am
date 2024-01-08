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
    if (a == NULL || b == NULL)
        return;
    mul_div_long(*a, *b, a, b);
}
