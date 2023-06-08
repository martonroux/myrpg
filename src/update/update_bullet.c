/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** update_bullet
*/

#include "../../include/my.h"

void delete_bullet(head_bullet_t *head_bullet, bullet_t *bullet,
                    bullet_t *previous)
{
    if (bullet != NULL && (bullet->range <= 0 || bullet->is_dead == true)) {
        if (previous == NULL) {
            head_bullet->first = bullet->next;
            return;
        }
        previous->next = bullet->next;
    }
}

void update_special_bullet(game_t *game, bullet_t *bullet)
{
    if (bullet->stat == NULL)
        return;
    update_explosive(game, bullet);
}

void update_bullet_head(head_bullet_t *head_bullet, game_t *game)
{
    bullet_t *bullet = head_bullet->first;
    bullet_t *previous = NULL;

    while (bullet != NULL) {
        if (bullet->sprite != NULL) {
            bullet->position.x += bullet->direction.x * bullet->speed;
            bullet->position.y += bullet->direction.y * bullet->speed;
            sfSprite_setPosition(bullet->sprite, bullet->position);
            bullet->range -= bullet->speed;
        }
        if (bullet->shooter_type == PLAYER)
            update_special_bullet(game, bullet);
        delete_bullet(head_bullet, bullet, previous);
        previous = bullet;
        bullet = bullet->next;
    }
}

int update_bullet(game_t *game)
{
    entity_t *actual = game->head_entity->first;

    while (actual) {
        if (actual->weapon && actual->weapon->head_bullet)
            update_bullet_head(actual->weapon->head_bullet, game);
        actual = actual->next;
    }
    return 0;
}
