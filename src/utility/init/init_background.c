/*
** EPITECH PROJECT, 2023
** init background
** File description:
** rpg
*/

#include "../../../include/my.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>

void init_boss(game_t *game)
{
    sfTexture *life_boss = sfTexture_createFromFile(
            "assets/red_bar.png", sfFalse);
    sfTexture *rect_boss = sfTexture_createFromFile(
            "assets/boarder1.jpg", sfFalse);
    sfTexture *boss_icon = sfTexture_createFromFile(
            "assets/icon_boss.png", sfFalse);

    game->background->icon_boss = sfSprite_create();
    game->background->boss_life = sfSprite_create();
    game->background->rect_boss = sfSprite_create();
    sfSprite_setTexture(game->background->icon_boss, boss_icon, sfFalse);
    sfSprite_setTexture(game->background->boss_life, life_boss, sfFalse);
    sfSprite_setTexture(game->background->rect_boss, rect_boss, sfFalse);
    sfSprite_setScale(game->background->rect_boss, (sfVector2f) {4.04, 1});
}

void init_level(game_t *game)
{
    sfFont *font = sfFont_createFromFile("assets/font_text.ttf");
    sfTexture *blue = sfTexture_createFromFile(
            "assets/blue_heart.png", sfFalse);

    game->background->bleu_heart = sfSprite_create();
    game->background->wave = sfText_create();
    game->background->level = sfText_create();
    sfText_setFont(game->background->level, font);
    sfText_setFont(game->background->wave, font);
    sfText_setFillColor(game->background->level, sfWhite);
    sfText_setFillColor(game->background->wave, sfWhite);
    sfSprite_setScale(game->background->bleu_heart, (sfVector2f) {0.1, 0.1});
    sfSprite_setTexture(game->background->bleu_heart, blue, sfFalse);
    init_boss(game);
}

void init_list_sprit(game_t *game, back_window_t *under, back_window_t *top)
{
    sfTexture *t_fond = sfTexture_createFromFile("assets/map.png", sfFalse);

    game->background->position = (sfVector2f){0, 0};
    under->position = (sfVector2f){0, 2446};
    top->position = (sfVector2f){0, -2446};
    game->background->s_fond = sfSprite_create();
    under->s_fond = sfSprite_create();
    top->s_fond = sfSprite_create();
    sfSprite_setTexture(game->background->s_fond, t_fond, sfFalse);
    sfSprite_setTexture(under->s_fond, t_fond, sfFalse);
    sfSprite_setTexture(top->s_fond, t_fond, sfFalse);
    sfSprite_setPosition(under->s_fond, under->position);
    sfSprite_setPosition(top->s_fond, top->position);
    sfSprite_setPosition(game->background->s_fond, game->background->position);
    under->next = top;
    top->next = NULL;
    game->background->next = under;
    init_level(game);
}

void init_background_bis(game_t *game, back_window_t *under, back_window_t *top)
{
    sfTexture *t_xp_bar = sfTexture_createFromFile(
        "assets/barre_xp.png", sfFalse);
    sfTexture *xp = sfTexture_createFromFile(
        "assets/evolution_xp.png", sfFalse);

    sfSprite_setTexture(game->background->evolution, xp, sfFalse);
    sfSprite_setScale(game->background->evolution, (sfVector2f){6.5, 1.2});
    sfSprite_setTexture(game->background->xp_bar, t_xp_bar, sfFalse);
    sfSprite_setScale(game->background->xp_bar, (sfVector2f){0.4, 0.1});
    sfSprite_setScale(game->background->heart, (sfVector2f){0.2, 0.2});
    sfSprite_setScale(game->background->half_heart, (sfVector2f){0.2, 0.2});
    sfSprite_setTextureRect(game->background->heart,
                                (sfIntRect){0, 0, 331, 264});
    sfSprite_setTextureRect(game->background->half_heart,
                                (sfIntRect){331, 0, 331, 264});
}

void init_background(game_t *game)
{
    back_window_t *under = my_malloc(sizeof(back_window_t), game->collector);
    back_window_t *top = my_malloc(sizeof(back_window_t), game->collector);
    sfTexture *t_heart = sfTexture_createFromFile("assets/heart.png", sfFalse);

    game->background = my_malloc(sizeof(back_window_t), game->collector);
    init_list_sprit(game, under, top);
    game->background->heart = sfSprite_create();
    game->background->half_heart = sfSprite_create();
    game->background->xp_bar = sfSprite_create();
    game->background->evolution = sfSprite_create();
    sfSprite_setTexture(game->background->heart, t_heart, sfFalse);
    sfSprite_setTexture(game->background->half_heart, t_heart, sfFalse);
    return init_background_bis(game, under, top);
}
