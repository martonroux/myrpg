/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui
** File description:
** update_death.c
*/

#include "../../include/my.h"

void update_death(game_t *game)
{
    entity_t *player = get_player_entity(game);

    game->has_died = true;
    game->wave_data = init_wave_data();
    sfSprite_setPosition(player->sprite, (sfVector2f){300, 0});
    player->position = (sfVector2f){300, 0};
    player->is_visible = 1;
    player->chunks = NULL;
    player->hp = 10.f;
    delete_all_entities(game->head_entity);
    sfClock_restart(game->death_clock);
    init_stat(game);
    get_ak47(game);
}
