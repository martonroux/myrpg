/*
** EPITECH PROJECT, 2023
** None
** File description:
** main
*/

#include "include/my.h"

void game_state(game_t *game)
{
    switch (game->state) {
        case STATE_MENU:
            update_menu(game);
            break;
        case STATE_GAME:
            update_game(game);
            break;
        case STATE_TUTO:
            update_tutorial(game);
            break;
        case STATE_EXIT:
            sfRenderWindow_close(game->window);
            break;
        case STATE_SETTINGS:
            update_settings(game);
    }
}

int main(int ac, char **av)
{
    game_t *game = init_game_struct();
    init_game(game);
    init_game_menu(game);
    while (sfRenderWindow_isOpen(game->window))
        game_state(game);
    free_garbage_collector(game->collector);
    return 0;
}
