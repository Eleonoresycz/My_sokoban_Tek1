/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** move
*/

#include "sokoban.h"

void movup(skb_t *sk)
{
    if (sk->tab[sk->yp - 1][sk->xp] == ' ') {
        sk->tab[sk->yp][sk->xp] = ' ';
        sk->tab[sk->yp - 1][sk->xp] = 'P';
    }
    if (sk->tab[sk->yp - 1][sk->xp] == 'X'
    && sk->tab[sk->yp - 2][sk->xp] != '#'
    && sk->tab[sk->yp - 2][sk->xp] != 'X' && sk->yp - 3 >= 0)
        movx_u_d(sk, 1);
    else if (sk->tab[sk->yp - 1][sk->xp] == 'O') {
        sk->tab[sk->yp][sk->xp] = ' ';
        sk->tab[sk->yp - 1][sk->xp] = 'P';
    }
}

void movdown(skb_t *sk)
{
    if (sk->tab[sk->yp + 1][sk->xp] == ' ') {
        sk->tab[sk->yp][sk->xp] = ' ';
        sk->tab[sk->yp + 1][sk->xp] = 'P';
    }
    if (sk->tab[sk->yp + 1][sk->xp] == 'X'
    && sk->tab[sk->yp + 2][sk->xp] != '#'
    && sk->tab[sk->yp + 2][sk->xp] != '#' && sk->yp + 3 < sk->lines)
        movx_u_d(sk, 2);
    else if (sk->tab[sk->yp + 1][sk->xp] == 'O') {
        sk->tab[sk->yp][sk->xp] = ' ';
        sk->tab[sk->yp + 1][sk->xp] = 'P';
    }
}

void movleft(skb_t *sk)
{
    if (sk->tab[sk->yp][sk->xp - 1] == ' ') {
        sk->tab[sk->yp][sk->xp] = ' ';
        sk->tab[sk->yp][sk->xp - 1] = 'P';
    }
    if (sk->tab[sk->yp][sk->xp - 1] == 'X'
    && sk->tab[sk->yp][sk->xp - 2] != '#'
    && sk->tab[sk->yp][sk->xp - 2] != 'X' && sk->xp - 2 > 0) {
        movx_l_r(sk, 3);
    }
    else if (sk->tab[sk->yp][sk->xp - 1] == 'O') {
        sk->tab[sk->yp][sk->xp] = ' ';
        sk->tab[sk->yp][sk->xp - 1] = 'P';
    }
}

void movright(skb_t *sk)
{
    if (sk->tab[sk->yp][sk->xp + 1] == ' ') {
        sk->tab[sk->yp][sk->xp] = ' ';
        sk->tab[sk->yp][sk->xp + 1] = 'P';
    }
    if (sk->tab[sk->yp][sk->xp + 1] == 'X'
    && sk->tab[sk->yp][sk->xp + 2] != '#'
    && sk->tab[sk->yp][sk->xp + 2] != 'X' && sk->xp + 3 < sk->colm) {
        movx_l_r(sk, 4);
    }
    else if (sk->tab[sk->yp][sk->xp + 1] == 'O') {
        sk->tab[sk->yp][sk->xp] = ' ';
        sk->tab[sk->yp][sk->xp + 1] = 'P';
    }
}