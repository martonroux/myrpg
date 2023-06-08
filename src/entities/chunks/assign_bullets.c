/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** assign_bullets.c
*/

#include "../../../include/my.h"

int *check_containing_bullet_chunk(
    head_chunk_t **p_head_chunk,
    bullet_t *entity,
    int nb_chunks,
    collector_t *collector
)
{
    sfVector2f pos = entity->position;
    int *all = my_malloc(sizeof(int) * nb_chunks, collector);

    for (int i = 0; i < nb_chunks; i++)
        all[i] = 0;
    for (int i = 0; p_head_chunk[i]; i++) {
        if (sfFloatRect_contains(&(p_head_chunk[i]->rect), pos.x, pos.y))
            all[i] = 1;
    }
    return all;
}

void conditionnal_add_bullet_chunk(
    head_chunk_t *head_chunk,
    bullet_t *data,
    collector_t *collector,
    int nb
)
{
    if (nb == 1)
        add_bullet_chunk(head_chunk, data, collector);
}

void assign_bullet_chunks(game_t *game, head_bullet_t *head_bullet)
{
    bullet_t *actual = head_bullet->first;
    int nb_chunks = get_nb_chunks(game->head_chunk);
    int *nb;
    bool found = false;
    for (; actual; actual = actual->next) {
        nb = check_containing_bullet_chunk(game->head_chunk,
                                    actual, nb_chunks, game->collector);
        for (int j = 0; j < nb_chunks; j++) {
            conditionnal_add_bullet_chunk(game->head_chunk[j],
                                    actual, game->collector, nb[j]);
            found = (nb[j] == 1) ? true : found;
        }
        if (found == false) {
            add_bullet_chunk(game->outside_screen, actual, game->collector);
            actual->is_visible = false;
        } else {
            actual->is_visible = true;
        }
        found = false;
    }
}
