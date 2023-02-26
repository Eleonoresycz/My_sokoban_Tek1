/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** end
*/
#include "sokoban.h"

int checko_x(skb_t *sk, int j, int i)
{
    for (int y = 0; sk->tabo[y] != NULL; y++) {
        if (y == j && sk->tabo[y][1] == i) {
            return (1);
        }
    }
    return (0);
}

int check_stuck(skb_t *sk, int j, int i)
{
    if (sk->tab[j][i] == 'X' && checko_x(sk, j, i) != 1) {
        if (sk->tab[j - 1][i] == '#' && (sk->tab[j][i - 1] == '#' ||
        sk->tab[j][i + 1] == '#')) {
            sk->d++;
            return (sk->d);
        }
        else if (sk->tab[j + 1][i] == '#' && (sk->tab[j][i - 1] == '#' ||
        sk->tab[j][i + 1] == '#')) {
            sk->d++;
            return (sk->d);
        }
    }
    return (0);
}

int defeat(skb_t *sk)
{
    sk->d = 0;
    for (int j = 0; sk->tab[j] != NULL; j++) {
        for (int i = 0; sk->tab[j][i] != '\n'; i++) {
            if (check_stuck(sk, j, i) == sk->o)
                return (1);
        }
    }
    return (0);
}

int victory(skb_t *sk)
{
    int v = 0;

    for (int i = 0; sk->tabo[i] != NULL; i++) {
        if (sk->tab[sk->tabo[i][0]][sk->tabo[i][1]] == 'X') {
            v++;
        }
    }
    if (v == sk->o)
        return (1);
    return (0);
}

int checko(skb_t *sk)
{
    for (int i = 0; sk->tabo[i] != NULL; i++) {
        if (sk->tab[sk->tabo[i][0]][sk->tabo[i][1]] == ' ') {
            sk->tab[sk->tabo[i][0]][sk->tabo[i][1]] = 'O';
            return (0);
        }
    }
    return (0);
}