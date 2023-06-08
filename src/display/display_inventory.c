/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui
** File description:
** display_inventory
*/

#include "../../include/my.h"

void display_inventory(game_t *game)
{
    update_inventory(game);
    if (game->inv->is_displayed) {
        for (int i = 0; i < 2; i++)
            sfRenderWindow_drawRectangleShape(game->window,
            game->inv->inv_slot[i], NULL);
    }
    sfRenderWindow_drawRectangleShape(game->window,
        game->item_frame, NULL);
}
