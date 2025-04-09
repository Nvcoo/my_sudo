/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** password_verification
*/

#include "../include/utils.h"
#include <crypt.h>

int password_verification(const char *user_given, const char *password)
{
    int result;
    char *correct_password = hashed_password(user_given);
    char *password_input = NULL;

    if (correct_password == NULL) {
        perror("User not found or error reading shadow\n");
        return 84;
    }
    password_input = crypt(password, correct_password);
    if (password_input == NULL) {
        free(correct_password);
        perror("Error hashing password\n");
        return 84;
    }
    result = strcmp(password_input, correct_password);
    free(correct_password);
    return (result == 0) ? 0 : 84;
}
