/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-amir.madaoui [WSL: Ubuntu]
** File description:
** save
*/

#include "../../include/my.h"

int write_save(FILE *file, char *str, int value, char *value2)
{
    fwrite(str, 1, my_strlen(str), file);
    fwrite(":", 1, 1, file);
    if (value2 != NULL)
        fwrite(value2, 1, my_strlen(value2), file);
    else
        fwrite(int_to_str(value), 1, my_strlen(int_to_str(value)), file);
    fwrite("\n", 1, 1, file);
}

int save_file(game_t *game)
{
    FILE *file = fopen("save.txt", "w");
    entity_t *player = get_player_entity(game);

    if (file == NULL)
        return 1;
    write_save(file, "level", game->stat->level, NULL);
    write_save(file, "xp", game->stat->xp, NULL);
    write_save(file, "explosive", game->stat->explosive, NULL);
    write_save(file, "multishot", game->stat->multishot, NULL);
    write_save(file, "range", game->stat->range, NULL);
    write_save(file, "wave", game->wave_data->wave_nb, NULL);
    write_save(file, "hp", player->hp, NULL);
    write_save(file, "point", game->stat->point, NULL);
    write_save(file, "fire_rate", game->stat->fire_rate * 1, NULL);
    fclose(file);
}
