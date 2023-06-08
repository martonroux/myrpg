/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** update_text
*/

#include "../../include/my.h"

void update_text(game_t *game)
{
    sfVector2f center = sfView_getCenter(game->view);
    sfVector2f size = sfView_getSize(game->view);
    sfVector2f new_pos;
    texts_t *tmp = game->game_menu->texts;

    switch (game->state) {
        case STATE_GAME:
            tmp = game->texts;
            break;
        case STATE_SETTINGS:
            tmp = game->settings_menu->texts;
            break;
    }
    for (int i = 0; tmp != NULL; tmp = tmp->next, i++) {
        new_pos.x = center.x - size.x / 2 + 50;
        if (game->state == STATE_SETTINGS && tmp->id > 0 && tmp->id < 6)
            new_pos.x += 200;
        new_pos.y = center.y - size.y / 2 + 50 + (float)(100 * i);
        sfText_setPosition(tmp->text, new_pos);
    }
}
