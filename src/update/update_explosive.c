/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** update_explosive
*/

#include "../../include/my.h"

void update_explosive(game_t *game, bullet_t *bullet)
{
    int bullet_max = bullet->stat->explosive;
    weapon_t *weapon = get_player_entity(game)->weapon;
    sfVector2f direction = {0, 0};

    if (bullet->stat->explosive > 0 && bullet->range <= 0) {
        for (int i = 0; i < bullet_max; i++) {
            direction.x = cos(i *
                (float) (360 / bullet_max) * M_PI / 180);
            direction.y = sin( i *
            (float) (360 / bullet_max) * M_PI / 180);
            create_mini_bullet(game, bullet->position,
                weapon, direction);
        }
    }
}
