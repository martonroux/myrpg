/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** wave_utils.c
*/

#include "../../../include/my.h"

bool enemies_still_alive(game_t *game)
{
    entity_t *actual = game->head_entity->first;

    while (actual) {
        if (actual->type == ENEMY || actual->type == BOSS)
            return true;
        actual = actual->next;
    }
    return false;
}

sfVector2f get_pos_outside_screen(game_t *game)
{
    sfVector2f window_size = sfView_getSize(game->view);
    sfVector2f player_pos = sfView_getCenter(game->view);
    sfVector2f borders = {player_pos.x - window_size.x / 2,
                            player_pos.y - window_size.y / 2};
    sfVector2f res;
    int pos_vert = rand() % 2;
    int pos_hor = rand() % 2;
    int vert_pos = rand() % (int)window_size.y / 6;
    int hor_pos = rand() % (int)window_size.x / 2;

    if (pos_vert == 0)
        res.x = borders.x + (float)hor_pos;
    else
        res.x = borders.x + window_size.x - (float)hor_pos;
    if (pos_hor == 0)
        res.y = borders.y - (float)vert_pos;
    else
        res.y = borders.y + window_size.y + (float)vert_pos;
    return res;
}
