/*
** EPITECH PROJECT, 2023
** display_background
** File description:
** rpg
*/

#include "../../include/my.h"

void display_background(game_t *game)
{
    entity_t *player = get_player_entity(game);
    back_window_t *tmp = game->background;

    if (player->position.y > game->background->position.y + 1230) {
        for (; tmp != NULL; tmp = tmp->next) {
            tmp->position.y += 2460;
            sfSprite_setPosition(tmp->s_fond, tmp->position);
        }
    }
    if (player->position.y < game->background->position.y - 1230) {
        for (; tmp != NULL; tmp = tmp->next) {
            tmp->position.y -= 2460;
            sfSprite_setPosition(tmp->s_fond, tmp->position);
        }
    }
    for (tmp = game->background; tmp != NULL; tmp = tmp->next)
        sfRenderWindow_drawSprite(game->window, tmp->s_fond, NULL);
}
