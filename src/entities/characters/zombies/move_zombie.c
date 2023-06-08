/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** move_zombie.c
*/

#include "../../../../include/my.h"

double check_zombie_collide(entity_t *zombie, entity_t *actual, sfVector2f move)
{
    if (actual == zombie || actual->type == PLAYER) return 0;
    sfVector2f zombie_pos = {zombie->position.x + move.x,
                                zombie->position.y + move.y};
    sfVector2f sec_pos = actual->position;
    float delta_x;
    float delta_y;
    float zombie_angle = atan2f(move.y, move.x);
    double delta_angle = PI / 4;
    double delta_tot;
    double angle;
    int sep = 100;

    delta_x = sec_pos.x - zombie_pos.x;
    delta_y = sec_pos.y - zombie_pos.y;
    delta_tot = get_vector_delta(zombie_pos, sec_pos);
    angle = atan2f(delta_y, delta_x);
    if (zombie_angle + delta_angle > angle &&
        zombie_angle - delta_angle < angle && delta_tot < sep)
        return delta_tot;
    return 0;
}

sfVector2f get_zombie_move_outside(
    entity_t *zombie,
    game_t *game,
    sfVector2f move
    )
{
    chunk_t *actual = game->outside_screen->first;
    double delta;

    while (actual) {
        if ((delta = check_zombie_collide(zombie, actual->entity, move)) != 0) {
            move.x *= (float)delta / 100;
            move.y *= (float)delta / 100;
        }
        actual = actual->next;
    }
    return move;
}

sfVector2f get_zombie_move_chunk(
    entity_t *zombie,
    game_t *game,
    sfVector2f move,
    int chunk
    )
{
    chunk_t *actual = game->head_chunk[chunk]->first;
    double delta;

    while (actual) {
        if ((delta = check_zombie_collide(zombie, actual->entity, move)) != 0) {
            move.x *= (float)delta / 100;
            move.y *= (float)delta / 100;
        }
        actual = actual->next;
    }
    return move;
}

sfVector2f get_zombie_move(entity_t *zombie, game_t *game, sfVector2f move)
{
    int *chunk_nb = zombie->chunks;

    if (chunk_nb == NULL) {
        return get_zombie_move_outside(zombie, game, move);
    }
    for (int i = 0; i < get_nb_chunks(game->head_chunk); i++) {
        if (chunk_nb[i] == 0)
            continue;
        move = get_zombie_move_chunk(zombie, game, move, i);
    }
    return move;
}

void move_zombie(entity_t *zombie, game_t *game)
{
    entity_t *player = get_player_entity(game);
    if (player == NULL) return;
    float angle = atan2f(player->position.y - zombie->position.y,
                            player->position.x - zombie->position.x);
    sfVector2f move = {zombie->speed * cosf(angle),
                        zombie->speed * sinf(angle)};

    move = get_zombie_move(zombie, game, move);
    zombie->anim_data->movement_dir = change_direction(move);
    change_pos(zombie, move);
}
