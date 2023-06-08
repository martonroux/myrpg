/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** update_camera
*/

#include "../../include/my.h"

int update_camera(game_t *game)
{
    sfVector2f view_size = sfView_getSize(game->view);
    entity_t *tmp = get_player_entity(game);

    if (tmp->position.x < view_size.x / 2)
        sfView_setCenter(game->view,
                            (sfVector2f){view_size.x / 2, tmp->position.y});
    else if (tmp->position.x > 3264 - view_size.x / 2)
        sfView_setCenter(game->view,
                            (sfVector2f)
                                {3264 - view_size.x / 2, tmp->position.y});
    else
        sfView_setCenter(game->view,tmp->position);
    sfRenderWindow_setView(game->window, game->view);
    return 0;
}
