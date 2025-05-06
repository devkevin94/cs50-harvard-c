#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

 char subst_cipher(char c, int key);

int main(int argc, string argv[])
{

    string texto = get_string ("Texto: ");

    // Verifica se o número correto de argumentos foi passado
    if (argc != 2)
    {
        printf("Uso correto: ./programa <mapa>\n");
        return 1; // Retorna 1 para indicar erro
    }

    // Obtém o texto mapeamento do argumento da linha de comando
    string mapa = argv[1];

    // Verifica se o texto tem exatamente 26 caracteres
    if (strlen(mapa) != 26)
    {
        printf("Erro: O texto precisa ter 26 caracteres!\n");
        return 1; // Retorna 1 para indicar erro
    }

    // Verifica se contém números
    for (int i = 0; i < strlen(mapa); i++)
    {
        if (isdigit(mapa[i]))
        {
            printf("Erro: O texto não pode conter números\n");
            return 1; // Retorna 1 para indicar erro
        }
    }

    // Verifica se contém letras repetidas
    int contagem[26] = {0};

    for (int i = 0; i < strlen(mapa); i++)
    {
       // char c = (mapa[i]); // Converte para minúscula para uniformidade

       int index = 0;

        if(isupper(mapa[i]))
        {
             index = mapa[i] - 'A';
        }
        else
        {
             index = mapa[i] - 'a'; // Calcula o índice da letra
        }

        if (contagem[index] > 0)
        {
            printf("Erro: O texto não pode conter letras repetidas\n");
            return 1; // Retorna 1 para indicar erro
        }

        contagem[index]++;
    }

    // Se todas as verificações passarem
    //printf("Texto válido! %s \n", mapa);

    char texto_cifrado[strlen(texto)];



     for (int i = 0; texto[i] != '\0'; i++)
    {
        texto_cifrado[i] = subst_cipher(texto[i], mapa[i]);
    }

    // Adiciona o caractere nulo no final da string cifrada
    texto_cifrado[strlen(texto)] = '\0';

    // Exibe o texto cifrado
    printf("Texto Cifrado: %s\n", texto_cifrado);

    return 0;
}

char subst_cipher(char c, int key)
    {
        if (isalpha(c))
        {
            char offset = isupper(c) ? 'A' : 'a';
            return (c - offset + key) % 26 + offset;
        }
    return c;
    }


