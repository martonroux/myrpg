/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** get_nb_entities.c
*/

#include "../../../include/my.h"

int get_nb_entities(game_t *game)
{
    entity_t *actual = game->head_entity->first;
    int nb = 0;

    while (actual) {
        nb++;
        actual = actual->next;
    }
    return nb;
}

int get_nb_enemies(game_t *game)
{
    entity_t *actual = game->head_entity->first;
    int nb = 0;

    while (actual) {
        if (actual->type == ENEMY)
            nb++;
        actual = actual->next;
    }
    return nb;
}
