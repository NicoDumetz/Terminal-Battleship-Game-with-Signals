/*
** EPITECH PROJECT, 2024
** oijegoj
** File description:
** epihzge
*/
#include "../include/my_navy.h"
#include "../include/my.h"

void signal_handler_player(int signe)
{
    if (signe == SIGUSR1) {
        received_signal = 1;
    }
    if (signe == SIGUSR2) {
        received_signal = 2;
    }
}

static int attack_player2(int pid_ennemy)
{
    char *buffer = malloc(1000);
    int len = 0;

    while (len < 1) {
        my_printf("attack: ");
        len = read(0, buffer, 1000); //verify buffer
    }
    buffer[2] = '\0';
    write_file("commande.txt", buffer);//verify tir
    send_signal_miss(pid_ennemy);
    signal(SIGUSR1, signal_handler_player);
    signal(SIGUSR2, signal_handler_player);
    while (!received_signal);
    if (received_signal == 1)
        my_printf("%s: missed\n", buffer);
    if (received_signal == 2)
        my_printf("%s: hit\n", buffer);
    received_signal = 0;
}

static int waiting_player2(int pid_ennemy)
{
    char *file;

    received_signal = 0;
    my_printf("waiting for enemy's attack...\n");
    signal(SIGUSR1, signal_handler_player);
    signal(SIGUSR2, signal_handler_player);
    while (!received_signal);
    file = read_file("commande.txt");
    file[2] = '\0';
    my_printf("%s: missed or hit\n", file); // verifier tir et envoyer send signal
    send_signal_hit(pid_ennemy);
    free(file);
    received_signal = 0;
}

static int display_map_player2(char **map)
{
    my_printf("my_positions:\n");
    display_map(map);
    my_printf("enemy's positions:\n");
    my_printf(" |A B C D E F G H\n-+---------------\n1|. . . . . . . .\n2|. . . . . . . .\n3|. . . . . . . .\n4|. . . . . . . .\n5|. . . . . . . .\n6|. . . . . . . .\n7|. . . . . . . .\n8|. . . . . . . .\n");
}

static int game_loop(int pid_ennemy, char **map)
{
    display_map_player2(map);
    waiting_player2(pid_ennemy);
    attack_player2(pid_ennemy);
}

int player2(char **map, char **av)
{
    int pid_ennemy = my_getnbr(av[2]);

    connection_player2(pid_ennemy);
    //while (1)
        //game_loop(pid_ennemy, map);
    return 0;
}
