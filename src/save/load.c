/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** load
*/

#include "../../include/my.h"

char** split(char* str, char delim)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int l;
    int len = my_strlen(str);
    char** tab = malloc(sizeof(char*) * (len + 1));

    for (; str[i] != '\0'; i++) {
        if (str[i] != delim && i != 0)
            continue;
        tab[j] = malloc(sizeof(char) * (len + 1));
        for (l = 0; str[k] != delim && str[k] != '\0'; k++, l++) {
            tab[j][l] = str[k];
        }
        tab[j][l] = '\0';
        j++;
        k++;
    }
    tab[j] = NULL;
    return tab;
}

int compare_string(char *str, char *str2)
{
    int i = 0;
    for (i = 0; str[i] != 0; i++) {
        if (str[i] != str2[i])
            return 0;
    }
    if (str2[i] != 0)
        return 0;
    return 1;
}

void compare_all(char *line, game_t * game)
{
    char **buff = split(line, ':');
    int value = my_get_nbr(buff[1]);
    entity_t *player = get_player_entity(game);

    if (compare_string(buff[0], "level"))
        game->stat->level = value;
    if (compare_string(buff[0], "xp"))
        game->stat->xp = value;
    if (compare_string(buff[0], "hp"))
        player->hp = (float)value;
    if (compare_string(buff[0], "explosive"))
        game->stat->explosive = value;
    if (compare_string(buff[0], "multishot"))
        game->stat->multishot = value;
    if (compare_string(buff[0], "range"))
        game->stat->range = value;
    if (compare_string(buff[0], "point"))
        game->stat->point = value;
    if (compare_string(buff[0], "wave"))
        game->wave_data->wave_nb = value - 1;
}

void compare_all2(char *line, game_t * game)
{
    char **buff = split(line, ':');
    int value = my_get_nbr(buff[1]);

    if (compare_string(buff[0], "fire_rate")) {
        game->stat->fire_rate = (float)value;
    }
}

void init_load_save(game_t *game)
{
    FILE *file = fopen("save.txt", "r");
    char *line = NULL;
    size_t len = 1;
    ssize_t read;

    if (file == NULL)
        return;
    while (1) {
        read = getline(&line, &len, file);
        if (read == -1)
            break;
        compare_all(line, game);
        compare_all2(line, game);
    }
}
