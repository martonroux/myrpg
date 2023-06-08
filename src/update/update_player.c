/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** update_player
*/

#include "../../include/my.h"

void update_item(game_t *game, entity_t *player, weapon_t *weapon)
{
    for (int i = 1; i <= game->stat->multishot; i++) {
            create_bullet(game, player->position, weapon, i * 10);
            create_bullet(game, player->position, weapon, i * -10);
        }
}

int update_rate(game_t *game, entity_t *player)
{
    weapon_t *weapon = player->weapon;

    if (weapon->shoot_rate > 0)
        weapon->shoot_rate -= 1;
    if (weapon->shoot_rate <= 0 && game->keyboard->isHeld[sfMouseLeft]) {
        weapon->shoot_rate = game->stat->fire_rate;
        player->speed = 3.f;
        create_bullet(game, player->position, weapon, 0);
        sfSound_play(game->sound->gun_sound);
        if (game->stat->ability == 1)
            update_item(game, player, weapon);
    } else if (!game->keyboard->isHeld[sfMouseLeft]) {
        player->speed = 6.f;
    }
    return 0;
}

void increment_skill(game_t *game, int preferred_skill)
{
        if (preferred_skill == 1)
            game->stat->multishot++;
        else
            game->stat->explosive++;
        if (game->stat->multishot <= game->stat->explosive) {
            game->stat->multishot++;
        } else {
            game->stat->explosive++;
        }
}

void update_player_stat(game_t *game, entity_t *player)
{
    if (log((double) game->stat->level) * game->stat->level + 50
        <= (double) game->stat->xp) {
        game->stat->xp -= (int)log(game->stat->level) * game->stat->level + 50;
        game->stat->level++;
        game->stat->point++;
        sfSound_play(game->sound->level_up);
        increment_skill(game, game->stat->ability);
    }
}

int update_player(game_t *game, entity_t *player)
{
    update_rate(game, player);
    update_player_stat(game, player);
    return 0;
}
