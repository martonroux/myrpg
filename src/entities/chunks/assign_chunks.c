/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** assign_chunks.c
*/

#include "../../../include/my.h"

int *check_containing_chunk(
    head_chunk_t **p_head_chunk,
    entity_t *entity,
    int nb_chunks,
    collector_t *collector
    )
{
    sfFloatRect size = sfSprite_getGlobalBounds(entity->sprite);
    int *all = my_malloc(sizeof(int) * (nb_chunks), collector);

    for (int i = 0; i < nb_chunks; i++)
        all[i] = 0;
    for (int i = 0; p_head_chunk[i]; i++) {
        if (sfFloatRect_contains(&(p_head_chunk[i]->rect), size.left, size.top))
            all[i] = 1;
        if (sfFloatRect_contains(&(p_head_chunk[i]->rect),
                                    size.left + size.width, size.top))
            all[i] = 1;
        if (sfFloatRect_contains(&(p_head_chunk[i]->rect),
                                    size.left, size.top + size.height))
            all[i] = 1;
        if (sfFloatRect_contains(&(p_head_chunk[i]->rect),
                                    size.left + size.width,
                                        size.top + size.height))
            all[i] = 1;
    }
    return all;
}

void conditionnal_add_chunk(
    head_chunk_t *head_chunk,
    entity_t *data,
    collector_t *collector,
    int nb
    )
{
    if (nb == 1) {
        add_chunk(head_chunk, data, collector);
    }
}

void conditionnal_add_entity(game_t *game, entity_t *actual,
                                int *nb, bool found)
{
    if (found == false) {
        add_chunk(game->outside_screen, actual, game->collector);
        actual->chunks = NULL;
        actual->is_visible = 0;
    } else {
        actual->chunks = nb;
        actual->is_visible = 1;
    }
}

void assign_chunks(game_t *game)
{
    entity_t *actual = game->head_entity->first;
    int nb_chunks = get_nb_chunks(game->head_chunk);
    int *nb;
    bool found = false;
    for (; actual; actual = actual->next) {
        nb = check_containing_chunk(game->head_chunk,
                                    actual, nb_chunks, game->collector);
        for (int j = 0; j < nb_chunks; j++) {
            conditionnal_add_chunk(game->head_chunk[j],
                                    actual, game->collector, nb[j]);
            found = (nb[j] == 1) ? true : found;
        }
        conditionnal_add_entity(game, actual, nb, found);
        found = false;
    }
}
