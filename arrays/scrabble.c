#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int POINT[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Pega as palavras input dos dois jogadores
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Pontua as duas palavras
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Printa o vencedor


    if (score1 > score2)
    {
        printf("Player 1 ganhou! \n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 ganhou! \n");
    }
    else
    {
        printf("EMPATE \n");clear
    }
}

int compute_score(string word)
{
    int score = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char c = word[i];

        if (isalpha(c)) // Verifica se o caractere é uma letra
        {
            if (isupper(c))
            {
                score += POINT[c - 'A'];

            }
            else if (islower(c))
            {
                score += POINT[c - 'a'];

            }

            else if (isdigit(c))
            {
                printf("ERRO: O texto não deve conter números! \n");
                break;
            }
        }

    } return score;
}
