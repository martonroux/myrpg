/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** add_entity
*/

#include "../../../include/my.h"

void add_entity(head_entity_t *head_entity, entity_t *new)
{
    new->next = head_entity->first;
    new->prev = NULL;

    if (head_entity->first != NULL)
        head_entity->first->prev = new;
    head_entity->first = new;
}
