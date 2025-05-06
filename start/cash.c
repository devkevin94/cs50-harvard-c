#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float reais;
    do
    {
        reais = get_float("Troco: ");
    }
    while (reais < 0);

    int centavos = round(reais * 100);

    int moedas = 0;
  
    moedas += centavos / 25;
    centavos %= 25;

    moedas += centavos / 10;
    centavos %= 10;

    moedas += centavos / 5;
    centavos %= 5;
 
    moedas += centavos;

    printf("%i\n", moedas);
}

