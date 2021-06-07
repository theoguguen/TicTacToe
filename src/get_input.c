/*
** EPITECH PROJECT, 2021
** stumper
** File description:
** get_input
*/

#include "stumper.h"

static int verif_input(char *buffer, game_t *game, char p)
{
    int nb1 = 0;
    int nb2 = 0;
    int delay = 0;

    nb1 = batoi(buffer);
    for (; buffer[delay] && buffer[delay] != ','; delay++);
    if (delay < (int)strlen(buffer))
        delay++;
    nb2 = batoi(buffer + delay);
    if (nb1 >= 0 && nb1 < game->size && nb2 >= 0 && nb2 < game->size) {
        if (game->board[nb2][nb1] == ' ') {
            game->board[nb2][nb1] = p;
            return 0;
        }
    }
    return 1;
}

void get_input(game_t *game, char *player, char p)
{
    char *buffer = NULL;
    size_t size = 0;

    print_map(game);
    do {
        printf("%s> ", player);
        if (getline(&buffer, &size, stdin) == -1)
            exit(0);
    }
    while (verif_input(buffer, game, p));
    if (buffer)
        free(buffer);
}
