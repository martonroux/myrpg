/*
** EPITECH PROJECT, 2023
** None
** File description:
** my
*/

#pragma once

#define PI 3.14159265359
#define ABSOLUTE_VALUE(x) ((x) >= 0 ? (x) : (-x))

#include "garbage_collector.h"
#include "game_struct.h"
#include "linked_list.h"
#include "button_management.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio.h>
#include <stdbool.h>

void update_game(game_t *game);
void init_game(game_t *game);
int check_event(game_t *game);
void add_entity(head_entity_t *head_entity, entity_t *new);
void display_characters(game_t *game);
void display_entities(game_t *game);
void move_characters_main(game_t *game);
head_entity_t *create_entity_ll(collector_t *collector);
entity_t *create_single_entity(
    char *img_path,
    entity_type_t type,
    collector_t *collector,
    void (*update)(entity_t *, game_t *)
    );
void create_anim_data(
    entity_t *entity,
    sfIntRect rect,
    collector_t *collector,
    void (*anim_func)(entity_t *, sfIntRect, sfVector2i)
    );
void *my_malloc(size_t size, collector_t *collector);
void init_game_keyboard(game_t *game);
void create_text(game_t * game, char *str, sfVector2f pos, int size);
texts_t *add_text(game_t *game, sfText *sf_text, collector_t *collector);
void move_player(entity_t *player, game_t *game);
void move_zombie(entity_t *zombie, game_t *game);
void set_sprite_origin(sfSprite *sprite);
int move_toward(sfVector2f *pos, sfVector2f target, float speed);
void change_pos(entity_t *entity, sfVector2f pos_add);
void set_entity_rect(entity_t *entity, sfIntRect rect);
void player_animation(entity_t *entity, sfIntRect rect, sfVector2i size);
void animation_main(game_t *game);
entity_t *get_player_entity(game_t *game);
void display_text(game_t *game);
wave_data_t *init_wave_data(void);
texts_t *temp_text(texts_t *text, float second);
int get_nb_entities(game_t *game);
void init_game_menu(game_t *game);
void update_menu(game_t *game);
int check_event_menu(game_t *game);
void update_text(game_t *game);
int update_camera(game_t *game);
void waves_main(game_t *game);
int display_weapon(game_t *game);
int get_ak47(game_t *game);
int update_player(game_t *game, entity_t *player);
void delete_entity(head_entity_t *head_entity, entity_t *to_del);
int get_nb_enemies(game_t *game);
void display_background(game_t *game);
movement_dir_t change_direction(sfVector2f sum);
void zombie_update(entity_t *zombie, game_t *game);
weapon_t *create_zombie_weapon(float damage, collector_t *collector);
entity_t *create_zombie(game_t *game, collector_t *collector);
double get_vector_delta(sfVector2f vector1, sfVector2f vector2);
void player_get_damaged(game_t *game, entity_t *player, float damage);
void damage_zombie(entity_t *zombie, game_t *game);
entity_t *create_player(game_t *game);
bool enemies_still_alive(game_t *game);
sfVector2f get_pos_outside_screen(game_t *game);
sfVector2f get_direction_toward(sfSprite *bullet,
                                    sfVector2f pos, sfVector2f target);
int display_bullet(game_t *game);
sfSprite *create_sprite(char *path, sfVector2f scale, sfVector2f pos);
bullet_t *create_bullet(game_t *game, sfVector2f pos,
    weapon_t *weapon, int angle);
char *my_strdup(const char *str, collector_t *collector);
void chunks_main(game_t *game);
void delete_all_entities(head_entity_t *head_entity);
head_chunk_t **init_head_chunks(game_t *game);
int get_nb_chunks(head_chunk_t **p_head_chunk);
void add_chunk(head_chunk_t *head_chunk,
                entity_t *data, collector_t *collector);
