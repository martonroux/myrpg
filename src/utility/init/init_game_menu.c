/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui
** File description:
** init_game_menu
*/

#include "../../../include/my.h"

void init_buttons(game_t *game)
{
    texts_t *tmp = game->game_menu->texts;

    for (; tmp; tmp = tmp->next) {
        static int id = 0;

        tmp->id = id++;
        tmp->rect = sfRectangleShape_create();
        sfRectangleShape_setSize(tmp->rect, (sfVector2f) {300, 100});
        sfRectangleShape_setPosition(tmp->rect, sfText_getPosition(tmp->text));
        sfRectangleShape_setFillColor(tmp->rect, sfTransparent);
        sfRectangleShape_setOutlineColor(tmp->rect, sfBlack);
        sfRectangleShape_setOutlineThickness(tmp->rect, 2);
    }
}

void init_settings_buttons(game_t *game)
{
    texts_t *tmp = game->settings_menu->texts;

    for (; tmp; tmp = tmp->next) {
        static int id = 0;

        tmp->id = id++;
        tmp->rect = sfRectangleShape_create();
        sfRectangleShape_setSize(tmp->rect, (sfVector2f) {300, 100});
        sfRectangleShape_setPosition(tmp->rect, sfText_getPosition(tmp->text));
        sfRectangleShape_setFillColor(tmp->rect, sfTransparent);
        sfRectangleShape_setOutlineColor(tmp->rect, sfBlack);
        sfRectangleShape_setOutlineThickness(tmp->rect, 2);
    }
}

void init_settings_menu(game_t *game)
{
    game->settings_menu = malloc(sizeof(game_menu_t));
    game->settings_menu->sprite = NULL;
    game->settings_menu->texture = NULL;
    game->settings_menu->texts = NULL;

    create_settings_text(game, "RESOLUTION:", (sfVector2f) {50, 50}, false);
    create_settings_text(game, "480p", (sfVector2f) {200, 150}, true);
    create_settings_text(game, "720p", (sfVector2f) {200, 250}, true);
    create_settings_text(game, "1080p", (sfVector2f) {200, 350}, true);
    create_settings_text(game, "1440p", (sfVector2f) {200, 450}, true);
    create_settings_text(game, "2160p", (sfVector2f) {200, 550}, true);
    create_settings_text(game, "RETOUR", (sfVector2f) {50, 650}, true);
    init_settings_buttons(game);
}

void init_game_menu(game_t *game)
{
    game->game_menu = malloc(sizeof(game_menu_t));
    game->state = STATE_MENU;
    game->game_menu->sprite = NULL;
    game->game_menu->texture = NULL;
    game->game_menu->texts = NULL;

    create_text(game, "JOUER", (sfVector2f) {50, 50}, 40);
    create_text(game, "TUTORIEL", (sfVector2f) {50, 150}, 40);
    create_text(game, "CHARGER PARTIE", (sfVector2f) {50, 250}, 40);
    create_text(game, "SAUVEGARDER", (sfVector2f) {50, 350}, 40);
    create_text(game, "PARAMETRES", (sfVector2f) {50, 450}, 40);
    create_text(game, "QUITTER", (sfVector2f) {50, 550}, 40);
    init_buttons(game);
    init_settings_menu(game);
}
