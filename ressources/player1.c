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
        my_printf("error caca\n");
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
    char *buffer = malloc(1000);
    int len = 0;

    while (len < 1) {
        my_printf("attack: ");
        len = read(0, buffer, 1000);//verify buffer
    }
    buffer[2] = '\0';
    write_file("commande.txt", buffer);
    send_signal_miss(pid_ennemy2);
    signal(SIGUSR1, signal_handler_player);
    signal(SIGUSR2, signal_handler_player);
    while (!received_signal);
    if (received_signal == 1)
        my_printf("%s: missed\n", buffer);
    if (received_signal == 2)
        my_printf("%s: hit\n", buffer);
    received_signal = 0;
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
    file[2] = '\0';
    my_printf("%s: missed or hit\n", file); // verifier tir et envoyer send signal
    send_signal_miss(pid_ennemy2);
    free(file);
    received_signal = 0;
}

static int display_map_player1(char **map)
{
    my_printf("my_positions:\n");
    display_map(map);
    my_printf("enemy's positions:\n");
    my_printf(" |A B C D E F G H\n-+---------------\n1|. . . . . . . .\n2|. . . . . . . .\n3|. . . . . . . .\n4|. . . . . . . .\n5|. . . . . . . .\n6|. . . . . . . .\n7|. . . . . . . .\n8|. . . . . . . .\n");
}

static int game(int pid_ennemy2, char **map)
{
    received_signal = 0;
    display_map_player1(map);
    attack_player1(pid_ennemy2);
    waiting_player1(pid_ennemy2);
}

int player1(char **map)
{
    int pid_ennemy2;

    connection_player1();
    pid_ennemy2 = my_getnbr(read_file("commande.txt"));
    //while (1)
        //game(pid_ennemy2, map);
    return 0;
}
