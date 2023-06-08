/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** init_state
*/

#include "../../../include/my.h"

void init_stat(game_t *game)
{
    game->stat->explosive = 0;
    game->stat->multishot = 0;
    game->stat->range = 500;
    game->stat->xp = 0;
    game->stat->level = 1;
    game->stat->point = 0;
    game->stat->fire_rate = 10.f;
    game->stat->ability = 0;
}
