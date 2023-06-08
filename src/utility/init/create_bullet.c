/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** create_bullet
*/

#include "../../../include/my.h"

sfVector2f rotate_vector(sfSprite *sprite, sfVector2f vector, int angle)
{
    sfVector2f new_vector;
    float rad = angle * PI / 180;
    float tot_angle;

    new_vector.x = vector.x * cos(rad) - vector.y * sin(rad);
    new_vector.y = vector.x * sin(rad) + vector.y * cos(rad);
    tot_angle = atan2f(new_vector.y, new_vector.x);
    sfSprite_setRotation(sprite, tot_angle * 180 / PI + 90);
    return new_vector;
}

sfVector2f get_bullet_direction(sfSprite *bullet, sfVector2f pos,
                                    sfVector2i mouse_pos, game_t *game)
{
    sfVector2f center = pos;
    sfVector2u window_size = sfRenderWindow_getSize(game->window);

    mouse_pos.x += sfView_getCenter(
            sfRenderWindow_getView(game->window)).x - window_size.x / 2;
    mouse_pos.y += sfView_getCenter(
            sfRenderWindow_getView(game->window)).y - window_size.y / 2;

    return get_direction_toward(bullet, center,
        change_vectorf(mouse_pos));
}

bullet_t *add_bullet_to_list(bullet_t *bullet, head_bullet_t *head_bullet)
{
    bullet_t *tmp = head_bullet->first;

    if (head_bullet->first == NULL) {
        head_bullet->first = bullet;
        return bullet;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = bullet;
    return bullet;
}

bullet_t *create_bullet(game_t *game, sfVector2f pos,
    weapon_t *weapon, int angle)
{
    bullet_t *bullet = malloc(sizeof(bullet_t));
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    bullet->sprite = sfSprite_copy(weapon->sprite_bullet);
    bullet->position = pos;
    bullet->speed = 10;
    bullet->direction = get_bullet_direction(bullet->sprite,
                                                pos, mouse_pos, game);
    if (angle != 0)
        bullet->direction = rotate_vector(bullet->sprite,
                                            bullet->direction, angle);
    bullet->angle = atan2(bullet->direction.y, bullet->direction.x);
    bullet->next = NULL;
    bullet->stat = game->stat;
    bullet->range = game->stat->range;
    bullet->damage = weapon->damage;
    bullet->is_visible = true;
    bullet->is_dead = false;
    bullet->shooter_type = PLAYER;
    return add_bullet_to_list(bullet,
                                get_player_entity(game)->weapon->head_bullet);
}

bullet_t *create_mini_bullet(game_t *game,
    sfVector2f pos, weapon_t *weapon, sfVector2f direction)
{
    bullet_t *bullet = malloc(sizeof(bullet_t));
    float angle = atan2f(direction.y, direction.x);

    bullet->sprite = sfSprite_copy(weapon->sprite_bullet);
    sfSprite_setRotation(bullet->sprite, angle * 180 / PI + 90);
    sfSprite_setScale(bullet->sprite, (sfVector2f) {0.5f, 0.5f});
    bullet->position = pos;
    bullet->speed = 10;
    bullet->stat = NULL;
    bullet->direction = direction;
    bullet->next = NULL;
    bullet->range = game->stat->range / 2;
    bullet->is_visible = true;
    bullet->is_dead = false;
    bullet->damage = weapon->damage / 2;
    bullet->shooter_type = PLAYER;
    return add_bullet_to_list(bullet,
                                get_player_entity(game)->weapon->head_bullet);
}
