/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** get_damaged.c
*/

#include "../../../../include/my.h"

void player_get_damaged(game_t *game, entity_t *player, float damage)
{
    player->hp -= damage;
}
