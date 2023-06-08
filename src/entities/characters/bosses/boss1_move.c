/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** boss1_move.c
*/

#include "../../../../include/my.h"

movement_dir_t boss1_change_direction(sfVector2f move)
{
    movement_dir_t dir;

    if (ABSOLUTE_VALUE(move.x) < 2) {
        dir = DOWN;
    } else {
        if (move.x < 0)
            dir = LEFT;
        else
            dir = RIGHT;
    }
    return dir;
}

void move_boss_1(entity_t *boss, game_t *game)
{
    sfVector2f pos = boss->position;
    sfVector2f player_pos = get_player_entity(game)->position;
    sfVector2f move = {0, 0};
    double angle;

    if (pos.y - player_pos.y >= 0) {
        move.y -= 10;
    } else {
        move.y = boss->speed * (player_pos.y - pos.y - 400) / 100;
    }
    move.x = boss->speed * (player_pos.x - pos.x) / 100;
    if (move.x != 0 && move.y != 0) {
        angle = atan2f(move.y, move.x);
        move.x *= ABSOLUTE_VALUE((float)cos(angle));
        move.y *= ABSOLUTE_VALUE((float)sin(angle));
    }
    boss->anim_data->movement_dir = boss1_change_direction(move);
    change_pos(boss, move);
}

void update_boss_1(entity_t *boss, game_t *game)
{
    move_boss_1(boss, game);
    boss1_shoot(game, boss);
}
