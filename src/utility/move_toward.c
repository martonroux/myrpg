/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** move_toward
*/

#include "../../include/my.h"

sfVector2f get_direction_toward(sfSprite *bullet,
                                    sfVector2f pos, sfVector2f target)
{
    sfVector2f dir = {target.x - pos.x, target.y - pos.y};
    float angle = atan2(dir.y, dir.x);

    if (dir.x == 0 && dir.y == 0)
        return (sfVector2f){0, 0};
    dir.x = cos(angle);
    dir.y = sin(angle);
    sfSprite_setRotation(bullet, angle * 180 / PI + 90);
    return dir;
}
