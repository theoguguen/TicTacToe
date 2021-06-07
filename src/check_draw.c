/*
** EPITECH PROJECT, 2021
** stumper
** File description:
** check_draw
*/

#include "stumper.h"

int check_draw(game_t *game)
{
    for (int i = 0; i < game->size; i++)
        for (int j = 0; j < game->size; j++)
            if (game->board[i][j] == ' ')
                return 0;
    return 1;
}
