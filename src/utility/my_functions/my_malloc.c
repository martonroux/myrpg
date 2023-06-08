/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** my_malloc
*/

#include "../../../include/my.h"

void *my_malloc(size_t size, collector_t *collector)
{
    void *ptr = malloc(size);

    if (ptr == NULL)
        return NULL;
    add_to_garbage_collector(ptr, collector);
    return ptr;
}
