/*
** EPITECH PROJECT, 2024
** main
** File description:
** maikfjzebeziozoei ozefioze i
*/
#include "include/my.h"
#include "include/my_navy.h"
#include "lib/my/my_printf/include/my_printf.h"
#include <stdlib.h>

static int help(void)
{
    my_printf("USAGE\n\t./my_navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n\tfirst_player_pid: only for the 2nd player. %s",
    "pid of the first player.\n");
    my_printf("\tnavy_positions: %s",
    "file representing the positions of the ships.\n");
    return 0;
}

int main(int ac, char **av)
{
    char **map;
    char **enemy_map;
    int return_value = 84;

    if (ac >= 2)
        if (my_strncmp(av[1], "-h", 2) == 0)
            return help();
    map = get_map(av[1]);
    if (map == NULL)
        return 84;
    enemy_map = create_void_map();
    if (ac == 3)
        return_value = player2(map, av, enemy_map);
    if (ac == 2)
        return_value = player1(map, enemy_map);
    free_map(map);
    free(enemy_map);
    return return_value;
}
