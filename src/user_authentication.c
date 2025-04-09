/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** user_authentication
*/

#include "../include/utils.h"

int user_authentication(const char *user_given)
{
    int attemps = 3;
    char *password;

    while (attemps > 0) {
        printf("[my_sudo] password for %s:", user_given);
        password = getpass("");
        if (password_verification(user_given, password) == 0) {
            printf("lets gooooo!!!\n");
            return 0;
        }
        attemps--;
        printf("u pringao, try again\n");
    }
    printf("why u trinna get in? you failed, too many incorrect attemps\n");
    return 84;
}
