/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** set_sprite.c
*/

#include "../../../include/my.h"

void set_sprite_origin(sfSprite *sprite)
{
    sfFloatRect bounds = sfSprite_getLocalBounds(sprite);
    sfVector2f origin = {bounds.width / 2,
                            bounds.height / 2};

    sfSprite_setOrigin(sprite, origin);
}
