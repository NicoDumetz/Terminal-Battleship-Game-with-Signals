/*
** EPITECH PROJECT, 2024
** oijegoj
** File description:
** epihzge
*/
#include "../include/my_navy.h"
#include "../include/my.h"

void signal_handler_player(int signe)
{
    if (signe == SIGUSR1) {
        received_signal = 1;
    }
    if (signe == SIGUSR2) {
        received_signal = 0;
    }
}

int display_all(char **map)
{
    my_printf("my_positions:\n");
    display_map(map);
    my_printf("enemy's positions:\n");
    my_printf(" |A B C D E F G H\n-+---------------\n1|. . . . . . . .\n2|. . . . . . . .\n3|. . . . . . . .\n4|. . . . . . . .\n5|. . . . . . . .\n6|. . . . . . . .\n7|. . . . . . . .\n8|. . . . . . . .\n");
}

static int game_loop(int pid_ennemy, char **map)
{
    received_signal = -1;
    display_all(map);
    waiting_player(pid_ennemy);
    attack_player(pid_ennemy);
}

int player2(char **map, char **av)
{
    int pid_ennemy = my_getnbr(av[2]);

    connection_player2(pid_ennemy);
    received_signal = -1;
    usleep(10000);
    send_pid(getpid(), pid_ennemy);
    while (1)
        game_loop(pid_ennemy, map);
    return 0;
}
