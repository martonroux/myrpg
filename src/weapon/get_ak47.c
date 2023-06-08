/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** get_ak47
*/

#include "../../include/my.h"

sfSprite *create_sprite(char *path, sfVector2f scale, sfVector2f pos)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

int get_ak47(game_t *game)
{
    entity_t *tmp = get_player_entity(game);

    tmp->weapon = my_malloc(sizeof(weapon_t), game->collector);
    tmp->weapon->damage = 5;
    tmp->weapon->shoot_rate = game->stat->fire_rate;
    tmp->weapon->shoot_distance = 200;
    tmp->weapon->sprite = create_sprite("assets/ak47.png",
        (sfVector2f){0.1f, 0.1f}, (sfVector2f){0, 0});
    tmp->weapon->sprite_bullet = create_sprite("assets/test.png",
        (sfVector2f){1.5f, 1.5f}, (sfVector2f){0, 0});
    tmp->weapon->shoot_rate_max = 1.f;
    tmp->weapon->head_bullet =
            my_malloc(sizeof(head_bullet_t), game->collector);
    tmp->weapon->head_bullet->first = NULL;
    set_sprite_origin(tmp->weapon->sprite);
    return 0;
}
