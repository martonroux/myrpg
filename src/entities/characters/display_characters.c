/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** display_players.c
*/
#include "../../../include/my.h"

void display_characters(game_t *game)
{
    entity_t *actual = game->head_entity->first;

    move_characters_main(game);
    while (actual) {
        if (actual->is_visible == 1)
            sfRenderWindow_drawSprite(game->window, actual->sprite, NULL);
        actual = actual->next;
    }
}
