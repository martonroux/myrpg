/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** waves_main.c
*/

#include "../../../include/my.h"

void spawn_zombies(game_t *game)
{
    wave_data_t *wave_data = game->wave_data;
    entity_t *new_entity;

    for (int i = 0; i < wave_data->nb_enemies_left; i++) {
        new_entity = create_zombie(game, game->collector);
        add_entity(game->head_entity, new_entity);
        new_entity->position = get_pos_outside_screen(game);
    }
}

void spawn_boss(game_t *game)
{
    wave_data_t *wave_data = game->wave_data;
    entity_t *new_entity;

    sfSound_play(game->sound->boss_sound);
    new_entity = create_boss_1(game);
    add_entity(game->head_entity, new_entity);
    new_entity->position = get_player_entity(game)->position;
    new_entity->weapon->damage = (float)wave_data->wave_nb / 5 * 2;
    new_entity->weapon->shoot_rate =
        (2.f / ((float)wave_data->wave_nb / 5)) * 0.7f;
    new_entity->hp = ((float)wave_data->wave_nb / 5) * 500;
}

void spawn_enemies(game_t *game)
{
    wave_data_t *wave_data = game->wave_data;

    if (wave_data->nb_enemies_left == 0)
        return;
    if (wave_data->wave_nb % 5 != 0) {
        spawn_zombies(game);
    } else {
        spawn_boss(game);
    }
    wave_data->nb_enemies_left = 0;
}

void start_wave(wave_data_t *wave_data, game_t *game)
{
    wave_data->started = true;
    wave_data->wave_nb++;
    if (game->quest != NULL && game->quest->type == DONT_MOVE
        && game->quest->quest_nb > 0)
        game->quest->state = DONE_QUEST;
    if (game->quest != NULL && game->quest->type == KILL_10_SEC
        && game->quest->quest_nb > 0)
        game->quest->state = DONE_QUEST;
    if (game->quest->state == DONE_QUEST || game->quest->state == FAILED_QUEST)
        game->quest->state = CAN_QUEST;
    wave_data->nb_enemies_left = 10 * wave_data->wave_nb;
}

void waves_main(game_t *game)
{
    if (enemies_still_alive(game) == false)
        game->wave_data->started = false;
    if (game->wave_data->started == false)
        start_wave(game->wave_data, game);
    spawn_enemies(game);
}
