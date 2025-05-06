#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main (void)
{
    string texto = get_string ("Digite ou cole o texto aqui: ");

    int letras = 0, palavras = 1, sentencas = 0;

    for (int i = 0, n = strlen(texto); i < n; i++ )
    {
            if (isalpha(texto[i]))
            {
                letras++;
            }
            else if (isspace(texto[i]))
            {
                palavras++;
            }
            else if (texto[i] == '.' || texto[i] == '!' || texto[i] == '?')
            {
                sentencas++;
            }
    }

    float L = letras / (float) palavras * 100;
    float S = sentencas / (float) palavras * 100;

      float index = 0.0588 * L - 0.296 * S - 15.8;

     int grade = round(index);

    if (grade < 0)
    {
        printf("Grade Kyds\n");
    }
    else if (grade > 16)
    {
         printf(" Grade 16+ \n");
    }
    else
    {
        printf("Grade %i Anos \n", grade);
    }

}
