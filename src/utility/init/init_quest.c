/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui
** File description:
** init_quest.c
*/

#include "../../../include/my.h"

quest_t *init_quest(game_t *game)
{
    quest_t *quest = my_malloc(sizeof(quest_t), game->collector);

    quest->state = 0;
    quest->quest_nb = 0;
    quest->text = sfText_create();
    quest->type = -1;
    return quest;
}
