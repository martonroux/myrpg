/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** init_sound
*/

#include "../include/my.h"

void init_sound(game_t *game)
{
    sfSoundBuffer *gun_buffer =
        sfSoundBuffer_createFromFile("assets/gun_sound.ogg");
    sfSoundBuffer *level_up_buffer =
        sfSoundBuffer_createFromFile("assets/level_up.ogg");
    sfSoundBuffer *boss_coming_buffer =
        sfSoundBuffer_createFromFile("assets/boss_coming.ogg");

    game->sound = malloc(sizeof(sound_t));
    game->sound->gun_sound = sfSound_create();
    sfSound_setBuffer(game->sound->gun_sound, gun_buffer);
    sfSound_setVolume(game->sound->gun_sound, 50);
    game->sound->level_up = sfSound_create();
    game->sound->boss_sound = sfSound_create();
    sfSound_setBuffer(game->sound->level_up, level_up_buffer);
    sfSound_setBuffer(game->sound->boss_sound, boss_coming_buffer);
}
