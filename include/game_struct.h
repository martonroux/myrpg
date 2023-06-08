/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** game_struct
*/

#pragma once

#include "garbage_collector.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>

typedef struct game_s game_t;
typedef struct entity_s entity_t;

typedef enum game_state_s{
    STATE_MENU,
    STATE_GAME,
    STATE_EXIT,
    STATE_TUTO,
    STATE_SETTINGS
} game_state_t;

typedef enum entity_state_s {
    STATE_NORMAL = 0,
    STATE_HURT = 1,
} entity_state_t;

typedef enum quest_state {
    CAN_QUEST,
    GIVE_QUEST,
    ACTIVE_QUEST,
    DONE_QUEST,
    FAILED_QUEST,
} quest_state_t;

typedef enum quest_type {
    KILL_ZOMBIES,
    KILL_10_SEC,
    DONT_MOVE,
    WAVE_10_PERFECT,
} quest_type_t;

typedef struct quest_s {
    quest_type_t type;
    quest_state_t state;
    int (*quest_condition) (game_t *game);
    int level;
    float quest_nb;
    int current_wave;
    sfText *text;
    char *quest_text;
} quest_t;

typedef struct stat_s {
    int explosive;
    int multishot;
    int range;
    int level;
    int xp;
    int point;
    int max_hp;
    int money;
    int hp_regen;
    int ability;
    float fire_rate;
} stat_t;

typedef struct tutorial_s {
    sfText *movements_text;
    sfText *shoot_text;
    sfText *health_text;
    sfText *boss_health;
    sfText *boss_fight;
    sfText *xp;
    sfText *congratulations;
    bool is_init;
    bool killed_zombies;
    bool killed_boss;
} tutorial_t;

typedef enum entity_type {
    PLAYER = 0,
    ENEMY = 1,
    NPC = 2,
    BOSS = 3,
} entity_type_t;

typedef enum movement_dir_s {
    NONE = 0,
    UP = 1,
    DOWN = 2,
    RIGHT = 3,
    LEFT = 4
} movement_dir_t;

typedef struct keyboard_s {
    bool *isHeld;
    bool *is_clicked_once;
} keyboard_t;

typedef struct texts_s {
    struct texts_s *next;
    sfText *text;
    sfRectangleShape *rect;
    bool hoverable;
    bool selected;
    float time;
    int id;
} texts_t;

typedef struct button_s {
    int is_visible;
    sfRectangleShape *rect;
    sfText *text;
    int (*ptr) (game_t *game);
    struct button_s *next;
} button_t;

typedef struct blood_node_s {
    struct blood_node_s *next;
    sfSprite *sprite;
    sfIntRect rect;
    bool is_dead;
} blood_node_t;

typedef struct anim_data_s {
    sfIntRect anim_rect;
    sfVector2i full_size;
    movement_dir_t movement_dir;
    entity_state_t state;
    void (*anim_func)(entity_t *, sfIntRect, sfVector2i);
} anim_data_t;

typedef struct bullet_s bullet_t;
struct bullet_s {
    bullet_t *next;
    bullet_t *prev;
    sfSprite *sprite;
    sfVector2f direction;
    sfVector2f position;
    stat_t *stat;
    entity_type_t shooter_type;
    bool is_visible;
    bool is_dead;
    float damage;
    int speed;
    int range;
    int angle;
};

typedef struct saved_sprites_s {
    sfSprite *zombie;
    sfTexture *zombie_texture;
    sfSprite *blood;
    sfTexture *blood_texture;
} saved_sprites_t;

typedef struct chunk_s {
    struct chunk_s *next;
    struct chunk_s *prev;
    entity_t *entity;
} chunk_t;

typedef struct bullet_chunk_s {
    struct bullet_chunk_s *next;
    struct bullet_chunk_s *prev;
    bullet_t *bullet;
} bullet_chunk_t;

typedef struct head_chunk_s {
    chunk_t *first;
    bullet_chunk_t *first_bullet;
    sfFloatRect rect;
} head_chunk_t;

typedef struct head_bullet_s {
    bullet_t *first;
} head_bullet_t;

typedef struct weapon_s {
    sfSprite *sprite;
    sfSprite *sprite_bullet;
    head_bullet_t *head_bullet;
    anim_data_t *bullet_anim;
    sfClock *shoot_clock;
    float damage;
    float shoot_rate;
    float shoot_rate_max;
    float shoot_distance;
} weapon_t;

typedef struct entity_s {
    entity_t *next;
    entity_t *prev;
    entity_type_t type;
    anim_data_t *anim_data;
    weapon_t *weapon;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect collider;
    void (*update)(entity_t *, game_t *);
    float speed;
    float hp;
    float hp_max;
    int* chunks;
    bool is_visible;
} entity_t;

typedef struct game_menu_s {
    sfSprite *sprite;
    sfTexture *texture;
    texts_t *texts;
} game_menu_t;

typedef struct head_entity_s {
    entity_t *first;
    blood_node_t *first_blood;
} head_entity_t;

typedef struct wave_data_s {
    sfClock *clock;
    bool started;
    int nb_enemies_left;
    int wave_nb;
} wave_data_t;

typedef struct back_window_s {
    struct back_window_s *next;
    sfSprite *s_fond;
    sfSprite *heart;
    sfSprite *bleu_heart;
    sfSprite *half_heart;
    sfSprite *xp_bar;
    sfSprite *evolution;
    sfSprite *rect_boss;
    sfSprite *icon_boss;
    sfSprite *boss_life;
    sfText *level;
    sfText *wave;
    sfVector2f position;
} back_window_t;

typedef struct inventory_s {
    sfRectangleShape **inv_slot;
    weapon_t *weapon;
    bool is_displayed;
} inventory_t;

typedef struct sound_s {
    sfSound *gun_sound;
    sfSoundBuffer *gun_buffer;
    sfSound *level_up;
    sfSound *boss_sound;
} sound_t;

typedef struct game_s {
    wave_data_t *wave_data;
    collector_t *collector;
    sfRenderWindow *window;
    game_menu_t *game_menu;
    game_menu_t *settings_menu;
    tutorial_t *tutorial;
    sfEvent event;
    button_t *button;
    head_entity_t *head_entity;
    keyboard_t *keyboard;
    head_chunk_t **head_chunk;
    head_chunk_t *outside_screen;
    texts_t *texts;
    sfFont *font;
    inventory_t *inv;
    sfRectangleShape *item_frame;
    sfClock *animation_timer;
    game_state_t state;
    sfView *view;
    back_window_t *background;
    stat_t *stat;
    saved_sprites_t *saved_sprites;
    quest_t *quest;
    sound_t *sound;
    sfVector2f view_size;
    sfText *death_text;
    sfClock *death_clock;
    bool has_died;
} game_t;

game_t* init_game_struct(void);
void init_background(game_t *game);
sfVector2f change_vectorf(sfVector2i vector);
sfVector2i change_vectori(sfVector2f vector);
