/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** init_tutorial_2.c
*/

#include "../../include/my.h"

sfText *init_boss_health_text(game_t *game)
{
    sfVector2f size = sfView_getSize(game->view);
    sfVector2f center = sfView_getCenter(game->view);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font_text.ttf");

    sfText_setString(text, "|| Ceci est la barre de vie du boss.\n\\/");
    sfText_setCharacterSize(text, 20);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, (sfVector2f){center.x + 200,
                                            center.y + size.y / 2 - 150});
    return text;
}

sfText *init_boss_fight_text(game_t *game)
{
    sfVector2f size = sfView_getSize(game->view);
    sfVector2f center = sfView_getCenter(game->view);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font_text.ttf");

    sfText_setString(text, "Attention! Tu te bats contre un boss. Celui"
                            "-ci a beaucoup\nplus de vie que les zombies. Tu"
                            " en croiseras toutes les 5 vagues,\net il sera "
                            "de plus en plus fort!");
    sfText_setCharacterSize(text, 20);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, (sfVector2f){center.x - size.x / 2.f,
                                            center.y - size.y / 2 + 100});
    return text;
}

sfText *init_congratulation_text(game_t *game)
{
    sfVector2f view_center = sfView_getCenter(game->view);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font_text.ttf");
    sfFloatRect bounds;

    sfText_setString(text, "GG! Tu as decouvert comment jouer au jeu,\n"
                            "tu peux maintenant retourner au menu en "
                            "appuyant sur Echap.");
    bounds = sfText_getLocalBounds(text);
    sfText_setCharacterSize(text, 30);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, (sfVector2f){view_center.x - bounds.width / 2,
                                            view_center.y - 200});
    return text;
}

sfText *init_xp_text(game_t *game)
{
    sfVector2f size = sfView_getSize(game->view);
    sfVector2f center = sfView_getCenter(game->view);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font_text.ttf");

    sfText_setString(text, "|| Ceci est ta barre d'XP. Lorsqu'elle est pleine"
                            ", une de tes competences\n\\/ est amelioree. Tu "
                            "peux voir ton niveau actuel en haut a gauche");
    sfText_setCharacterSize(text, 20);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, (sfVector2f){center.x + 100,
                                            center.y + size.y / 2 - 100});
    return text;
}
