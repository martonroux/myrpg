/*
** EPITECH PROJECT, 2023
** display life
** File description:
** rpg
*/

#include "../../include/my.h"

void display_xp_bis(game_t *game, sfVector2f player_pos,
                        sfVector2f size_window)
{
    float rec_xp = logf((float)game->stat->level) *
            (float)game->stat->level + 50;
    float pourcent = ((float)game->stat->xp * 100.f) / rec_xp;
    sfVector2f evolution_scale = {6.5f * pourcent / 100, 1.3f};
    sfVector2f evolution_pos = {player_pos.x,
                                player_pos.y - 26 + (size_window.y / 2)};
    sfFloatRect rect_size = sfSprite_getGlobalBounds(game->background->xp_bar);
    sfFloatRect evol_size;

    sfSprite_setScale(game->background->evolution, evolution_scale);
    evol_size = sfSprite_getGlobalBounds(game->background->evolution);
    evolution_pos.x -= (rect_size.width - evol_size.width) / 2;
    set_sprite_origin(game->background->evolution);
    sfSprite_setPosition(game->background->evolution, evolution_pos);
    sfRenderWindow_drawSprite(game->window, game->background->xp_bar, NULL);
    sfRenderWindow_drawSprite(game->window, game->background->evolution, NULL);
    sfRenderWindow_drawText(game->window, game->background->level, NULL);
}

void diplay_xp(game_t *game, sfVector2f player_pos, sfVector2f size_window)
{
    sfVector2f xp_bar_pos = {player_pos.x,
                                player_pos.y - 25 + (size_window.y / 2)};
    sfVector2f level_pos = {player_pos.x - (size_window.x / 2),
                                player_pos.y - (size_window.y / 2)};
    char *print;
    char *str_int;

    str_int = into_str(game->stat->level);
    print = my_strcat("Level: ", str_int);
    sfText_setString(game->background->level, print);
    set_sprite_origin(game->background->xp_bar);
    sfSprite_setPosition(game->background->xp_bar, xp_bar_pos);
    sfText_setPosition(game->background->level, level_pos);
    display_xp_bis(game, player_pos, size_window);
    free(print);
    free(str_int);
    display_wave(game, player_pos, size_window);
}

void display_life_bis(game_t *game, sfVector2f player_pos,
                        float life, int pos)
{
    sfVector2f size_window = sfView_getSize(game->view);

    for (; life <= 10 && life >= 1; life -= 1) {
        sfSprite_setPosition(game->background->heart, (sfVector2f)
            {(player_pos.x - ((float)size_window.x / 2)) + pos,
                player_pos.y - ((float)size_window.y / 2.2)});
        sfRenderWindow_drawSprite(game->window, game->background->heart, NULL);
        pos += 50;
    }
    if (life * 10 >= 5) {
        sfSprite_setPosition(game->background->half_heart, (sfVector2f)
            {(player_pos.x - ((float)size_window.x / 2)) + pos,
                player_pos.y - ((float)size_window.y / 2.2)});
        sfRenderWindow_drawSprite(game->window,
                                    game->background->half_heart, NULL);
    }
}

void display_life(game_t *game)
{
    entity_t *player = get_player_entity(game);
    int pos = 0;
    sfVector2f size_window = sfView_getSize(game->view);
    sfVector2f player_pos = sfView_getCenter(game->view);
    float life = player->hp;

    for (; life > 10; life -= 10) {
        sfSprite_setPosition(game->background->bleu_heart, (sfVector2f)
        {(player_pos.x - ((float)size_window.x / 2)) + pos,
            player_pos.y - ((float)size_window.y / 2.2)});
        sfRenderWindow_drawSprite(game->window,
                                    game->background->bleu_heart, NULL);
        pos += 50;
    }
    display_life_bis(game, player_pos, life, pos);
    diplay_xp(game, player_pos, size_window);
    display_inventory(game);
}
