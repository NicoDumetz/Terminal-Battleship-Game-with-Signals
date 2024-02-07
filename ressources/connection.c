/*
** EPITECH PROJECT, 2024
** connection
** File description:
** cojoegoini
*/
#include "../include/my_navy.h"
#include "../include/my.h"
int received_signal = 0;


static void signal_handler(int signo, siginfo_t *info, void *context)
{
    if (signo == SIGUSR1) {
        received_signal = 1;
        received_signal = info->si_pid;
    }
}

int connection_player1(void)
{
    struct sigaction sa;

    sa.sa_sigaction = signal_handler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    my_printf("my_pid: %d\n\n", getpid());
    my_printf("waiting for enemy...\n");
    while (!received_signal);
    my_printf("\nenemy connected\n\n");
    return 0;
}

int send_signal_co(int pid)
{
    if (kill(pid, SIGUSR1) == 0) {
        my_printf("my_pid: %d\n\n", getpid());
        my_printf("successfully connected to enemy\n\n");
    } else {
        return 84;
    }
    return 0;
}

int connection_player2(int pid)
{
    return send_signal_co(pid);
}
