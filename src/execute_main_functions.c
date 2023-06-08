/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** update
*/

#include "../include/my.h"
#include <unistd.h>

void init_game(game_t *game)
{
    sfVector2u window_size = sfRenderWindow_getSize(game->window);
    sfFloatRect view_size = {0, 0, window_size.x, window_size.y};
    game->head_entity = create_entity_ll(game->collector);
    add_entity(game->head_entity, create_player(game));
    add_entity(game->head_entity, create_animal(game->collector));
    get_ak47(game);
    init_inventory(game);
    sfSprite_setScale(get_player_entity(game)->sprite,
                        (sfVector2f){2.5f, 2.5f});
    set_sprite_origin(get_player_entity(game)->sprite);
    game->view = sfView_createFromRect(view_size);
    game->view_size = sfView_getSize(game->view);
    game->quest = init_quest(game);
    init_sound(game);
    sfText_setFont(game->quest->text, game->font);
    sfText_setCharacterSize(game->quest->text, 50);
    sfText_setColor(game->quest->text, sfWhite);
    sfText_setPosition(game->quest->text, (sfVector2f){200, 200});
}

void update_menu(game_t *game)
{
    sfVector2u window_size = sfRenderWindow_getSize(game->window);

    sfView_setSize(game->view, (sfVector2f){window_size.x, window_size.y});
    update_camera(game);
    sfRenderWindow_clear(game->window, sfBlack);
    update_text(game);
    display_text(game);
    sfRenderWindow_display(game->window);
    check_event_menu(game);
}

void update_game(game_t *game)
{
    sfView_setSize(game->view, game->view_size);
    update_camera(game);
    sfRenderWindow_clear(game->window, sfBlack);
    display_background(game);
    chunks_main(game);
    update_bullet(game);
    update_quest(game);
    waves_main(game);
    animation_main(game);
    display_entities(game);
    display_text(game);
    display_bullet(game);
    display_life(game);
    display_quest(game);
    collisions_main(game);
    update_zombie(game);
    check_event(game);
    update_blood(game);
    sfRenderWindow_display(game->window);
}
