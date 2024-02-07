/*
** EPITECH PROJECT, 2024
** main
** File description:
** maikfjzebeziozoei ozefioze i
*/
#include "include/my.h"
#include "include/my_navy.h"

int main(int ac, char **av)
{
    char **map = get_map(av[1]);

    if (map == NULL)
        return 84;
    if (ac == 3)
        return player2(map, av);
    player1(map);
    return 0;
}
