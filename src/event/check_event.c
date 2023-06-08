/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** check_event
*/

#include "../../include/my.h"

void check_selected(game_t *game)
{
    if (game->state != STATE_SETTINGS) return;
    texts_t *texts = game->settings_menu->texts;
    texts_t *select;
    int i = 0;
    int index = get_index_resolution(game);

    while (texts) {
        texts->selected = false;
        if (i == index)
            select = texts;
        texts = texts->next;
        i++;
    }
    if (index == -1) return;
    select->selected = true;
}

void check_hovered(game_t *game, texts_t *tmp)
{
    for (; tmp; tmp = tmp->next) {
        if (text_is_hovered(tmp->text, game->window, game->view)
            && tmp->hoverable) {
            sfFloatRect rect = sfText_getGlobalBounds(tmp->text);
            float rectWidth = rect.width;
            float rectHeight = rect.height;
            sfRectangleShape_setOutlineColor(tmp->rect, sfWhite);
            sfRectangleShape_setSize(tmp->rect,
            (sfVector2f) {rectWidth, rectHeight + 14});
            sfRectangleShape_setPosition(tmp->rect, (sfVector2f)
                {rect.left, rect.top - 7});
        } else {
            sfRectangleShape_setOutlineColor(tmp->rect, sfTransparent);
        }
        if (game->state == STATE_SETTINGS)
            apply_buttons_settings(game, tmp);
        else
            apply_buttons_menu(game, tmp);
    }
    check_selected(game);
}

int check_event_menu(game_t *game)
{
    texts_t *tmp = game->game_menu->texts;

    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        check_hovered(game, tmp);
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
    return 0;
}

int check_event_settings(game_t *game)
{
    texts_t *tmp = game->settings_menu->texts;

    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        check_hovered(game, tmp);
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
    return 0;
}

int check_event(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (is_released(game, sfKeyEscape))
            game->state = STATE_MENU;
        is_hold(game, (sfKeyCode) sfMouseLeft);
        is_clicked_once(game, sfKeyE);
        if (is_released(game, sfKeyTab))
            game->inv->is_displayed = !game->inv->is_displayed;
    }
    return 0;
}
