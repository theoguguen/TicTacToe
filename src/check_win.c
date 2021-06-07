/*
** EPITECH PROJECT, 2021
** check
** File description:
** win
*/

#include "stumper.h"

static int check_horizontal(game_t *game, char player)
{
    int count = 0;

    for (int i = 0; i < game->size; i++) {
        count = 0;
        for (int j = 0; j < game->size; j++)
            count += counter(game, i, j, player);
        if (count == game->size)
            return 1;
    }
    return 0;
}

static int check_vertical(game_t *game, char player)
{
    int count = 0;

    for (int j = 0; j < game->size; j++) {
        count = 0;
        for (int i = 0; i < game->size; i++)
            count += counter(game, i, j, player);
        if (count == game->size)
            return 1;
    }
    return 0;
}

static int check_diagonal(game_t *game, char player)
{
    int j = game->size - 1;
    int count = 0;

    for (int i = 0; i < game->size; i++) {
        count += counter(game, i, i, player);
        if (count == game->size)
            return 1;
    }
    count = 0;
    for (int i = 0; i < game->size; i++, j--) {
        count += counter(game, i, j, player);
        if (count == game->size)
            return 1;
    }
    return 0;
}

int check_win(game_t *game, char player)
{
    if (check_horizontal(game, player) == 1)
        return 1;
    if (check_vertical(game, player) == 1)
        return 1;
    if (check_diagonal(game, player) == 1)
        return 1;
    return 0;
}
