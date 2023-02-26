/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** sokoban
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <fcntl.h>
#include <string.h>
#include "my.h"

typedef struct sokoban
{
    char *map;
    char **tab;
    int **tabo;
    int colm;
    int lines;
    int o;
    int xp;
    int yp;
    int d;

}skb_t;

void open_map(char *map, skb_t *sk);
int colum(skb_t *sk);
int line(skb_t *sk);
int nb_char(skb_t *sk, int j);
void mapt(skb_t *sk);
void loop(skb_t *sk, int c);
void len_terminal(skb_t *sk);
int error_c(skb_t *sk, int i);
void printage(skb_t *sk);

void movep(int c, skb_t *sk);
void switch2(int c, skb_t *sk);
void movx_u_d(skb_t *sk, int i);
void movup(skb_t *sk);
void movdown(skb_t *sk);
void movx_l_r(skb_t *sk, int i);
void movleft(skb_t *sk);
void movright(skb_t *sk);

int posx(skb_t *sk);
int posy(skb_t *sk);
void posp(skb_t *sk);
void tabo(skb_t *sk);
int checko(skb_t *sk);

void freet(skb_t *sk);
void free_tab(skb_t *sk);

int defeat(skb_t *sk);
int check_stuck(skb_t *sk, int j, int i);
int checko_x(skb_t *sk, int j, int i);
int victory(skb_t *sk);

void end_v(skb_t *sk);
void end_d(skb_t *sk);

#endif /* !SOKOBAN_H_ */
