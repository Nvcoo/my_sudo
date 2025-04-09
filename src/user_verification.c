/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** user_verification
*/

#include "../include/utils.h"

int user_compare(char *line, const char *user_given)
{
    char *user = strtok(line, ":");

    if (user && strcmp(user, user_given) == 0) {
        return 0;
    }
    return 84;
}

int open_read(const char *user_given)
{
    size_t length = 0;
    char *line = NULL;
    FILE *passwd = fopen("/etc/passwd", "r");

    if (passwd == NULL) {
        my_perror("Error opening /etc/passwd\n");
        exit(84);
    }
    while (getline(&line, &length, passwd) != -1) {
        if (user_compare(line, user_given) == 0) {
            free(line);
            fclose(passwd);
            return 0;
        }
    }
    free(line);
    fclose(passwd);
    return 84;
}
