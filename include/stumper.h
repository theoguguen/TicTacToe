/*
** EPITECH PROJECT, 2020
** stumper
** File description:
** 24/03/2021
*/

#ifndef STUMPER_H
#define STUMPER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char p1;
    char p2;
    int size;
    char **board;
} game_t;

void print_map(game_t *game);

void get_input(game_t *game, char *player, char p);

int check_win(game_t *game, char player);

int check_draw(game_t *game);

int counter(game_t *game, size_t i, size_t j, char player);

void print_win(int i);

int batoi(char *str);

char **binit_array(size_t x, size_t y);

void bfree_array(char **src);

void *bcalloc(size_t nmemb, size_t size);

char **binit_array_light(size_t x);

void *bmemset(void *s, int c, size_t n);

#endif
