/*
** EPITECH PROJECT, 2021
** print
** File description:
** map
*/

#include "stumper.h"

static void print_line(int size)
{
    putchar('+');
    for (int c = 0; c < size; c++)
        putchar('-');
    putchar('+');
    putchar('\n');
}

void print_map(game_t *game)
{
    print_line(game->size);
    for (int i = 0; i < game->size; i++)
        printf("|%s|\n", game->board[i]);
    print_line(game->size);
}

void print_win(int i)
{
    if (i == 1)
        printf("Player 1 won!\n");
    if (i == 2)
        printf("Player 2 won!\n");
}
