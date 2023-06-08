/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** init_game_struct
*/

#include "../../../include/my.h"

game_t* init_game_struct(void)
{
    game_t* game = malloc(sizeof(game_t));
    game->stat = malloc(sizeof(stat_t));
    game->collector = create_garbage_collector();
    game->saved_sprites = init_saved_sprites(game);
    game->window = sfRenderWindow_create((sfVideoMode)
        {3264, 2448, 32}, "test", sfClose | sfResize, NULL);
    init_game_keyboard(game);
    game->texts = NULL;
    sfRenderWindow_setFramerateLimit(game->window, 60);
    game->font = sfFont_createFromFile("assets/font_text.ttf");
    init_background(game);
    game->animation_timer = sfClock_create();
    add_to_garbage_collector(game, game->collector);
    game->wave_data = init_wave_data();
    init_stat(game);
    game->head_chunk = init_head_chunks(game);
    game->outside_screen = init_outside_screen(game->collector);
    game->tutorial = partial_init_tutorial(game);
    init_death(game);
    return game;
}
