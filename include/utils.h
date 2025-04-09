/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** Same as swap function, but with characters
*/

#ifndef UTILS_H
    #define UTILS_H

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <sys/sysmacros.h>
    #include <dirent.h>
    #include <string.h>
    #include <errno.h>
    #include <stddef.h>
    #include <sys/types.h>
    #include <grp.h>
    #include <time.h>
    #include <fcntl.h>
    #include "struct.h"

int my_putstr(const char *str);
void my_putchar(char c);
int my_strlen(char const *str);
void help(int ac, char **av);
void my_perror(char *str);
int open_read(const char *user_given);
void print_usage(int status);
int find_user(cur_t *core);
char *hashed_password(const char *user_given);
int password_verification(const char *user_given, const char *password);
int user_authentication(const char *user_given);

#endif
