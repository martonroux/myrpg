/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** update_quest
*/

#include "../../include/my.h"

void update_kill_quest(game_t *game)
{
    char * new = my_strcat("KILL ", int_to_str(game->quest->quest_nb));
    game->quest->quest_text = new;
    sfText_setString(game->quest->text, game->quest->quest_text);
    if (game->quest->state == ACTIVE_QUEST) {
        if (game->quest->quest_nb <= 0.1)
            game->quest->state = DONE_QUEST;
    }
}

void update_kill_10_sec_quest(game_t * game)
{
    char * new = my_strcat("FINISH WAVE IN: ",
                            int_to_str(game->quest->quest_nb));
    game->quest->quest_text = new;
    sfText_setString(game->quest->text, game->quest->quest_text);
    game->quest->quest_nb -=
        sfClock_getElapsedTime(game->animation_timer).microseconds / 3000000.f;;
    if (game->quest->state == ACTIVE_QUEST) {
        if (game->quest->quest_nb <= 0.01)
            game->quest->state = FAILED_QUEST;
    }
}

void update_quest(game_t *game)
{
    if (game->quest->state == CAN_QUEST)
        game->quest->state = GIVE_QUEST;
    if (game->quest->state == GIVE_QUEST) {
        game->quest->type = rand() % 2;
        game->quest->quest_nb = 10.f;
        game->quest->current_wave = game->wave_data->wave_nb;
        if (game->quest->type == KILL_ZOMBIES)
            game->quest->quest_nb = 50.f * game->wave_data->wave_nb;
        game->quest->state = ACTIVE_QUEST;
    }
    if (game->quest->type == KILL_ZOMBIES)
        update_kill_quest(game);
    if (game->quest->type == KILL_10_SEC)
        update_kill_10_sec_quest(game);
}
