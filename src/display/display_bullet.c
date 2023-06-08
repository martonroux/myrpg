/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** display_bullet
*/

#include "../../include/my.h"

void display_bullet_head(head_bullet_t *head_bullet, game_t *game)
{
    bullet_t *bullet = head_bullet->first;

    while (bullet != NULL) {
        if (bullet->is_visible)
            sfRenderWindow_drawSprite(game->window, bullet->sprite, NULL);
        bullet = bullet->next;
    }
}

int display_bullet(game_t *game)
{
    entity_t *actual = game->head_entity->first;

    while (actual) {
        if (actual->weapon && actual->weapon->head_bullet)
            display_bullet_head(actual->weapon->head_bullet, game);
        actual = actual->next;
    }
    return 0;
}
