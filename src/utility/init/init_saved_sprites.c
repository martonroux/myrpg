/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** init_saved_sprites.c
*/

#include "../../../include/my.h"

saved_sprites_t *init_saved_sprites(game_t *game)
{
    saved_sprites_t *saved_sprites =
            my_malloc(sizeof(saved_sprites_t), game->collector);

    saved_sprites->zombie_texture =
            sfTexture_createFromFile("assets/zombie_asset.png", NULL);
    saved_sprites->zombie = sfSprite_create();
    sfSprite_setTexture(saved_sprites->zombie,
                            saved_sprites->zombie_texture, sfTrue);

    saved_sprites->blood_texture =
            sfTexture_createFromFile("assets/blood_burst.png", NULL);
    saved_sprites->blood = sfSprite_create();
    sfSprite_setTexture(saved_sprites->blood,
                            saved_sprites->blood_texture, sfTrue);
    sfSprite_setScale(saved_sprites->blood, (sfVector2f){0.6f, 0.6f});
    return saved_sprites;
}
