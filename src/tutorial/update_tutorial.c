/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** update_tutorial.c
*/

#include "../../include/my.h"

void update_tutorial_specific(game_t *game)
{
    if (enemies_still_alive(game) == false) {
        if (game->tutorial->killed_zombies == false)
            game->tutorial->killed_zombies = true;
        else
            game->tutorial->killed_boss = true;

        if (game->tutorial->killed_zombies == true
            && game->tutorial->killed_boss == false) {
            game->wave_data->wave_nb = 5;
            game->wave_data->nb_enemies_left = 1;
            spawn_enemies(game);
        }
    }
    display_tuto_text(game, game->tutorial);
}

void update_tutorial(game_t *game)
{
    if (game->tutorial->is_init == false)
        game->tutorial = init_tutorial(game, game->tutorial);
    sfView_setSize(game->view, game->view_size);
    update_camera(game);
    sfRenderWindow_clear(game->window, sfBlack);
    display_background(game);
    chunks_main(game);
    update_bullet(game);
    animation_main(game);
    display_entities(game);
    display_weapon(game);
    display_text(game);
    display_bullet(game);
    update_blood(game);
    display_life(game);
    collisions_main(game);
    check_event(game);
    update_zombie(game);
    update_tutorial_specific(game);
    sfRenderWindow_display(game->window);
}
