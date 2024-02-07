/*
** EPITECH PROJECT, 2024
** signal
** File description:
** send signal
*/
#include "../include/my_navy.h"
#include "../include/my.h"

void send_signal_one(int pid)
{
    if (kill(pid, SIGUSR1) != 0) {
        my_printf("error sigusr1 send\n");
    }
}

void send_signal_zero(int pid)
{
    if (kill(pid, SIGUSR2) != 0) {
        my_printf("error sigusr2 send\n");
    }
}

void signal_handler_player(int signe)
{
    if (signe == SIGUSR1) {
        received_signal = 1;
    }
    if (signe == SIGUSR2) {
        received_signal = 0;
    }
}
