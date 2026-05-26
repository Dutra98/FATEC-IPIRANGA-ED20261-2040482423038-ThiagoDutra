/*
Exercicio03-A.c
*/

#include <stdio.h>

/*
Função recursiva
das Torres de Hanói
*/
void hanoi(int n,
           char origem,
           char destino,
           char auxiliar)
{
    /*
    Caso base:
    se existir apenas um disco,
    move diretamente
    */
    if (n == 1)
    {
        printf("Mover disco 1 de %c para %c\n",
               origem,
               destino);

        return;
    }

    /*
    Move n-1 discos
    para a haste auxiliar
    */
    hanoi(n - 1,
          origem,
          auxiliar,
          destino);

    /*
    Move o maior disco
    */
    printf("Mover disco %d de %c para %c\n",
           n,
           origem,
           destino);

    /*
    Move os discos restantes
    para a haste destino
    */
    hanoi(n - 1,
          auxiliar,
          destino,
          origem);
}

int main(void)
{
    int n = 3;

    printf("TORRE DE HANOI\n\n");

    hanoi(n, 'A', 'C', 'B');

    return 0;
}
