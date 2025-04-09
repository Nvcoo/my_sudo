/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** user_verification
*/

#include "../include/utils.h"
#include <crypt.h>

char *password_retrieve(FILE *shadow)
{
    char *hashed_password = strtok(NULL, ":");

    if (hashed_password) {
        fclose(shadow);
        return strdup(hashed_password);
    }
    return NULL;
}

int find_password(char *line, const char *user_given, FILE *shadow)
{
    char *user = strtok(line, ":");

    if (user && strcmp(user, user_given) == 0) {
        strtok(NULL, ":");
        password_retrieve(shadow);
    }
    return 84;
}

char *hashed_password(const char *user_given)
{
    char *line = NULL;
    size_t len = 0;
    FILE *shadow = fopen("/etc/shadow", "r");

    if (shadow == NULL) {
        perror("Error opening /etc/shadow\n");
        return NULL;
    }
    while (getline(&line, &len, shadow) != -1) {
        if (find_password(line, user_given, shadow) == 0) {
            free(line);
            fclose(shadow);
            return 0;
        }
    }
    fclose(shadow);
    free(line);
    return NULL;
}
