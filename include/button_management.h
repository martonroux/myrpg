/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** button_management
*/

#pragma once

#include "game_struct.h"

int is_pressed(game_t *game, sfKeyCode key);
int is_released(game_t *game, sfKeyCode key);
bool is_hold(game_t * game, sfKeyCode key);
bool is_clicked_once(game_t *game, sfKeyCode key);
bool text_is_hovered(sfText *text, sfRenderWindow *window, sfView *view);
void add_button(game_t *game, button_t *button);
button_t *create_button(sfVector2f pos, sfVector2f size, char *text,
    int (*ptr) (game_t *game));
