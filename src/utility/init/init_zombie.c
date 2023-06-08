/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** init_zombie.c
*/

#include "../../../include/my.h"

entity_t *create_zombie_entity(
    game_t *game,
    collector_t *collector,
    void (*update)(entity_t *, game_t *)
)
{
    entity_t *new = my_malloc(sizeof(entity_t), collector);

    new->sprite = sfSprite_copy(game->saved_sprites->zombie);
    new->texture = sfTexture_copy(game->saved_sprites->zombie_texture);
    new->hp = 10;
    new->is_visible = 1;
    new->next = NULL;
    new->prev = NULL;
    new->update = update;
    new->type = ENEMY;
    new->speed = 6.f;
    new->chunks = NULL;
    return new;
}

weapon_t *create_zombie_weapon(float damage, collector_t *collector)
{
    weapon_t *weapon = my_malloc(sizeof(weapon_t), collector);

    weapon->sprite = NULL;
    weapon->sprite_bullet = sfSprite_create();
    sfSprite_setTexture(weapon->sprite_bullet,
                            sfTexture_createFromFile("assets/test.png", NULL),
                            sfTrue);
    weapon->bullet_anim = NULL;
    weapon->damage = damage;
    weapon->shoot_distance = 50;
    weapon->head_bullet = NULL;
    weapon->shoot_rate = 1.f;
    weapon->shoot_clock = sfClock_create();

    return weapon;
}

entity_t *create_zombie(game_t *game, collector_t *collector)
{
    entity_t *zombie = create_zombie_entity(
        game,
        collector,
        &zombie_update
    );

    create_anim_data(zombie, (sfIntRect){0, 0, 64, 64},
                        collector, &zombie_animation);
    zombie->weapon = create_zombie_weapon(1, collector);
    zombie->speed = 3.5f;
    sfSprite_setScale(zombie->sprite, (sfVector2f){2, 2});
    return zombie;
}
