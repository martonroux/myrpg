/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** init_boss1.c
*/

#include "../../../include/my.h"

anim_data_t *create_boss1_bullet_anim(game_t *game, sfTexture *texture)
{
    anim_data_t *anim_data = malloc(sizeof(anim_data_t));
    sfVector2u size = sfTexture_getSize(texture);

    anim_data->anim_rect = (sfIntRect){0, 0, 64, 32};
    anim_data->movement_dir = NONE;
    anim_data->state = STATE_NORMAL;
    anim_data->full_size.x = (int)size.x;
    anim_data->full_size.y = (int)size.y;
    anim_data->anim_func = &boss1_bullet_animation;
    return anim_data;
}

weapon_t *create_boss_1_weapon(game_t *game)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));
    sfTexture *bullet_texture = sfTexture_createFromFile(
            "assets/fire_ball.png", NULL);

    weapon->sprite_bullet = sfSprite_create();
    sfSprite_setTexture(weapon->sprite_bullet, bullet_texture, sfTrue);
    weapon->bullet_anim = create_boss1_bullet_anim(game, bullet_texture);
    weapon->shoot_clock = sfClock_create();
    weapon->head_bullet = malloc(sizeof(head_bullet_t));
    weapon->head_bullet->first = NULL;
    weapon->damage = 5;
    weapon->shoot_distance = 600;
    sfSprite_setScale(weapon->sprite_bullet, (sfVector2f){2.f, 2.f});
    return weapon;
}

entity_t *create_boss_1(game_t *game)
{
    entity_t *boss = create_single_entity(
        "assets/boss_n1_57_88.png",
        BOSS,
        game->collector,
        &update_boss_1
        );

    create_anim_data(boss,
                        (sfIntRect){0, 0, 57, 88},
                            game->collector,
                                &boss1_animation);
    boss->position = (sfVector2f){0, 0};
    boss->speed = 4.f;
    boss->hp = 1000;
    boss->hp_max = 1000;
    sfSprite_setScale(boss->sprite, (sfVector2f){2.5f, 2.5f});
    set_sprite_origin(boss->sprite);
    boss->weapon = create_boss_1_weapon(game);
    return boss;
}
