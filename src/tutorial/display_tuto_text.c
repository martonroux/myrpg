/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** display_text.c
*/

#include "../../include/my.h"

void update_tuto_text_2(game_t *game, tutorial_t *tutorial)
{
    sfVector2f size = sfView_getSize(game->view);
    sfVector2f center = sfView_getCenter(game->view);
    sfFloatRect bounds;

    sfText_setPosition(tutorial->boss_health,
                        (sfVector2f){center.x + 200,
                                    center.y + size.y / 2 - 150});
    sfText_setPosition(tutorial->boss_fight,
                        (sfVector2f){center.x - size.x / 2.f,
                                    center.y - size.y / 2 + 100});
    bounds = sfText_getGlobalBounds(tutorial->congratulations);
    sfText_setPosition(tutorial->congratulations,
                        (sfVector2f){center.x - bounds.width / 2,
                                        center.y - 200});
}

void update_tuto_text(game_t *game, tutorial_t *tutorial)
{
    sfVector2f play_pos = get_player_entity(game)->position;
    sfVector2f size = sfView_getSize(game->view);
    sfVector2f center = sfView_getCenter(game->view);
    sfFloatRect bounds;

    sfText_setPosition(tutorial->shoot_text,
                        (sfVector2f){play_pos.x, play_pos.y - 100});
    sfText_setPosition(tutorial->movements_text,
                        (sfVector2f){center.x - size.x / 2.f,
                                        center.y});
    sfText_setPosition(
        tutorial->health_text,
        (sfVector2f){center.x - size.x / 2.f,
                        center.y - size.y / 2 + 100});
    bounds = sfText_getGlobalBounds(tutorial->xp);
    sfText_setPosition(tutorial->xp,
                        (sfVector2f){center.x + size.x / 2 - bounds.width - 10,
                                        center.y + size.y / 2 - 100});
    update_tuto_text_2(game, tutorial);
}

void display_tuto_text(game_t *game, tutorial_t *tutorial)
{
    update_tuto_text(game, tutorial);
    if (tutorial->killed_zombies == false) {
        sfRenderWindow_drawText(game->window, tutorial->movements_text, NULL);
        sfRenderWindow_drawText(game->window, tutorial->health_text, NULL);
        sfRenderWindow_drawText(game->window, tutorial->shoot_text, NULL);
        sfRenderWindow_drawText(game->window, tutorial->xp, NULL);
    } else if (tutorial->killed_boss == false) {
        sfRenderWindow_drawText(game->window, tutorial->boss_fight, NULL);
        sfRenderWindow_drawText(game->window, tutorial->boss_health, NULL);
    } else {
        sfRenderWindow_drawText(game->window, tutorial->congratulations, NULL);
    }
}
