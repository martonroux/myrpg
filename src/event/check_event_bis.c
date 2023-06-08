/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui
** File description:
** check_event_bis.c
*/

#include "../../include/my.h"

int get_index_resolution(game_t *game)
{
    sfVector2f view_size = game->view_size;

    if (view_size.x == 720 && view_size.y == 480) return 1;
    if (view_size.x == 1280 && view_size.y == 720) return 2;
    if (view_size.x == 1920 && view_size.y == 1080) return 3;
    if (view_size.x == 2560 && view_size.y == 1440) return 4;
    if (view_size.x == 3264 && view_size.y == 1948) return 5;
    return -1;
}
