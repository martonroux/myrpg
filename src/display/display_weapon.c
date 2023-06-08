/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** display_weapon
*/

#include "../../include/my.h"

int display_weapon(game_t *game)
{
    entity_t *tmp = get_player_entity(game);
    if (tmp->weapon != NULL)
        tmp->weapon->shoot_rate_max = game->stat->fire_rate / 1000;
    return 0;
}
