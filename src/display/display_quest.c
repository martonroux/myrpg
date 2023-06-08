/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** display_quest
*/

#include "../../include/my.h"

void set_quest_position(game_t *game)
{
    sfVector2f center = sfView_getCenter(game->view);
    sfVector2f size = sfView_getSize(game->view);
    sfVector2f pos = {center.x - size.x / 2, center.y + size.y / 3};

    sfText_setPosition(game->quest->text, pos);
}

void display_quest(game_t *game)
{
    if (game->quest->state == ACTIVE_QUEST) {
        set_quest_position(game);
        sfRenderWindow_drawText(game->window, game->quest->text, NULL);
    }
}
