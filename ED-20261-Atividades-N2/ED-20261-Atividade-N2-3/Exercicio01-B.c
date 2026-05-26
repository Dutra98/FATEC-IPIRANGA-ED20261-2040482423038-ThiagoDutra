/*
Exercicio01-B.c
*/

#include <stdio.h>

int main(void)
{
    int v[] = {10, 20, 30, 40, 50};

    int *inicio = v;

    int *fim = v + 4;

    int soma = 0;

    printf("VETOR ORIGINAL\n\n");

    while (inicio <= fim)
    {
        /*
        *inicio acessa o valor armazenado
        no endereço apontado pelo ponteiro
        */
        printf("Valor: %d | Endereco: %p\n",
               *inicio,
               (void*)inicio);

        soma += *inicio;

        inicio++;
    }

    printf("\nSoma dos elementos: %d\n\n", soma);

    /* Reinicia os ponteiros */
    inicio = v;
    fim = v + 4;

    /*
    Inversão do vetor usando apenas ponteiros
    */
    while (inicio < fim)
    {
        int temp = *inicio;

        *inicio = *fim;
        *fim = temp;

        inicio++;
        fim--;
    }

    printf("VETOR INVERTIDO\n\n");

    inicio = v;

    while (inicio < v + 5)
    {
        printf("%d ", *inicio);

        inicio++;
    }

    printf("\n");

    return 0;
}
