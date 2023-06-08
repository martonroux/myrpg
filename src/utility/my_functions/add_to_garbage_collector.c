/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** my_malloc
*/

#include "../../../include/my.h"

collector_t* create_garbage_collector(void)
{
    collector_t* collector = malloc(sizeof(collector_t));
    collector->next = NULL;
    collector->ptr = NULL;
    return collector;
}

int add_to_garbage_collector(void *ptr, collector_t *collector)
{
    collector_t *new = malloc(sizeof(collector_t));
    collector_t *tmp = collector;

    if (collector == NULL)
        return 84;
    if (collector->ptr == NULL) {
        collector->ptr = ptr;
        return 0;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    new->ptr = ptr;
    new->next = NULL;
    return 0;
}

int free_garbage_collector(collector_t *collector)
{
    collector_t *tmp = collector;

    while (tmp != NULL) {
        free(tmp->ptr);
        tmp = tmp->next;
    }
    free(collector);
    return 0;
}
