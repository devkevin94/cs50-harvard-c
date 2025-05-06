#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função para converter uma letra em um índice de 0 a 25
int char_to_index(char c)
{
    if (isalpha(c)) // Verifica se é uma letra do alfabeto
    {
        c = tolower(c); // Converte a letra para minúscula
        return c - 'a'; // Subtrai 'a' para obter um índice de 0 a 25
    }
    return -1; // Retorna -1 se o caractere não for uma letra
}

// Função para cifrar uma letra com a cifra de César
char caesar_cipher(char c, int key)
{
    if (isalpha(c))
    {
        char offset = isupper(c) ? 'A' : 'a';
        return (c - offset + key) % 26 + offset;
    }
    return c;
}

int main(int argc, string argv[])
{
    // Verifica se o número correto de argumentos foi passado
    if (argc != 2)
    {
        printf("Atenção para funcionar corretamente use: ./caesar + chave numerica\n");
        return 1; // Retorna 1 para indicar que houve um erro
    }

    // Converte argv[1] para um número inteiro
    int chave = atoi(argv[1]);

    // Verifica se a conversão foi bem-sucedida
    if (chave == 0 && argv[1][0] != '0')
    {
        printf("Erro: A chave deve ser um número.\n");
        return 1; // Retorna 1 para indicar que houve um erro
    }

    // Pede o texto ao usuário
    string texto = get_string("Texto Normal: ");

    // Cria uma string para armazenar o texto cifrado
    char texto_cifrado[strlen(texto) + 1];

    // Cifra cada caractere do texto
    for (int i = 0; texto[i] != '\0'; i++)
    {
        texto_cifrado[i] = caesar_cipher(texto[i], chave);
    }

    // Adiciona o caractere nulo no final da string cifrada
    texto_cifrado[strlen(texto)] = '\0';

    // Exibe o texto cifrado
    printf("Texto Cifrado: %s\n", texto_cifrado);

    return 0;
}





