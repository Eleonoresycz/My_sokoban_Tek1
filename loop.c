/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** loop
*/

#include "sokoban.h"

int error_c(skb_t *sk, int i)
{
    if (sk->map[i] != '#' && sk->map[i] != 'O' && sk->map[i] != 'P'
        && sk->map[i] != 'X' && sk->map[i] != '\n' && sk->map[i] != '\0'
        && sk->map[i] != ' ')
        exit (84);
    return (0);
}

void len_terminal(skb_t *sk)
{
    while ((COLS < sk->colm + 5) || (LINES < sk->lines + 5)) {
        erase();
        move(LINES / 2 - 1 , COLS / 2 - 13);
        printw("Too small to print the map");
        refresh();
    }
}

void loop(skb_t *sk, int c)
{
    initscr();
    printage(sk);
    keypad(stdscr, TRUE);
    len_terminal(sk);
    while ((c = wgetch(stdscr)) != 27) {
        len_terminal(sk);
        if (c == ' ') {
            freet(sk);
            mapt(sk);
            refresh();
        }
        move(0, 0);
        posp(sk);
        movep(c, sk);
        checko(sk);
        printage(sk);
        refresh();
        if (victory(sk) == 1 || defeat(sk) == 1)
            break;
    }
}

void end_v(skb_t *sk)
{
    printage(sk);
    free_tab(sk);
    keypad(stdscr, FALSE);
    endwin();
    exit(0);
}

void end_d(skb_t *sk)
{
    printage(sk);
    free_tab(sk);
    keypad(stdscr, FALSE);
    endwin();
    exit(1);
}