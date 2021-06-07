/*
** EPITECH PROJECT, 2021
** TicTacToe
** File description:
** atoi
*/

static int batoi_sign(char **str)
{
    int sign = 1;

    for (; **str == '-' || **str == '+'; *str += sizeof(char)) {
        if (**str == '-')
            sign *= -1;
    }
    return sign;
}

int batoi(char *str)
{
    int result = -1;
    int sign = batoi_sign(&str);

    for (int i = 0; str[i] && (str[i] >= '0' && str[i] <= '9'); i++) {
        if (result == -1)
            result = 0;
        result *= 10;
        result += str[i] - '0';
    }
    return result * sign;
}
