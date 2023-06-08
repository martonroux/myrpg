/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** is_pressed
*/

#include "../../include/my.h"

int is_pressed(game_t *game, sfKeyCode key)
{
    if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == key)
        return 1;
    if (game->event.type == sfEvtMouseButtonPressed &&
        game->event.mouseButton.button == key)
        return 1;
    return 0;
}

int is_released(game_t *game, sfKeyCode key)
{
    if (game->event.type == sfEvtKeyReleased &&
        game->event.key.code == key)
        return 1;
    if (game->event.type == sfEvtMouseButtonReleased &&
        game->event.mouseButton.button == key)
        return 1;
    return 0;
}

bool is_hold(game_t * game, sfKeyCode key)
{
    sfEvent event = game->event;
    bool *isHeld = game->keyboard->isHeld;

    if (event.type == sfEvtKeyPressed && event.key.code == key)
        isHeld[key] = true;
    if (event.type == sfEvtKeyReleased && event.key.code == key)
        isHeld[key] = false;
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == key)
        isHeld[key] = true;
    if (event.type == sfEvtMouseButtonReleased &&
        event.mouseButton.button == key)
        isHeld[key] = false;

    game->keyboard->isHeld = isHeld;
    return isHeld[key];
}

bool is_clicked_once(game_t *game, sfKeyCode key)
{
    bool *is_clicked_once = game->keyboard->is_clicked_once;
    if (is_pressed(game, key) && !is_clicked_once[key]) {
        is_clicked_once[key] = true;
        return true;
    }
    if (is_released(game, key))
        is_clicked_once[key] = false;
    return false;
}
