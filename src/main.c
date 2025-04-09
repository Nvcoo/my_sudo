/*
** EPITECH PROJECT, 2024
** mainfile
** File description:
** Same as swap function, but with characters
*/

#include "../include/utils.h"

int main(int ac, char **av)
{
    cur_t core = {0};

    if (ac < 2) {
        print_usage(84);
    }
    find_user(&core);
    help(ac, av);
    if (user_authentication(core.username) == 84) {
        return 84;
    }
    return 0;
}
