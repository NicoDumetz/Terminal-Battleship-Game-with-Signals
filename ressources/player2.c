/*
** EPITECH PROJECT, 2024
** oijegoj
** File description:
** epihzge
*/
#include "../include/my_navy.h"
#include "../include/my.h"

int display_all(char **map, char **map_enemy)
{
    my_printf("my navy:\n");
    display_map(map);
    my_printf("\nenemy navy:\n");
    display_map(map_enemy);
    my_printf("\n");
}

int check_shoot(char **map, char *pos, int pid_ennemy2)
{
    int j = pos[0] - 65;
    int i = pos[1] - 49;

    if (map[i][j] == '.' || map[i][j] == 'o' || map[i][j] == 'x') {
        my_printf("\n%s : missed\n\n", pos);
        usleep(100000);
        if (map[i][j] == '.')
            map[i][j] = 'o';
        send_signal_zero(pid_ennemy2);
    } else if (map[i][j] != '.') {
        my_printf("\n%s : hit\n\n", pos);
        usleep(100000);
        map[i][j] = 'x';
        send_signal_one(pid_ennemy2);
    }
}

int check_missed_or_hit(char **map, char *pos)
{
    int j = pos[0] - 65;
    int i = pos[1] - 49;

    if (received_signal == 0) {
        my_printf("\nresult: %s: missed\n\n", pos);
        if (map[i][j] != 'x')
            map[i][j] = 'o';
    }
    if (received_signal == 1) {
        my_printf("\nresult: %s: hit\n\n", pos);
        map[i][j] = 'x';
    }
}

static int game_loop(int pid_ennemy, char **map, char **map_enemy)
{
    received_signal = -1;
    display_all(map, map_enemy);
    waiting_player(pid_ennemy, map, map_enemy);
    attack_player(pid_ennemy, map, map_enemy);
    return check_victory(pid_ennemy, map, map_enemy);
}

int player2(char **map, char **av, char **map_enemy)
{
    int pid_ennemy = my_getnbr(av[2]);
    int stop = 3;

    if (connection_player2(pid_ennemy) == 84)
        return 84;
    received_signal = -1;
    usleep(10000);
    send_pid(getpid(), pid_ennemy);
    while (stop == 3)
        stop = game_loop(pid_ennemy, map, map_enemy);
    return stop;
}