void assign_chunks(game_t *game);
void delete_chunk(head_chunk_t *head_chunk, chunk_t *to_del);
void remove_all_chunks(head_chunk_t *head_chunk);
int update_bullet(game_t *game);
bullet_t *create_mini_bullet(game_t *game,
    sfVector2f pos, weapon_t *weapon, sfVector2f direction);
entity_t *create_animal(collector_t *collector);
void display_life(game_t *game);
void init_stat(game_t *game);
void update_explosive(game_t *game, bullet_t *bullet);
void npc_animation(entity_t *entity, sfIntRect rect, sfVector2i size);
void add_bullet_chunk(head_chunk_t *head_chunk,
                        bullet_t *data, collector_t *collector);
void delete_bullet_chunk(head_chunk_t *head_chunk, bullet_chunk_t *to_del);
void assign_bullet_chunks(game_t *game, head_bullet_t *head_bullet);
void remove_all_bullet_chunks(head_chunk_t *head_chunk);
void delete_bullet(head_bullet_t *head_bullet,
                    bullet_t *bullet, bullet_t *previous);
void collisions_bullets_zombies(game_t *game);
void kill_zombie(game_t *game, entity_t *entity);
void collisions_main(game_t *game);
saved_sprites_t *init_saved_sprites(game_t *game);
int my_strlen(char *str);
void zombie_animation(entity_t *entity, sfIntRect rect, sfVector2i size);
void add_blood(head_entity_t *head_entity, sfVector2f position,
                saved_sprites_t *saved_sprites);
void delete_blood(head_entity_t *head_entity, blood_node_t *to_del);
void free_entity(entity_t *entity);
void free_blood(blood_node_t *blood_node);
void blood_animation(blood_node_t *blood_node);
void update_blood(game_t *game);
void update_zombie(game_t *game);
char *int_to_str(int nb);
char *my_strcat(char *str, char *target);
int my_get_nbr(char *str);
void display_quest(game_t *game);
void update_quest(game_t *game);
void update_boss_1(entity_t *boss, game_t *game);
void boss1_animation(entity_t *entity, sfIntRect rect, sfVector2i size);
entity_t *create_boss_1(game_t *game);
void boss1_bullet_animation(entity_t *boss, sfIntRect rect, sfVector2i size);
sfVector2f get_bullet_direction(sfSprite *bullet, sfVector2f pos,
                                    sfVector2i mouse_pos, game_t *game);
bullet_t *add_bullet_to_list(bullet_t *bullet, head_bullet_t *head_bullet);
void boss1_shoot(game_t *game, entity_t *entity);
void init_load_save(game_t *game);
int save_file(game_t *game);
void display_life_boss(entity_t *boss, game_t *game);
char *into_str(int nb);
char *my_revstr(char *str, int i);
void display_wave(game_t *game, sfVector2f player_pos, sfVector2f size_window);
void init_inventory(game_t *game);
void init_sound(game_t *game);
void display_inventory(game_t *game);
void update_inventory(game_t *game);
void update_tutorial(game_t *game);
tutorial_t *init_tutorial(game_t *game, tutorial_t *tutorial);
void tutorial_main(game_t *game);
head_chunk_t *init_outside_screen(collector_t *collector);
tutorial_t *partial_init_tutorial(game_t *game);
void spawn_enemies(game_t *game);
void display_tuto_text(game_t *game, tutorial_t *tutorial);
sfText *init_boss_health_text(game_t *game);
sfText *init_boss_fight_text(game_t *game);
sfText *init_congratulation_text(game_t *game);
sfText *init_xp_text(game_t *game);
void create_settings_text(game_t *game, char *str, sfVector2f pos, bool hover);
void update_settings(game_t *game);
int check_event_settings(game_t *game);
void apply_buttons_menu(game_t *game, texts_t *tmp);
void apply_buttons_settings(game_t *game, texts_t *tmp);
quest_t *init_quest(game_t *game);
int get_index_resolution(game_t *game);
void update_death(game_t *game);
void init_death(game_t *game);
void display_death(game_t *game);
bool rect_hovered(sfRectangleShape *rect, sfRenderWindow *window, sfView *view);
