/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** get_player.c
*/

#include "../../../include/my.h"

entity_t *get_player_entity(game_t *game)
{
    entity_t *actual = game->head_entity->first;

    while (actual != NULL) {
        if (actual->type == PLAYER)
            return actual;
        actual = actual->next;
    }
    return NULL;
}
