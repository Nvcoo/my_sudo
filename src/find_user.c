/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** find_user
*/

#include "../include/utils.h"

int uid_compare(char *line, cur_t *core)
{
    char *user = strtok(line, ":");
    char *uid_str = NULL;

    strtok(NULL, ":");
    uid_str = strtok(NULL, ":");
    if (uid_str && atoi(uid_str) == core->uid) {
        core->username = strdup(user);
        return 0;
    }
    return 84;
}

int find_user(cur_t *core)
{
    size_t length = 0;
    char *line = NULL;
    FILE *passwd = fopen("/etc/passwd", "r");

    core->uid = getuid();
    if (passwd == NULL) {
        my_perror("Error opening /etc/passwd\n");
        exit(84);
    }
    while (getline(&line, &length, passwd) != -1) {
        if (uid_compare(line, core) == 0) {
            free(line);
            fclose(passwd);
            return 0;
        }
    }
    free(line);
    fclose(passwd);
    return 84;
}
