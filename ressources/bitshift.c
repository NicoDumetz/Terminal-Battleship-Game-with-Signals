/*
** EPITECH PROJECT, 2024
** bitshift
** File description:
** bitshift
*/
#include "../include/my_navy.h"
#include "../include/my.h"


int send_pid(int pid, int pid_enemy)
{
    int bit;

    for (int i = (sizeof(int) * 8) - 1; i >= 0; i--) {
        bit = (pid >> i) & 1;
        if (bit == 1) {
            send_signal_one(pid_enemy);
        } else {
            send_signal_zero(pid_enemy);
        }
        usleep(10000);
    }
}

int set_pid_ennemy(int pid_ennemy2)
{
    while (received_signal == -1);
    if (received_signal == 0)
        pid_ennemy2 = (pid_ennemy2 << 1) | 0;
    if (received_signal == 1)
        pid_ennemy2 = (pid_ennemy2 << 1) | 1;
    received_signal = -1;
    return pid_ennemy2;
}

static int send_char(int pid_enemy, char *pos, int index)
{
    int bit;

    for (int i = 7; i >= 0; i--) {
        bit = (pos[index] >> i) & 1;
        if (bit == 1) {
            send_signal_one(pid_enemy);
        } else {
            send_signal_zero(pid_enemy);
        }
        usleep(10000);
    }
}

int send_pos(int pid_enemy, char *pos)
{
    for (int index = 0; index < 2; index++)
        send_char(pid_enemy, pos, index);
}

static int get_char(int index, char *pos)
{
    for (int i = 0; i < 8; i++) {
        while (received_signal == -1);
        if (received_signal == 0)
            pos[index] = (pos[index] << 1) | 0;
        if (received_signal == 1)
            pos[index] = (pos[index] << 1) | 1;
        received_signal = -1;
    }
}

char *get_pos(void)
{
    char *pos = malloc(3);

    pos[0] = 0;
    pos[1] = 0;
    for (int index = 0; index < 2; index++)
        get_char(index, pos);
    pos[2] = '\0';
    return pos;
}
