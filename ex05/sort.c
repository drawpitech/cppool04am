/*
** EPITECH PROJECT, 2024
** ppool04am
** File description:
** sort
*/

#include <stdint.h>
#include <stdlib.h>

static
void my_swap(void *left, void *right, size_t size)
{
    uint8_t *l_ptr = left;
    uint8_t *r_ptr = right;
    uint8_t tmp;

    for (uint32_t i = 0; i < size; i++) {
        tmp = l_ptr[i];
        l_ptr[i] = r_ptr[i];
        r_ptr[i] = tmp;
    }
}

static
size_t get_pivot(
    uint8_t *ptr, size_t nmemb, size_t size,
    int (*cmp) (const void *, const void *))
{
    uint8_t *pivot = ptr + (nmemb - 1) * size;
    size_t i = 0;

    for (uint8_t *j = ptr; j < pivot; j += size) {
        if (cmp(j, pivot) < 0) {
            my_swap(ptr + (i * size), j, size);
            i += 1;
        }
    }
    my_swap(ptr + (i * size), pivot, size);
    return i;
}

static
void my_qsort(
    void *arr, size_t nmemb, size_t size,
    int (*compar) (const void *, const void *))
{
    uint8_t *ptr = arr;
    size_t pi;

    if (nmemb <= 1)
        return;
    pi = get_pivot(ptr, nmemb, size, compar);
    my_qsort(ptr, pi, size, compar);
    my_qsort(ptr + (pi + 1) * size, nmemb - (pi + 1), size, compar);
}

static
int compare_int(const void *a, const void *b)
{
    return (*(const int *)a - *(const int *)b);
}

void sort_int_array(int *array, size_t nmemb)
{
    my_qsort(array, nmemb, sizeof(int), &compare_int);
}

void sort_array(
    void *array, size_t nmemb, size_t size,
    int (*compar) (const void *, const void *))
{
    my_qsort(array, nmemb, size, compar);
}
