/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** init_animal
*/

#include "../../../include/my.h"

void npc_update(entity_t *animal, game_t *game)
{
    entity_t *player = get_player_entity(game);
    int distance = sqrt(pow(player->position.x - animal->position.x, 2) +
        pow(player->position.y - animal->position.y, 2));
    float angle = atan2(player->position.y - animal->position.y,
        player->position.x - animal->position.x);
    sfVector2f direction = {cos(angle), sin(angle)};
    animal->position.x += direction.x * distance / 20;
    animal->position.y += direction.y * distance / 20;
    sfSprite_setPosition(animal->sprite, animal->position);
    if (player->position.x > animal->position.x)
        sfSprite_setScale(animal->sprite, (sfVector2f){2, 2});
    else
        sfSprite_setScale(animal->sprite, (sfVector2f){-2, 2});
}

entity_t *create_animal(collector_t *collector)
{
    entity_t *animal = create_single_entity(
        "assets/pngwing.com.png",
        NPC,
        collector,
        &npc_update
    );

    animal->position = (sfVector2f){300, 300};

    create_anim_data(
        animal,
        (sfIntRect){0, 0, 32, 32},
        collector,
        &npc_animation
        );

    return animal;
}
