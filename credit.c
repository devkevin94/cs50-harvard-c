#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
 
    long card = get_long("Digite apenas os números do cartão (sem ífem): ");

    // Extrai cada dígito do número do cartão
    int d[16];
    for (int i = 0; i < 16; i++) {
        d[i] = card % 10;
        card /= 10;
    }

 
    int soma1 = 0;
    for (int i = 1; i < 16; i += 2) {
        int valida = d[i] * 2;
        soma1 += (valida / 10) + (valida % 10);  
    }

    
    int soma2 = 0;
    for (int i = 0; i < 16; i += 2) {
        soma2 += d[i];
    }

    
    int finaltotal = soma1 + soma2;

 
    int valida = finaltotal % 10;

    
    if (valida == 0) {
        printf("CARTAO VÁLIDO \n");
    } else {
        printf("CARTÃO INVÁLIDO \n");
    }

    int primeiro = d[15];
    int segundo = d[14];

    if ( primeiro == 5 && segundo >= 1)
    {
        printf("MASTER CARD \n");
    }
    else if (primeiro == 4)
    {
        printf("VISA \n");
    }
    else
    {
        printf("NÃO INDENTIFICADO \n");
    }

}
