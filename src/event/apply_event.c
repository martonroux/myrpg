/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui
** File description:
** apply_event.c
*/

#include "../../include/my.h"

bool check_action(game_t *game, texts_t *tmp, int id)
{
    if (text_is_hovered(tmp->text, game->window, game->view)
        && is_pressed(game, (sfKeyCode) sfMouseLeft) && tmp->id == id)
        return true;
    return false;
}

void apply_buttons_menu(game_t *game, texts_t *tmp)
{
    if (check_action(game, tmp, 0))
        game->state = STATE_GAME;
    if (check_action(game, tmp, 1))
        game->state = STATE_TUTO;
    if (check_action(game, tmp, 2)) {
        init_load_save(game);
        delete_all_entities(game->head_entity);
        game->state = STATE_GAME;
    }
    if (check_action(game, tmp, 3))
        save_file(game);
    if (check_action(game, tmp, 4))
        game->state = STATE_SETTINGS;
    if (check_action(game, tmp, 5))
        sfRenderWindow_close(game->window);
}

void apply_buttons_settings(game_t *game, texts_t *tmp)
{
    if (check_action(game, tmp, 1))
        game->view_size = (sfVector2f){720, 480};
    if (check_action(game, tmp, 2))
        game->view_size = (sfVector2f){1280, 720};
    if (check_action(game, tmp, 3))
        game->view_size = (sfVector2f){1920, 1080};
    if (check_action(game, tmp, 4))
        game->view_size = (sfVector2f){2560, 1440};
    if (check_action(game, tmp, 5))
        game->view_size = (sfVector2f){3264, 1948};
    if (check_action(game, tmp, 6))
        game->state = STATE_MENU;
}
