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
    buffer[my_strlen(buffer) - 1] = '\0';
    write_file("commande.txt", buffer);
    //verify tir
    my_printf("%s: missed or hit\n", buffer);
    free(buffer);
    send_signal_miss(pid_ennemy);
}

static int waiting_player2(int pid_ennemy)
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
    received_signal = 0;
}

static int display_map_player2(void)
{
    my_printf("my_positions:\n");
    my_printf(" |A B C D E F G H\n-+---------------\n1|. . . . . . . .\n2|. . . . . . . .\n3|. . . . . . . .\n4|. . . . . . . .\n5|. . . . . . . .\n6|. . . . . . . .\n7|. . . . . . . .\n8|. . . . . . . .\n");
    my_printf("enemy's positions:\n");
    my_printf(" |A B C D E F G H\n-+---------------\n1|. . . . . . . .\n2|. . . . . . . .\n3|. . . . . . . .\n4|. . . . . . . .\n5|. . . . . . . .\n6|. . . . . . . .\n7|. . . . . . . .\n8|. . . . . . . .\n");
}

static int game_loop(int pid_ennemy)
{
    display_map_player2();
    waiting_player2(pid_ennemy);
    attack_player2(pid_ennemy);
}

int player2(int ac, char **av)
{
    int pid_ennemy = my_getnbr(av[1]);

    connection_player2(pid_ennemy);
    while (1)
        game_loop(pid_ennemy);
    return 0;
}
