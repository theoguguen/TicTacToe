/*
** EPITECH PROJECT, 2021
** counter
** File description:
** c
*/

#include "stumper.h"

int counter(game_t *game, size_t i, size_t j, char player)
{
    if (game->board[i][j] == player)
        return 1;
    return 0;
}
