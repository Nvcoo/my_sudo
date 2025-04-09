/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** print_usage
*/

#include "../include/utils.h"

void print_usage(int status)
{
    printf("usage:\t./my_sudo -h\n");
    printf("usage:\t./my_sudo [-ugEs] [command [args ...]]\n");
    exit(status);
}
