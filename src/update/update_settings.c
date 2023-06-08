/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui
** File description:
** update_settings.c
*/

#include "../../include/my.h"

void update_settings(game_t *game)
{
    sfVector2u window_size = sfRenderWindow_getSize(game->window);

    sfView_setSize(game->view, (sfVector2f){window_size.x, window_size.y});
    update_camera(game);
    sfRenderWindow_clear(game->window, sfBlack);
    update_text(game);
    display_text(game);
    check_event_settings(game);
    sfRenderWindow_display(game->window);
}
