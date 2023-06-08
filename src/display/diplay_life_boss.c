/*
** EPITECH PROJECT, 2023
** display_life_boss
** File description:
** rpg
*/

#include "../../include/my.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>

void display_life_boss_set_origin(game_t *game, sfVector2f boss_life_pos,
                                    sfVector2f rect_boss_pos,
                                        sfVector2f icon_boss_pos)
{
    sfRenderWindow *window = game->window;

    set_sprite_origin(game->background->boss_life);
    set_sprite_origin(game->background->rect_boss);
    set_sprite_origin(game->background->icon_boss);
    sfSprite_setPosition(game->background->boss_life, boss_life_pos);
    sfSprite_setPosition(game->background->rect_boss, rect_boss_pos);
    sfSprite_setPosition(game->background->icon_boss, icon_boss_pos);
    sfRenderWindow_drawSprite(window, game->background->rect_boss, sfFalse);
    sfRenderWindow_drawSprite(window, game->background->boss_life, sfFalse);
    sfRenderWindow_drawSprite(window, game->background->icon_boss, sfFalse);
}

void display_life_boss(entity_t *boss, game_t *game)
{
    sfVector2f size_window = sfView_getSize(game->view);
    sfVector2f player_pos = sfView_getCenter(game->view);
    sfVector2f boss_life_pos = {player_pos.x,
                                    player_pos.y - 80 + size_window.y / 2};
    sfVector2f rect_boss_pos = {player_pos.x,
                                    player_pos.y - 80 + size_window.y / 2};
    sfVector2f icon_boss_pos = {player_pos.x,
                                player_pos.y - 170 + (size_window.y / 2)};
    sfFloatRect life_size;
    sfFloatRect rect_size = sfSprite_getGlobalBounds(
            game->background->rect_boss);
    float pourcent_hp = boss->hp * 100 /
            (((float)game->wave_data->wave_nb / 5) * 500);

    sfSprite_setScale(game->background->boss_life,
                        (sfVector2f) {pourcent_hp * 4.1 / 100, 1});
    life_size = sfSprite_getGlobalBounds(game->background->boss_life);
    boss_life_pos.x -= (rect_size.width - life_size.width) / 2;
    display_life_boss_set_origin(game, boss_life_pos,
                                    rect_boss_pos, icon_boss_pos);
}
