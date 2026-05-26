/*
Exercicio02-A.c
*/

#include <stdio.h>

/* Calcula e retorna a média aritmética */
float calcularMedia(float *vet, int n)
{
    float soma = 0.0f;

    float *ptr = vet;

    for (int i = 0; i < n; i++)
    {
        soma += *ptr;

        ptr++;
    }

    return soma / n;
}

/*
Encontra o maior e o menor valor
e armazena nos ponteiros recebidos
*/
void encontrarExtremos(float *vet,
                       int n,
                       float *maior,
                       float *menor)
{
    float *ptr = vet;

    *maior = *ptr;
    *menor = *ptr;

    ptr++;

    for (int i = 1; i < n; i++)
    {
        if (*ptr > *maior)
        {
            *maior = *ptr;
        }

        if (*ptr < *menor)
        {
            *menor = *ptr;
        }

        ptr++;
    }
}

/*
Normaliza o vetor:
cada elemento é dividido pelo maior valor
*/
void normalizar(float *vet, int n)
{
    float maior;
    float menor;

    encontrarExtremos(vet,
                       n,
                       &maior,
                       &menor);

    float *ptr = vet;

    for (int i = 0; i < n; i++)
    {
        *ptr = *ptr / maior;

        ptr++;
    }

    /*
    O vetor original é alterado porque
    a função recebe o endereço do vetor.

    Assim, o ponteiro acessa diretamente
    os valores armazenados na memória.
    */
}

/* Imprime o vetor formatado */
void imprimirVetor(float *vet,
                   int n,
                   const char *titulo)
{
    printf("%s\n", titulo);

    float *ptr = vet;

    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", *ptr);

        ptr++;
    }

    printf("\n\n");
}

int main(void)
{
    float notas[] =
    {
        7.5f,
        3.2f,
        9.8f,
        6.0f,
        5.5f,
        8.1f
    };

    int tamanho = sizeof(notas) / sizeof(notas[0]);

    float media;
    float maior;
    float menor;

    imprimirVetor(notas,
                  tamanho,
                  "Vetor original:");

    media = calcularMedia(notas, tamanho);

    encontrarExtremos(notas,
                       tamanho,
                       &maior,
                       &menor);

    printf("Media: %.2f\n", media);
    printf("Maior valor: %.2f\n", maior);
    printf("Menor valor: %.2f\n\n", menor);

    normalizar(notas, tamanho);

    imprimirVetor(notas,
                  tamanho,
                  "Vetor normalizado:");

    return 0;
}
