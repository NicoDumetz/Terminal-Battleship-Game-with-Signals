/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** map.c
*/

#include "../include/my.h"
#include "../include/my_navy.h"

char **create_void_map(void)
{
    char **new_map = malloc(sizeof(char *) * 9);
    char *line = "........\n";

    for (int i = 0; i < 8; i++)
        new_map[i] = my_strdup(line);
    new_map[8] = 0;
    return new_map;
}

static int is_between(char c, char min, char max)
{
    if (c >= min && c <= max)
        return 1;
    return 0;
}

static int check_valid_boat(char a, char b, char c, char d)
{
    return (a != b) && (a != c) && (a != d) && (b != c) && (b != d) &&
        (c != d);
}

static int valid_coord(char *filemap)
{
    for (int i = 0; i <= 24; i += 8) {
        if (!(filemap[i + 2] == filemap[i + 5] ||
            filemap[i + 3] == filemap[i + 6]) ||
            !(ABS(filemap[i + 2] - filemap[i + 5]) == (filemap[i] - '0') ||
            ABS(filemap[i + 3] - filemap[i + 6]) == (filemap[i] - '0')))
            return 1;
    }
    return 0;
}

static int not_valid_map(char *filemap, int readed)
{
    if (readed != 31)
        return 1;
    for (int i = 0; i <= 24; i += 8) {
        if (!is_between(filemap[i], '2', '5') ||
            !is_between(filemap[i + 3], '1', '8') ||
            !is_between(filemap[i + 6], '1', '8') ||
            !is_between(filemap[i + 2], 'A', 'H') ||
            !is_between(filemap[i + 5], 'A', 'H') ||
            filemap[i + 1] != ':' || filemap[i + 4] != ':')
            return 1;
    }
    if (check_valid_boat(filemap[0], filemap[8], filemap[16], filemap[24]))
        return 1;
    if (filemap[7] != '\n' || filemap[15] != '\n' || filemap[23] != '\n')
        return 1;
    if (!valid_coord(filemap))
        return 1;
    return 0;
}

char **get_map(char *filepath)
{
    char **map;
    int fd = open(filepath, O_RDONLY);
    char filemap[31];
    int readed;

    if (fd < 0)
        return 0;
    readed = read(fd, filemap, 31);
    if (not_valid_map(filemap, readed))
        return 0;
    map = create_void_map();
}
