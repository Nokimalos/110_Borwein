/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my
*/

#ifndef _MY_H_
#define _MY_H_

#define EXIT_ERROR (84)

void my_putchar(char c);
void my_putstr(char const *str);
void my_put_nbr(int nb);
void my_printf(char *str, ...);
void my_put_strocta(char *str);
void my_put_hexa(int nb);
void my_puthexa_upper(int nb);
void my_put_address(long int nb);
void my_insigned_nbr(unsigned nb);
void my_put_octa(int nb);
void my_put_binary(int nb);
int my_compute_power_it(int nb, int p);
char *my_revstr(char *str);
int my_strlen(char const *str);
int my_atoi(char *str);


int display_usage(int ac, char **av);
void display_result(int n, double res);
int check_number(char *str);
double borwein_integrals(int n, double x);
void midpoint_rule(int n);
void simpson_rule(int n);
void trapezoidal_rule(int n);
int main(int argc, char **argv);

#endif
