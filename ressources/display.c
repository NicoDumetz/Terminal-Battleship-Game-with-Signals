/*
** EPITECH PROJECT, 2024
** display
** File description:
** display map
*/
#include "../include/my_navy.h"
#include "../include/my.h"

static int display_line(char **map, int i)
{
    for (int j = 0; map[i][j]; j++) {
        my_printf("%c", map[i][j]);
        if (map[i][j + 1] != '\0')
            my_printf(" ");
    }
}

int display_map(char **map)
{
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; map[i]; i++) {
        my_printf("%d|", i + 1);
        display_line(map, i);
        my_printf("\n");
    }
}
