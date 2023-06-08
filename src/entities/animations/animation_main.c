/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** animation_main.c
*/

#include "../../../include/my.h"

void animation_main(game_t *game)
{
    entity_t *actual = game->head_entity->first;
    blood_node_t *blood_node = game->head_entity->first_blood;
    sfTime time = sfClock_getElapsedTime(game->animation_timer);
    float seconds = (float)time.microseconds / 1000000.0f;

    if (seconds < 0.1)
        return;
    sfClock_restart(game->animation_timer);
    while (actual != NULL) {
        if (actual->anim_data == NULL || actual->anim_data->anim_func == NULL) {
            actual = actual->next;
            continue;
        }
        actual->anim_data->anim_func(actual, actual->anim_data->anim_rect,
                                        actual->anim_data->full_size);
        actual = actual->next;
    }
    for (; blood_node; blood_node = blood_node->next)
        blood_animation(blood_node);
}
