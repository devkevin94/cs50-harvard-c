#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char mapa[100];

    // Obtém o texto digitado pelo usuário
    printf("Digite um texto: ");
    fgets(mapa, sizeof(mapa), stdin);

    // Remove o caractere de nova linha '\n' se presente
    mapa[strcspn(mapa, "\n")] = 0;

    // Array para contar a ocorrência de cada letra (26 letras do alfabeto)
    int contagem[26] = {0};

    // Percorre cada caractere da string
    for (int i = 0; i < strlen(mapa); i++)
    {
        char c = mapa[i];

        // Verifica se o caractere é uma letra
        if (isalpha(c))
        {
            // Converte a letra para minúscula
            c = tolower(c);

            // Incrementa a contagem da letra correspondente
            contagem[c - 'a']++;
        }
    }

    // Verifica se alguma letra foi repetida
    int repetido = 0;
    for (int i = 0; i < 26; i++)
    {
        if (contagem[i] > 1)
        {
            printf("A letra '%c' é repetida.\n", 'a' + i);
            repetido = 1;
        }
    }

    if (!repetido)
    {
        printf("Nenhuma letra repetida.\n");
    }

    return 0;
}
