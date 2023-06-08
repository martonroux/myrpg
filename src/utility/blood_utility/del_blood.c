/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** del_blood.c
*/

#include "../../../include/my.h"

void delete_blood(head_entity_t *head_entity, blood_node_t *to_del)
{
    blood_node_t *previous = NULL;
    blood_node_t *actual = head_entity->first_blood;

    if (to_del == head_entity->first_blood) {
        head_entity->first_blood = to_del->next;
        return;
    }
    while (actual) {
        if (actual == to_del) {
            previous->next = to_del->next;
            break;
        }
        previous = actual;
        actual = actual->next;
    }
    free_blood(to_del);
    free(to_del);
}
