/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** init_player.c
*/

#include "../../../include/my.h"
#include <SFML/System/Vector2.h>

entity_t *create_player(game_t *game)
{
    entity_t *player = create_single_entity(
        "assets/player_sprite.png",
        PLAYER,
        game->collector,
        &move_player
        );

    create_anim_data(player,
                        (sfIntRect){0, 0, 64, 64},
                        game->collector,
                        &player_animation);
    sfSprite_setScale(player->sprite, (sfVector2f){2, 2});
    sfSprite_setPosition(player->sprite, (sfVector2f){300, 0});
    player->position = (sfVector2f){300, 0};
    return player;
}
