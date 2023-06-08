/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** chunks_main.c
*/

#include "../../../include/my.h"

void set_chunk_rects(game_t *game)
{
    int nb_chunks = get_nb_chunks(game->head_chunk);
    sfVector2f window_size = sfView_getSize(game->view);
    sfVector2f view_center = sfView_getCenter(game->view);
    sfFloatRect global_rect = {view_center.x - window_size.x / 2,
                                view_center.y - window_size.y / 2,
                                window_size.x / (float)sqrt(nb_chunks),
                                window_size.y / (float)sqrt(nb_chunks)};
    for (int i = 0; i < nb_chunks; i++) {
        game->head_chunk[i]->rect.top = global_rect.top;
        game->head_chunk[i]->rect.left = global_rect.left;
        game->head_chunk[i]->rect.width = global_rect.width;
        game->head_chunk[i]->rect.height = global_rect.height;
        global_rect.left += global_rect.width;
        if (global_rect.left + global_rect.width >
            view_center.x + window_size.x / 2) {
            global_rect.left = view_center.x - (float)window_size.x / 2;
            global_rect.top += global_rect.height;
        }
    }
}

void chunks_main(game_t *game)
{
    entity_t *actual = game->head_entity->first;

    for (int i = 0; game->head_chunk[i]; i++) {
        remove_all_chunks(game->head_chunk[i]);
        remove_all_bullet_chunks(game->head_chunk[i]);
    }
    remove_all_chunks(game->outside_screen);
    remove_all_bullet_chunks(game->outside_screen);
    set_chunk_rects(game);
    assign_chunks(game);
    for (; actual; actual = actual->next) {
        if (actual->weapon && actual->weapon->head_bullet)
            assign_bullet_chunks(game, actual->weapon->head_bullet);
    }
}
