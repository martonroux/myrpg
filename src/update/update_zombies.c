/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** update_zombies.c
*/

#include "../../include/my.h"

void update_zombie(game_t *game)
{
    entity_t *actual = game->head_entity->first;
    entity_t *tmp;

    while (actual) {
        if (actual->type == BOSS)
            display_life_boss(actual, game);
        if (actual->type == ENEMY || actual->type == BOSS) {
            tmp = actual->next;
            kill_zombie(game, actual);
            actual = tmp;
            continue;
        }
        actual = actual->next;
    }
}
