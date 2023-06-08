/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** add_chunk.c
*/

#include "../../../include/my.h"

void add_chunk(head_chunk_t *head_chunk, entity_t *data, collector_t *collector)
{
    chunk_t *new = my_malloc(sizeof(chunk_t), collector);
    new->entity = data;
    new->next = head_chunk->first;
    new->prev = NULL;

    if (head_chunk->first != NULL)
        head_chunk->first->prev = new;
    head_chunk->first = new;
}

void add_bullet_chunk(head_chunk_t *head_chunk,
                        bullet_t *data, collector_t *collector)
{
    bullet_chunk_t *new = my_malloc(sizeof(bullet_chunk_t), collector);
    new->bullet = data;
    new->next = head_chunk->first_bullet;
    new->prev = NULL;

    if (head_chunk->first_bullet != NULL)
        head_chunk->first_bullet->prev = new;
    head_chunk->first_bullet = new;
}
