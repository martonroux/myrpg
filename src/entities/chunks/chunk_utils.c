/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** chunk_utils.c
*/

#include "../../../include/my.h"

int get_nb_chunks(head_chunk_t **p_head_chunk)
{
    int len;

    for (len = 0; p_head_chunk[len]; len++);
    return len;
}
