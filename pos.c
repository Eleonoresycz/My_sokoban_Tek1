/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** pos
*/
#include "sokoban.h"

void posp(skb_t *sk)
{
    sk->xp = posx(sk);
    sk->yp = posy(sk);
}

int posy(skb_t *sk)
{
    for (int y = 0; sk->tab[y] != NULL; y++) {
        for (int x = 0; sk->tab[y][x] != '\0'; x++) {
            if (sk->tab[y][x] == 'P')
                return (y);
        }
    }
    return (0);
}

int posx(skb_t *sk)
{
    for (int y = 0; sk->tab[y] != NULL; y++) {
        for (int x = 0; sk->tab[y][x] != '\0'; x++) {
            if (sk->tab[y][x] == 'P')
                return (x);
        }
    }
    return (0);
}

void movx_u_d(skb_t *sk, int i)
{
    if (i == 1){
        sk->tab[sk->yp][sk->xp] = ' ';
        sk->tab[sk->yp - 1][sk->xp] = 'P';
        sk->tab[sk->yp -2][sk->xp] = 'X';
    }
    else {
        sk->tab[sk->yp][sk->xp] = ' ';
        sk->tab[sk->yp + 1][sk->xp] = 'P';
        sk->tab[sk->yp + 2][sk->xp] = 'X';
    }
}

void movx_l_r(skb_t *sk, int i)
{
    if (i == 3) {
        if (sk->tab[sk->yp][sk->xp - 2] == 'O') {
        }
        sk->tab[sk->yp][sk->xp] = ' ';
        sk->tab[sk->yp][sk->xp - 1] = 'P';
        sk->tab[sk->yp][sk->xp - 2] = 'X';
    }
    else {
        if (sk->tab[sk->yp][sk->xp + 2] == 'O') {
        }
        sk->tab[sk->yp][sk->xp] = ' ';
        sk->tab[sk->yp][sk->xp + 1] = 'P';
        sk->tab[sk->yp][sk->xp + 2] = 'X';
    }
}