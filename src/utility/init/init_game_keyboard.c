/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** init_game_keyboard
*/

#include "../../../include/my.h"

void init_game_keyboard(game_t *game)
{
    game->keyboard = my_malloc(sizeof(keyboard_t), game->collector);
    game->keyboard->isHeld = my_malloc(sizeof(bool) * 128, game->collector);
    game->keyboard->is_clicked_once =
            my_malloc(sizeof(bool) * 128, game->collector);
}
