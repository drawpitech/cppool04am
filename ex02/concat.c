/*
** EPITECH PROJECT, 2024
** ppool04am
** File description:
** concat
*/

#include <stdlib.h>
#include <string.h>

#include "concat.h"

void concat_strings(const char *str1, const char *str2, char **res)
{
    if (res == NULL || str1 == NULL || str2 == NULL)
        return;
    *res = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    if (*res == NULL)
        return;
    strcpy(*res, str1);
    strcat(*res, str2);
}

void concat_struct(concat_t *str)
{
    concat_strings(str->str1, str->str2, &str->res);
}
