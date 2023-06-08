/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** move_players.c
*/

#include "../../../include/my.h"

void change_pos(entity_t *entity, sfVector2f pos_add)
{
    entity->position.x += pos_add.x;
    entity->position.y += pos_add.y;

    sfSprite_setPosition(entity->sprite, entity->position);
}

movement_dir_t change_direction(sfVector2f sum)
{
    movement_dir_t dir = NONE;

    if (ABSOLUTE_VALUE(sum.y) > ABSOLUTE_VALUE(sum.x)) {
        if (sum.y > 0)
            dir = DOWN;
        if (sum.y < 0)
            dir = UP;
    } else {
        if (sum.x > 0)
            dir = RIGHT;
        if (sum.x < 0)
            dir = LEFT;
    }
    return dir;
}

void move_player(entity_t *player, game_t *game)
{
    sfVector2f sum = {0, 0};

    update_player(game, player);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        sum.y -= player->speed;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        sum.y += player->speed;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        sum.x -= player->speed;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        sum.x += player->speed;
    player->anim_data->movement_dir = change_direction(sum);
    if (player->position.x + sum.x < 100 || player->position.x + sum.x > 3200)
        sum.x = 0;
    if (sum.x == 0 && sum.y == 0) return;
    if (sum.x != 0 && sum.y == 0) return change_pos(player, sum);
    if (sum.x == 0 && sum.y != 0) return change_pos(player, sum);
    return change_pos(player,
                        (sfVector2f){sum.x * cos(PI / 4), sum.y * sin(PI / 4)});
}

void move_characters_main(game_t *game)
{
    entity_t *actual = game->head_entity->first;

    while (actual != NULL) {
        if (actual->update != NULL)
            actual->update(actual, game);
        actual->anim_data->state = STATE_NORMAL;
        actual = actual->next;
    }
}
