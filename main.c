/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** main
*/
#include "include/sokoban.h"

void help(void)
{
    my_putstr("USAGE\n     ./my_sokoban map\nDESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map, ");
    my_putstr("containing '#' for walls, \n          'P' for the player, ");
    my_putstr("'X' for boxes and 'O' for storage locations\n");
}

int error(skb_t *sk)
{
    int cmpo = 0;
    int cmpx = 0;
    int cmpp = 0;

    for (int i = 0; i != my_strlen(sk->map); i++) {
        error_c(sk, i);
        if (sk->map[i] == 'O')
            cmpo++;
        if (sk->map[i] == 'X')
            cmpx++;
        if (sk->map[i] == 'P')
            cmpp++;
    }
    if (cmpo != cmpx || cmpo == 0 || cmpp != 1) {
        exit (84);
    }
    sk->o = cmpo;
    return (0);
}

void printage(skb_t *sk)
{
    for (int i = 0; sk->tab[i] != NULL; i++)
        printw("%s", sk->tab[i]);
}

void game(skb_t *sk)
{
    int c = 0;

    loop(sk, c);
    if (victory(sk) == 1)
        end_v(sk);
    else if (defeat(sk) == 1)
        end_d(sk);
    else {
    keypad(stdscr, FALSE);
    endwin();
    }
    free_tab(sk);
}

int main(int ac, char **av)
{
    skb_t sk;

    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h')
        help();
    open_map(av[1], &sk);
    error(&sk);
    mapt(&sk);
    tabo(&sk);
    game(&sk);
    return (0);
}
