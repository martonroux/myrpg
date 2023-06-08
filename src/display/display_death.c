/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui
** File description:
** display_death.c
*/

#include "../../include/my.h"

void display_death(game_t *game)
{
    sfFloatRect rect = sfText_getGlobalBounds(game->death_text);
    sfVector2f view_center = sfView_getCenter(game->view);
    sfVector2f new_pos = {view_center.x - rect.width / 2, view_center.y};
    sfTime time = sfClock_getElapsedTime(game->death_clock);
    float seconds = (float)time.microseconds / 1000000.0f;

    if (seconds < 2 && game->has_died == true) {
        sfText_setPosition(game->death_text, new_pos);
        sfRenderWindow_drawText(game->window, game->death_text, NULL);
    } else {
        game->has_died = false;
    }
}
