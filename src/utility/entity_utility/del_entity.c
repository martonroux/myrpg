/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** del_entity.c
*/

#include "../../../include/my.h"

void delete_all_entities(head_entity_t *head_entity)
{
    entity_t *actual = head_entity->first;

    while (actual) {
        if (actual->type == ENEMY || actual->type == BOSS
            && actual->next != NULL) {
            actual = actual->next;
            delete_entity(head_entity, actual->prev);
            continue;
        }
        if (actual->type == ENEMY || actual->type == BOSS
            && actual->next == NULL) {
            delete_entity(head_entity, actual);
            return;
        }
        actual = actual->next;
    }
}

void delete_entity(head_entity_t *head_entity, entity_t *to_del)
{
    if (head_entity->first == NULL || to_del == NULL)
        return;
    if (head_entity->first == to_del)
        head_entity->first = to_del->next;
    if (to_del->next != NULL)
        to_del->next->prev = to_del->prev;
    if (to_del->prev != NULL)
        to_del->prev->next = to_del->next;

    free_entity(to_del);
    free(to_del);
}
