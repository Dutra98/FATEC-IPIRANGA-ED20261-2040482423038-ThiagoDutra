/*
Exercicio03-C.c
*/

#include <stdio.h>

/*
Imprime espaços de acordo
com o nível da recursão
*/
void imprimirIndentacao(int nivel)
{
    for (int i = 0; i < nivel * 2; i++)
    {
        printf(" ");
    }
}

void hanoi(int n,
           char origem,
           char destino,
           char auxiliar,
           int nivel)
{
    /*
    Caso base
    */
    if (n == 1)
    {
        imprimirIndentacao(nivel);

        printf("[Nivel %d] "
               "Mover disco 1 de %c para %c\n",
               nivel,
               origem,
               destino);

        return;
    }

    hanoi(n - 1,
          origem,
          auxiliar,
          destino,
          nivel + 1);

    imprimirIndentacao(nivel);

    printf("[Nivel %d] "
           "Mover disco %d de %c para %c\n",
           nivel,
           n,
           origem,
           destino);

    hanoi(n - 1,
          auxiliar,
          destino,
          origem,
          nivel + 1);
}

int main(void)
{
    int n = 4;

    printf("TORRE DE HANOI\n\n");

    hanoi(n, 'A', 'C', 'B', 0);

    return 0;
}
