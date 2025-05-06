#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int ne = get_int("Tamanho de Entrada: ");
    int ns = get_int("Tamanho de Saída: ");
    int counter = 0;

    if(ns < ne)
    {
        printf("Por favor digite um valor maior que a entrada \n");
    }
    else
    {

    while (ne < ns)
    {
        ne = ne + (ne / 3) - (ne / 4);
        counter++;
    }

    printf("Anos: %i\n", counter);
    }

}
