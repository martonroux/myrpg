/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** kill_zombie.c
*/

#include "../../../../include/my.h"

void kill_zombie(game_t *game, entity_t *entity)
{
    if (entity->hp > 0)
        return;

    if (entity->type == ENEMY)
        game->stat->xp += 1;
    if (entity->type == BOSS)
        game->stat->xp += 100;
    add_blood(game->head_entity, entity->position, game->saved_sprites);
    delete_entity(game->head_entity, entity);
    if (game->quest != NULL && game->quest->type == KILL_ZOMBIES
            && game->quest->quest_nb > 0) {
        game->quest->quest_nb -= 1;
    }
}
