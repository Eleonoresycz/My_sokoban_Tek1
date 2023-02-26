/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** tab_int
*/
#include "sokoban.h"

void tabo(skb_t *sk)
{
    int j = 0;

    sk->tabo = malloc(sizeof(int *) * (sk->o + 1));
    for (int i = 0; i != sk->o; i++)
        sk->tabo[i] = malloc(sizeof(int) * 3);
    for (int y = 0; sk->tab[y] != NULL; y++) {
        for (int x = 0; sk->tab[y][x] != '\0'; x++) {
            if (sk->tab[y][x] == 'O') {
                sk->tabo[j][0] = y;
                sk->tabo[j][1] = x;
                j++;
            }
        }
    }
    sk->tabo[j] = NULL;
}

void freet(skb_t *sk)
{
    for (int i = 0; sk->tab[i] != NULL; i++)
        free(sk->tab[i]);
    free(sk->tab);
}

void free_tab(skb_t *sk)
{
    free(sk->map);
    for (int i = 0; sk->tab[i] != NULL; i++)
        free(sk->tab[i]);
    free(sk->tab);
    for (int i = 0; sk->tabo[i] != NULL; i++)
        free(sk->tabo[i]);
    free(sk->tabo);
}