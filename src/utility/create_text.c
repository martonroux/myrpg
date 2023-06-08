/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** create_text
*/

#include "../../include/my.h"

texts_t *add_text(game_t *game, sfText *sf_text, collector_t *collector)
{
    texts_t *new = my_malloc(sizeof(texts_t), collector);
    texts_t *tmp = game->texts;

    new->text = sf_text;
    new->next = NULL;
    new->time = -100;
    new->hoverable = true;
    if (game->texts == NULL) {
        game->texts = new;
        return new;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return new;
}

texts_t *add_text_menu(game_t *game, sfText *sf_text, collector_t *collector)
{
    texts_t *new = my_malloc(sizeof(texts_t), collector);
    texts_t *tmp = game->game_menu->texts;

    new->text = sf_text;
    new->next = NULL;
    new->time = -100;
    new->hoverable = true;
    if (game->game_menu->texts == NULL) {
        game->game_menu->texts = new;
        return new;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return new;
}

texts_t *add_text_settings(game_t *game, sfText *sf_text,
                            collector_t *collector)
{
    texts_t *new = my_malloc(sizeof(texts_t), collector);
    texts_t *tmp = game->settings_menu->texts;

    new->text = sf_text;
    new->next = NULL;
    new->time = -100;
    new->hoverable = true;
    if (game->settings_menu->texts == NULL) {
        game->settings_menu->texts = new;
        return new;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return new;
}

void create_settings_text(game_t *game, char *str, sfVector2f pos, bool hover)
{
    sfText *text = sfText_create();
    texts_t *tmp;

    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    sfText_setFont(text, game->font);
    sfText_setCharacterSize(text, 40);
    sfText_setColor(text, sfWhite);
    tmp = add_text_settings(game, text, game->collector);
    tmp->time = 5.0f;
    tmp->selected = false;
    tmp->hoverable = hover;
}

void create_text(game_t *game, char *str, sfVector2f pos, int size)
{
    sfText *text = sfText_create();
    texts_t *tmp;

    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    sfText_setFont(text, game->font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfWhite);
    switch (game->state) {
        case STATE_MENU:
            tmp = add_text_menu(game, text, game->collector); break;
        case STATE_GAME:
            tmp = add_text(game, text, game->collector); break;
    }
    tmp->selected = false;
    tmp->time = 5.0f;
}
