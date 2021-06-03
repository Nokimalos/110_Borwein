/*
** EPITECH PROJECT, 2021
** 108trigo
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "my.h"

int main(int argc, char **argv)
{
    if (argc != 2 || check_number(argv[1]) == 84)
        return (EXIT_ERROR);
    if (display_usage(argc, argv) == EXIT_SUCCESS)
        return (EXIT_SUCCESS);
    check_number(argv[1]);
    midpoint_rule(atoi(argv[1]));
    trapezoidal_rule(atoi(argv[1]));
    simpson_rule(atoi(argv[1]));
    return (EXIT_SUCCESS);
}
