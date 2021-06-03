/*
** EPITECH PROJECT, 2021
** B-MAT-200-PAR-2-1-110borwein-arnaud.ho-chouck-foune
** File description:
** utils
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "my.h"

int display_usage(int ac, char **av)
{
    int len = my_strlen(av[1]);

    if (ac != 2)
        return (EXIT_ERROR);
    if (len == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_printf("USAGE.\n    /110borwein n");
        my_printf("\n\nDESCRIPTION\n");
        my_printf("    n  constant defining the");
        my_printf(" integral to be computed\n");
        return (EXIT_SUCCESS);
    }
    return (EXIT_ERROR);
}

void display_result(int n, double res)
{
    double diff = fabs(fabs(res) - fabs(M_PI / 2));

    printf("I%d = %.10f\n", n, res);
    printf("diff = %.10f\n", diff);
}

int check_number(char *str)
{
    for (int i = 0; str[i] != '\0';) {
        if (str[i] < '0' || str[i] > '9')
            return (84);
        else
            i += 1;
    }
    return (0);
}

double borwein_integrals(int n, double x)
{
    double res = 1; 
    double check = 0;

    if (x == 0)
        return (1);
    for (double k = 0; k <= n; k += 1) {
        check = (x / (2 * k + 1));
        res *= sin(x / (2 * k + 1)) / (x / (2 * k + 1));
    }
    return (res);
}