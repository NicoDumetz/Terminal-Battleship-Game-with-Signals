/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** my_navy.h
*/

#ifndef MY_NAVY_HEADER
    #define MY_NAVY_HEADER
    #define ABS(x) (((x) < 0) ? -(x) : (x))
    #include <signal.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <stdint.h>
    #include <stddef.h>
    #include <wchar.h>

extern int received_signal;

int player1(char **map);
int player2(char **map, char **av);
int connection_player1(void);
int connection_player2(int pid);
char *int_to_str(int nb);
void signal_handler_player(int signe);
char **get_map(char *filepath);
int display_map(char **map);
void send_signal_zero(int pid);
void send_signal_one(int pid);
int send_pid(int pid, int pid_enemy);
int set_pid_ennemy(int pid_ennemy2);
char *get_pos(void);
int send_pos(int pid_enemy, char *pos);
int attack_player(int pid_ennemy2);
int waiting_player(int pid_ennemy2);
int display_all(char **map);

#endif
