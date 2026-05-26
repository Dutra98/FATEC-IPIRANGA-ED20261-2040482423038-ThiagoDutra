/*
Exercicio04-B.c
*/

#include <stdio.h>

/* Contador global de chamadas */
int chamadas = 0;

/*
Calcula base^exp usando
potenciação rápida recursiva

Complexidade:
O(log n)
*/
long long potenciaRapida(long long base,
                         int exp)
{
    chamadas++;

    /*
    Caso base:
    qualquer número elevado a 0 é 1
    */
    if (exp == 0)
    {
        return 1;
    }

    /*
    Se o expoente for par
    */
    if (exp % 2 == 0)
    {
        long long metade;

        metade = potenciaRapida(base,
                                exp / 2);

        return metade * metade;
    }

    /*
    Caso recursivo para expoente ímpar
    */
    return base *
           potenciaRapida(base,
                          exp - 1);
}

int main(void)
{
    chamadas = 0;

    printf("2^10 = %lld\n",
           potenciaRapida(2, 10));

    printf("Chamadas recursivas: %d\n\n",
           chamadas);

    chamadas = 0;

    printf("3^7 = %lld\n",
           potenciaRapida(3, 7));

    printf("Chamadas recursivas: %d\n\n",
           chamadas);

    chamadas = 0;

    printf("5^0 = %lld\n",
           potenciaRapida(5, 0));

    printf("Chamadas recursivas: %d\n\n",
           chamadas);

    chamadas = 0;

    printf("7^12 = %lld\n",
           potenciaRapida(7, 12));

    printf("Chamadas recursivas: %d\n\n",
           chamadas);

    return 0;
}

/*
Comparação de complexidade

Forma ingênua:
b^n = b * b^(n-1)

Complexidade:
O(n)

Potenciação rápida:
divide o problema pela metade
a cada chamada recursiva.

Complexidade:
O(log n)

Isso reduz significativamente
a quantidade de chamadas recursivas.
*/
