/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** is_linked_list
*/

#include "../../../include/my.h"

linked_list_t *create_linked_list(void *data)
{
    linked_list_t *list = malloc(sizeof(linked_list_t));

    if (list == NULL)
        return NULL;
    list->head = list;
    list->data = data;
    list->prev = NULL;
    list->next = NULL;
    return list;
}

void append_list(linked_list_t *list, void *data)
{
    linked_list_t *tmp = list;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(linked_list_t));
    tmp->next->head = list;
    tmp->next->data = data;
    tmp->next->prev = tmp;
    tmp->next->next = NULL;
}

void remove_list(linked_list_t *list, void *data)
{
    linked_list_t *tmp = list;
    if (list->data == data) {
        list->data = list->next->data;
        list->next = list->next->next;
        list->head = list;
        free(tmp);
        return;
    }

    while (tmp->next != NULL) {
        if (tmp->data == data) {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);
            return;
        }
        tmp = tmp->next;
    }
}
