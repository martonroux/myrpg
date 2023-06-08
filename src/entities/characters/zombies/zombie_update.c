/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** main_update.c
*/

#include "../../../../include/my.h"

void zombie_update(entity_t *zombie, game_t *game)
{
    move_zombie(zombie, game);
    damage_zombie(zombie, game);
}
