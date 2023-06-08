/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui
** File description:
** init_death_text.c
*/

#include "../../../include/my.h"

void init_death(game_t *game)
{
    sfFont *font = sfFont_createFromFile("assets/font_text.ttf");

    game->death_clock = sfClock_create();
    game->death_text = sfText_create();
    game->has_died = false;

    sfText_setColor(game->death_text, sfWhite);
    sfText_setString(game->death_text, "You died!");
    sfText_setCharacterSize(game->death_text, 60);
    sfText_setFont(game->death_text, font);
}
