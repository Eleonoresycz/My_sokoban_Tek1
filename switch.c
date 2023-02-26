/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** switch
*/

#include "sokoban.h"

void movep(int c, skb_t *sk)
{
    switch (c)
        {
        case KEY_UP:
            if (sk->yp - 1 >= 0)
                movup(sk);
            break;
        case KEY_DOWN:
            if (sk->yp + 1 < sk->lines)
                movdown(sk);
            break;
        default:
            break;
        }
    switch2(c, sk);
}

void switch2(int c, skb_t *sk)
{
    switch (c)
    {
    case KEY_LEFT:
        if (sk->xp - 1 >= 0)
            movleft(sk);
        break;
    case KEY_RIGHT:
        if (sk->xp + 1 < sk->colm)
            movright(sk);
        break;
    default:
        break;
    }
}