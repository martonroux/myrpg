/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** display_text
*/

#include "../../include/my.h"

void display_text(game_t *game)
{
    texts_t *tmp = NULL;

    switch (game->state) {
        case STATE_MENU:
            tmp = game->game_menu->texts; break;
        case STATE_GAME:
            tmp = game->texts; break;
        case STATE_SETTINGS:
            tmp = game->settings_menu->texts; break;
    }
    while (tmp != NULL) {
        if (tmp->selected == true)
            sfText_setColor(tmp->text, sfGreen);
        else
            sfText_setColor(tmp->text, sfWhite);
        sfRenderWindow_drawText(game->window, tmp->text, NULL);
        sfRenderWindow_drawRectangleShape(game->window, tmp->rect, NULL);
        tmp = tmp->next;
    }
}

void display_wave(game_t *game, sfVector2f play_pos, sfVector2f size_window)
{
    sfFloatRect bounds = sfText_getGlobalBounds(game->background->wave);
    sfVector2f position = {play_pos.x + size_window.x / 2 - bounds.width - 10,
                            play_pos.y - size_window.y / 2 + bounds.height};
    char *print;
    char *str_int;

    str_int = into_str(game->wave_data->wave_nb);
    print = my_strcat("Wave:  ", str_int);
    sfText_setString(game->background->wave, print);
    sfText_setPosition(game->background->wave, position);
    sfRenderWindow_drawText(game->window, game->background->wave, NULL);
    free(print);
    free(str_int);
}
