/*
** EPITECH PROJECT, 2020
** bs
** File description:
** main
*/

#include "stumper.h"

static game_t *init_struct(char **argv)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->p1 = 'X';
    game->p2 = 'O';
    game->size = 3;
    for (int delay = 1; argv[delay]; delay++) {
        if (argv[delay] && argv[delay + 1] && !strcmp(argv[delay], "-p1"))
            game->p1 = argv[delay + 1][0];
        if (argv[delay] && argv[delay + 1] && !strcmp(argv[delay], "-p2"))
            game->p2 = argv[delay + 1][0];
        if (argv[delay] && argv[delay + 1] && !strcmp(argv[delay], "-s") &&
            atoi(argv[delay + 1]) > 0)
            game->size = atoi(argv[delay + 1]);
    }
    game->board = binit_array(game->size, game->size);
    if (game->p1 == game->p2)
        return NULL;
    return game;
}

static int loop(game_t *game)
{
    while (1) {
        get_input(game, "Player 1", game->p1);
        if (check_win(game, game->p1) == 1)
            return 1;
        if (check_draw(game) == 1)
            return 3;
        get_input(game, "Player 2", game->p2);
        if (check_win(game, game->p2) == 1)
            return 2;
        if (check_draw(game) == 1)
            return 3;
    }
    return 0;
}

int main(__attribute__((unused)) int argc, char **argv)
{
    game_t *game = init_struct(argv);
    int i = 0;

    if (!game)
        return 84;
    i = loop(game);
    print_map(game);
    print_win(i);
    bfree_array(game->board);
    free(game);
    return 0;
}
