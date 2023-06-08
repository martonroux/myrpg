/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui
** File description:
** init_inv
*/

#include "my.h"

void init_item_frames(game_t *game, sfTexture *bullet, sfTexture *bullet2)
{
    for (int i = 0; i < 2; i++) {
        game->inv->inv_slot[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(game->inv->inv_slot[i],
        (sfVector2f) {100, 100});
        sfRectangleShape_setOutlineColor(game->inv->inv_slot[i], sfBlack);
        sfRectangleShape_setOutlineThickness(game->inv->inv_slot[i], 3);
        if (i == 0) {
            sfRectangleShape_setTexture(game->inv->inv_slot[i],
            bullet, sfTrue);
            sfRectangleShape_setFillColor(game->inv->inv_slot[i],
        (sfColor){255, 255, 255, 255});
            sfRectangleShape_setOutlineColor(game->inv->inv_slot[i], sfWhite);
        } else {
            sfRectangleShape_setTexture(game->inv->inv_slot[i],
            bullet2, sfTrue);
            sfRectangleShape_setFillColor(game->inv->inv_slot[i],
        (sfColor){90, 90, 90, 255});
        }
    }
}

void init_inventory(game_t *game)
{
    game->inv = malloc(sizeof(inventory_t));
    game->inv->inv_slot = malloc(sizeof(sfRectangleShape *) * 2);
    sfTexture *bullet = sfTexture_createFromFile("assets/test.png",
    NULL);
    sfTexture *bullet2 = sfTexture_createFromFile("assets/test2.png", NULL);
    game->item_frame = sfRectangleShape_create();
    game->inv->is_displayed = false;
    game->stat->ability = 0;
    sfRectangleShape_setPosition(game->item_frame,
    (sfVector2f) {sfRenderWindow_getSize(game->window).x / 2 - 50,
    sfRenderWindow_getSize(game->window).y / 2});
    sfRectangleShape_setSize(game->item_frame,
    (sfVector2f){100, 100});
    sfRectangleShape_setFillColor(game->item_frame,
    (sfColor){255, 255, 255, 255});
    sfRectangleShape_setOutlineColor(game->item_frame, sfWhite);
    sfRectangleShape_setOutlineThickness(game->item_frame, 3);
    sfRectangleShape_setTexture(game->item_frame, bullet, sfTrue);
    init_item_frames(game, bullet, bullet2);
}
