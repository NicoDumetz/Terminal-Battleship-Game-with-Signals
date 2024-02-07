/*
** EPITECH PROJECT, 2024
** oijegoj
** File description:
** epihzge
*/
#include "../include/my_navy.h"
#include "../include/my.h"

void send_signal_miss(int pid)
{
    if (kill(pid, SIGUSR1) != 0) {
        my_printf("error\n");
    }
}

void send_signal_hit(int pid)
{
    if (kill(pid, SIGUSR2) != 0) {
        my_printf("error\n");
    }
}

static int attack_player1(int pid_ennemy2)
{
    char *buffer = malloc(3);
    int len = 0;

    while (len < 1) {
        my_printf("attack: ");
        len = read(0, buffer, 3);//verify buffer
    }
    buffer[3] = '\0';
    write_file("commande.txt", buffer);
    //verify tir
    send_signal_hit(pid_ennemy2);
    my_printf("%s: missed or hit\n", buffer);
    free(buffer);
}

static int waiting_player1(int pid_ennemy2)
{
    char *file;

    my_printf("waiting for enemy's attack...\n");
    signal(SIGUSR1, signal_handler_player);
    signal(SIGUSR2, signal_handler_player);
    while (!received_signal);
    file = read_file("commande.txt");
    if (received_signal == 1)
        my_printf("%s: missed\n", file);
    if (received_signal == 2)
        my_printf("%s: hit\n", file);
    free(file);
}

static int display_map_player1(void)
{
    my_printf("my_positions:\n");
    my_printf(" |A B C D E F G H\n-+---------------\n1|. . . . . . . .\n2|. . . . . . . .\n3|. . . . . . . .\n4|. . . . . . . .\n5|. . . . . . . .\n6|. . . . . . . .\n7|. . . . . . . .\n8|. . . . . . . .\n");
    my_printf("enemy's positions:\n");
    my_printf(" |A B C D E F G H\n-+---------------\n1|. . . . . . . .\n2|. . . . . . . .\n3|. . . . . . . .\n4|. . . . . . . .\n5|. . . . . . . .\n6|. . . . . . . .\n7|. . . . . . . .\n8|. . . . . . . .\n");
}

static int game(int pid_ennemy2)
{
    received_signal = 0;
    display_map_player1();
    attack_player1(pid_ennemy2);
    waiting_player1(pid_ennemy2);
}

int player1(int ac, char **av)
{
    int pid_ennemy2;

    connection_player1();
    pid_ennemy2 = my_getnbr(read_file("commande.txt"));
    while (1)
        game(pid_ennemy2);
    return 0;
}
