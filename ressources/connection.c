/*
** EPITECH PROJECT, 2024
** connection
** File description:
** cojoegoini
*/
#include "../include/my_navy.h"
#include "../include/my.h"
int received_signal = 0;

static void signal_handler(int signe)
{
    if (signe == SIGUSR1) {
        received_signal = 1;
    }
}

int connection_player1(void)
{
    signal(SIGUSR1, signal_handler);
    my_printf("my_pid: %d\n", getpid());
    my_printf("waiting for enemy connection...\n");
    while (!received_signal);
    my_printf("enemy connected\n");
}

void send_signal_co(int pid)
{
    if (kill(pid, SIGUSR1) == 0 &&
        write_file("commande.txt", int_to_str(getpid())) != 84) {
        my_printf("successfully connected\n");
    } else {
        my_printf("error\n");
    }
}

int connection_player2(int pid)
{
    my_printf("my_pid: %d\n", getpid());
    send_signal_co(pid);
}
