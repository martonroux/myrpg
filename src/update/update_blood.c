/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** update_blood.c
*/

#include "../../include/my.h"

void update_blood(game_t *game)
{
    entity_t *player = get_player_entity(game);
    blood_node_t *actual = game->head_entity->first_blood;
    blood_node_t *tmp;

    while (actual) {
        if (actual->is_dead == true) {
            tmp = actual->next;
            delete_blood(game->head_entity, actual);
            actual = tmp;
            continue;
        }
        sfRenderWindow_drawSprite(game->window, actual->sprite, NULL);
        actual = actual->next;
    }
    if (player->hp <= 0)
        update_death(game);
    display_death(game);
}
