/*
** EPITECH PROJECT, 2021
** B-MAT-200-PAR-2-1-110borwein-arnaud.ho-chouck-foune
** File description:
** simpson
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "my.h"

void simpson_rule(int n)
{
    double res = 0;
    double a = 0;
    double b = 5000;
    double sub_intervals = (b - a) / 10000;
    double borwein = 0;

    for (a = 0, b = 0.5; b <= 5000; a += 0.5, b += 0.5) {
        borwein = borwein_integrals(n , a) + 4 * 
        borwein_integrals(n, ((a + b) / 2)) + borwein_integrals(n, b);
        res += sub_intervals / 6 * borwein;
    }
    printf("\nSimpson:\n");
    display_result(n, res);
}