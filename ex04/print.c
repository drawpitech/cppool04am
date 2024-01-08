/*
** EPITECH PROJECT, 2024
** ppool04am
** File description:
** print
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "print.h"

void print_normal(const char *str)
{
    printf("%s\n", (str == NULL) ? "(null)" : str);
}

void print_reverse(const char *str)
{
    size_t len = (str == NULL) ? 0 : strlen(str);
    char tmp[len + 1];

    if (str == NULL) {
        printf("(null)\n");
        return;
    }
    for (size_t i = 0; i < len; i++)
        tmp[i] = str[len - i - 1];
    tmp[len - 1] = '\0';
    print_normal(tmp);
}

void print_upper(const char *str)
{
    size_t len = (str == NULL) ? 0 : strlen(str);
    char tmp[len + 1];

    if (str == NULL) {
        printf("(null)\n");
        return;
    }
    for (size_t i = 0; i < len; i++)
        tmp[i] = (char)toupper(str[i]);
    tmp[len - 1] = '\0';
    print_normal(tmp);
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    func_t f = ACTIONS[action];

    if (f != NULL)
        f(str);
}
