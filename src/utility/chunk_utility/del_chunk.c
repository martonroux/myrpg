/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** remove_chunk.c
*/

#include "../../../include/my.h"

void remove_all_bullet_chunks(head_chunk_t *head_chunk)
{
    bullet_chunk_t *actual = head_chunk->first_bullet;

    while (actual) {
        if (actual->next != NULL) {
            actual = actual->next;
            delete_bullet_chunk(head_chunk, actual->prev);
            continue;
        } else {
            delete_bullet_chunk(head_chunk, actual->prev);
            delete_bullet_chunk(head_chunk, actual);
            return;
        }
    }
}

void remove_all_chunks(head_chunk_t *head_chunk)
{
    chunk_t *actual = head_chunk->first;

    while (actual) {
        if (actual->next != NULL) {
            actual = actual->next;
            delete_chunk(head_chunk, actual->prev);
            continue;
        } else {
            delete_chunk(head_chunk, actual->prev);
            delete_chunk(head_chunk, actual);
            return;
        }
    }
}

void delete_chunk(head_chunk_t *head_chunk, chunk_t *to_del)
{
    if (head_chunk->first == NULL || to_del == NULL)
        return;
    if (head_chunk->first == to_del)
        head_chunk->first = to_del->next;
    if (to_del->next != NULL)
        to_del->next->prev = to_del->prev;
    if (to_del->prev != NULL)
        to_del->prev->next = to_del->next;

    free(to_del);
}

void delete_bullet_chunk(head_chunk_t *head_chunk, bullet_chunk_t *to_del)
{
    if (head_chunk->first_bullet == NULL || to_del == NULL)
        return;
    if (head_chunk->first_bullet == to_del)
        head_chunk->first_bullet = to_del->next;
    if (to_del->next != NULL)
        to_del->next->prev = to_del->prev;
    if (to_del->prev != NULL)
        to_del->prev->next = to_del->next;

    free(to_del);
}
