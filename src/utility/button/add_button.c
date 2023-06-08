/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** add_button
*/

#include "../../../include/my.h"

button_t *create_button(sfVector2f pos, sfVector2f size, char *text,
    int (*ptr) (game_t *game))
{
    button_t *button = malloc(sizeof(button_t));

    button->rect = sfRectangleShape_create();
    button->text = sfText_create();
    button->is_visible = 1;
    button->ptr = ptr;
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setFillColor(button->rect, sfWhite);
    sfText_setString(button->text, text);
    sfText_setPosition(button->text, pos);
    sfText_setCharacterSize(button->text, 20);
    sfText_setFont(button->text, sfFont_createFromFile("assets/font_text.ttf"));
    return button;
}

void add_button(game_t *game, button_t *button)
{
    button_t *tmp = game->button;
    if (tmp == NULL) {
        game->button = button;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = button;
}
