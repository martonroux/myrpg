/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** init_tutorial.c
*/

#include "../../include/my.h"

sfText *init_movement_text(game_t *game)
{
    sfVector2f view_size = sfView_getSize(game->view);
    sfVector2f view_center = sfView_getCenter(game->view);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font_text.ttf");

    sfText_setString(text, "Z: haut\nS: bas\nQ: gauche\nD: droite");
    sfText_setCharacterSize(text, 30);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, (sfVector2f){view_center.x - view_size.x / 2.f,
                                            view_center.y});
    return text;
}

sfText *init_health_text(game_t *game)
{
    sfVector2f size = sfView_getSize(game->view);
    sfVector2f center = sfView_getCenter(game->view);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font_text.ttf");

    sfText_setString(text, "^ Ceci est ta barre de vie.\n"
                            "1 Coeur rouge: 1 PV\n1 Coeur bleu: 10 PV");
    sfText_setCharacterSize(text, 20);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, (sfVector2f){center.x - size.x / 2.f,
                                            center.y - size.y / 2 + 100});
    return text;
}

sfText *init_shoot_text(game_t *game)
{
    sfVector2f player_pos = get_player_entity(game)->position;
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font_text.ttf");

    sfText_setString(text, "Tire sur les zombies avec clic gauche pour "
                            "les tuer\net entamer la prochaine vague");
    sfText_setCharacterSize(text, 20);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, (sfVector2f){player_pos.x,
                                            player_pos.y - 100});
    return text;
}

void init_tuto_player_stats(game_t *game, entity_t *player)
{
    player->hp = 20.f;
    player->weapon->damage = 5;
    game->stat->level = 1;
    game->stat->xp = 0;
    game->stat->multishot = 0;
    game->stat->explosive = 0;
    game->wave_data->wave_nb = 1;
    game->wave_data->nb_enemies_left = 2;
    player->weapon->damage = 20;
    delete_all_entities(game->head_entity);
    spawn_enemies(game);
}

tutorial_t *init_tutorial(game_t *game, tutorial_t *tutorial)
{
    entity_t *player = get_player_entity(game);

    tutorial->movements_text = init_movement_text(game);
    tutorial->shoot_text = init_shoot_text(game);
    tutorial->health_text = init_health_text(game);
    tutorial->xp = init_xp_text(game);
    tutorial->boss_health = init_boss_health_text(game);
    tutorial->boss_fight = init_boss_fight_text(game);
    tutorial->congratulations = init_congratulation_text(game);
    tutorial->is_init = true;
    tutorial->killed_zombies = false;
    tutorial->killed_boss = false;
    init_tuto_player_stats(game, player);
    return tutorial;
}
