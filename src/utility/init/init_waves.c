/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** init_waves.c
*/

#include "../../../include/my.h"

wave_data_t *init_wave_data(void)
{
    wave_data_t *wave_data = malloc(sizeof(wave_data_t));

    wave_data->wave_nb = 0;
    wave_data->clock = sfClock_create();
    return wave_data;
}
