/*
** EPITECH PROJECT, 2024
** write in file
** File description:
** frwire
*/

#include "../include/my_navy.h"
#include "../include/my.h"


int write_file(char *filename, char *content)
{
    int fd = open(filename, O_RDWR | O_TRUNC);
    int check;

    if (fd == -1)
        return 84;
    check = write(fd, content, my_strlen(content));
    if (check == -1)
        return 84;
    close(fd);
}

char *read_file(char *filename)
{
    int fd = open(filename, O_RDONLY);
    int check;
    char *buffer = malloc(1000);

    if (fd == -1)
        return NULL;
    if (buffer == NULL) {
        close(fd);
        return NULL;
    }
    check = read(fd, buffer, 1000 - 1);
    if (check == -1) {
        close(fd);
        free(buffer);
        return NULL;
    }
    buffer[check] = '\0';
    close(fd);
    return buffer;
}

static char *my_revstr_convert(char *str)
{
    int index;
    int len = my_strlen(str) - 1;
    char temp;

    for (index = 0; index < len; index++) {
        temp = str[index];
        str[index] = str[len];
        str[len] = temp;
        len--;
    }
    return str;
}

char *int_to_str(int nb)
{
    char *buffer = malloc(100);
    int i = 0;

    if (nb == 0) {
        buffer[i] = '0';
        i++;
    } else {
        for (i; nb != 0 && i < 100; i++) {
            buffer[i] = '0' + nb % 10;
            nb /= 10;
        }
    }
    buffer[i] = '\0';
    return my_revstr_convert(buffer);
}
