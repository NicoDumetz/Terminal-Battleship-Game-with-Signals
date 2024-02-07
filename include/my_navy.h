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

int player1(int ac, char **av);
int player2(int ac, char **av);
int connection_player1(void);
int connection_player2(int pid);
char *read_file(char *filename);
int write_file(char *filename, char *content);
char *int_to_str(int nb);
void send_signal_miss(int pid);
void send_signal_hit(int pid);
void signal_handler_player(int signe);


#endif
