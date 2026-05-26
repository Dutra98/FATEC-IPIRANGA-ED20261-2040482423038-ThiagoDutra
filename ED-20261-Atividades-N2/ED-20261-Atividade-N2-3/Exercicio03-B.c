/*
Exercicio03-B.c
*/

#include <stdio.h>

int movimentos = 0;

void hanoi(int n,
           char origem,
           char destino,
           char auxiliar)
{
    if (n == 1)
    {
        movimentos++;

        printf("Mover disco 1 de %c para %c\n",
               origem,
               destino);

        return;
    }

    hanoi(n - 1,
          origem,
          auxiliar,
          destino);

    movimentos++;

    printf("Mover disco %d de %c para %c\n",
           n,
           origem,
           destino);

    hanoi(n - 1,
          auxiliar,
          destino,
          origem);
}

int main(void)
{
    int n;

    printf("n | Movimentos | 2^n - 1\n");
    printf("--------------------------\n");

    for (n = 1; n <= 6; n++)
    {
        movimentos = 0;

        hanoi(n, 'A', 'C', 'B');

        printf("%d | %d | %d\n",
               n,
               movimentos,
               (1 << n) - 1);

        printf("\n");
    }

    return 0;
}

/*
Tabela esperada:

n | Movimentos | 2^n - 1
--------------------------
1 | 1          | 1
2 | 3          | 3
3 | 7          | 7
4 | 15         | 15
5 | 31         | 31
6 | 63         | 63

Complexidade:
O(2^n)

O número de chamadas cresce
exponencialmente.
*/
