/*
** EPITECH PROJECT, 2024
** library
** File description:
** Same as swap function, but with characters
*/

#include "../include/utils.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(const char *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return 0;
}

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void help(int ac, char **av)
{
    int i;

    for (i = 1; i < ac; i++) {
        if (av[i][0] == '-' && av[i][1] == 'h') {
            print_usage(0);
        }
    }
}

void my_perror(char *str)
{
    int len = my_strlen(str);

    write(2, str, len);
    exit(84);
}
