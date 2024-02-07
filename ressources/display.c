/*
** EPITECH PROJECT, 2024
** display
** File description:
** display map
*/
#include "../include/my_navy.h"
#include "../include/my.h"

int display_map(char **map)
{
    int j;

    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; map[i]; i++) {
        my_printf("%d|", i);
        for (j = 0; map[i][j]; j++) {
            my_printf("%c ", map[i][j]);
        }
        my_printf("\n");
    }
}