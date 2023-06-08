/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** init_chunks.c
*/

#include "../../../include/my.h"

head_chunk_t *init_outside_screen(collector_t *collector)
{
    head_chunk_t *head_chunk = my_malloc(sizeof(head_chunk_t), collector);

    head_chunk->first = NULL;
    head_chunk->first_bullet = NULL;
    return head_chunk;
}

head_chunk_t **init_head_chunks(game_t *game)
{
    head_chunk_t **p_head_chunk = my_malloc(sizeof(head_chunk_t *) * 37,
                                                game->collector);
    sfFloatRect base = {0, 0, 1, 1};

    for (int i = 0; i < 36; i++) {
        p_head_chunk[i] = my_malloc(sizeof(head_chunk_t), game->collector);
        p_head_chunk[i]->first = NULL;
        p_head_chunk[i]->first_bullet = NULL;
        p_head_chunk[i]->rect = base;
    }
    p_head_chunk[36] = NULL;
    return p_head_chunk;
}
