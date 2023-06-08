/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** partial_init_tutorial.c
*/

#include "../../../include/my.h"

tutorial_t *partial_init_tutorial(game_t *game)
{
    tutorial_t *tutorial = my_malloc(sizeof(tutorial_t), game->collector);

    tutorial->shoot_text = NULL;
    tutorial->movements_text = NULL;
    tutorial->is_init = false;
    return tutorial;
}
