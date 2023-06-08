/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** damage_zombie.c
*/

#include "../../../../include/my.h"

void damage_zombie(entity_t *zombie, game_t *game)
{
    entity_t *player = get_player_entity(game);
    double delta = get_vector_delta(zombie->position, player->position);
    sfTime time = sfClock_getElapsedTime(zombie->weapon->shoot_clock);
    float seconds = (float)time.microseconds / 1000000.0f;

    if (seconds < zombie->weapon->shoot_rate)
        return;
    if (delta < zombie->weapon->shoot_distance) {
        player_get_damaged(game, player, zombie->weapon->damage);
        sfClock_restart(zombie->weapon->shoot_clock);
    }
}
