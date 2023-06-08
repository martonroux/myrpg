/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui
** File description:
** update_inventory
*/

#include "../../include/my.h"

void set_pref_ability(game_t *game, int i)
{
    if (i == 0) {
        game->stat->ability = 0;
        sfRectangleShape_setTexture(game->item_frame,
        sfRectangleShape_getTexture(game->inv->inv_slot[0]), sfTrue);
        sfRectangleShape_setOutlineColor(game->item_frame, sfWhite);
        sfRectangleShape_setOutlineColor(game->inv->inv_slot[0], sfWhite);
        sfRectangleShape_setOutlineColor(game->inv->inv_slot[1], sfBlack);
    } else {
        game->stat->ability = 1;
        sfRectangleShape_setTexture(game->item_frame,
        sfRectangleShape_getTexture(game->inv->inv_slot[1]), sfTrue);
        sfRectangleShape_setOutlineColor(game->item_frame, sfWhite);
        sfRectangleShape_setOutlineColor(game->inv->inv_slot[1], sfWhite);
        sfRectangleShape_setOutlineColor(game->inv->inv_slot[0], sfBlack);
    }
}

void check_weapons(game_t *game)
{
    for (int i = 0; i < 2; i++) {
        if (rect_hovered(game->inv->inv_slot[i], game->window, game->view) &&
        sfMouse_isButtonPressed(sfMouseLeft) &&
        game->inv->is_displayed == true && game->stat->level > 1)
            set_pref_ability(game, i);
    }
}

void update_inventory(game_t *game)
{
    entity_t *tmp = get_player_entity(game);
    sfVector2f center_window = sfView_getCenter(game->view);
    sfVector2f view_size = sfView_getSize(game->view);

    sfRectangleShape_setPosition(game->item_frame,
    (sfVector2f) {(((float)center_window.x) + view_size.x / 2 - 150),
    (tmp->position.y - view_size.y / 2 + 100)});
    for (int i = 0; i < 2; i++) {
        sfRectangleShape_setPosition(game->inv->inv_slot[i],
        (sfVector2f){tmp->position.x - 300 + i * 110, tmp->position.y - 175});
        if (game->stat->level > 1)
            sfRectangleShape_setFillColor(game->inv->inv_slot[1], sfWhite);
    }
    check_weapons(game);
}
