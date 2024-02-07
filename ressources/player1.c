/*
** EPITECH PROJECT, 2024
** oijegoj
** File description:
** epihzge
*/
#include "../include/my_navy.h"
#include "../include/my.h"

static int compt_x(char **map)
{
    int compt = 0;

    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            compt += map[i][j] == 'x' ? 1 : 0;
        }
    }
    return compt;
}

int check_victory(int pid_ennemy, char **map, char **map_enemy)
{
    int compt = 0;

    compt = compt_x(map);
    if (compt == 14) {
        display_all(map, map_enemy);
        my_printf("\nEnemy won\n");
        return 1;
    }
    compt = compt_x(map_enemy);
    if (compt == 14) {
        display_all(map, map_enemy);
        my_printf("\nI won\n");
        return 0;
    }
    return 3;
}

int attack_player(int pid_ennemy2, char **map, char **map_enemy)
{
    char *buffer = malloc(1000);
    int len = 0;

    while (len < 1) {
        my_printf("attack: ");
        len = read(0, buffer, 1000);
        buffer[2] = '\0';
        len = check_pos(len, buffer);
    }
    send_pos(pid_ennemy2, buffer);
    received_signal = -1;
    while (received_signal == -1);
    check_missed_or_hit(map_enemy, buffer);
    free(buffer);
}

int waiting_player(int pid_ennemy2, char **map, char **map_enemy)
{
    char *file;

    my_printf("waiting for enemy's attack...\n");
    signal(SIGUSR1, signal_handler_player);
    signal(SIGUSR2, signal_handler_player);
    received_signal = -1;
    while (received_signal == -1);
    file = get_pos();
    check_shoot(map, file, pid_ennemy2);
    free(file);
}

static int game(int pid_ennemy2, char **map, char **map_enemy)
{
    received_signal = -1;
    display_all(map, map_enemy);
    attack_player(pid_ennemy2, map, map_enemy);
    waiting_player(pid_ennemy2, map, map_enemy);
    return check_victory(pid_ennemy2, map, map_enemy);
}

int player1(char **map, char **map_enemy)
{
    int pid_ennemy2 = 0;
    int stop = 3;

    connection_player1();
    received_signal = -1;
    signal(SIGUSR1, signal_handler_player);
    signal(SIGUSR2, signal_handler_player);
    for (int i = 0; i < sizeof(int) * 8; i++) {
        pid_ennemy2 = set_pid_ennemy(pid_ennemy2);
    }
    while (stop == 3)
        stop = game(pid_ennemy2, map, map_enemy);
    return stop;
}
