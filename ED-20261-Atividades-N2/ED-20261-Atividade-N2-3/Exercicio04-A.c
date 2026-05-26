/*
Exercicio04-A.c
*/

#include <stdio.h>

/* Contador global de chamadas */
int chamadas = 0;

/*
Busca Binária Recursiva

Retorna:
- índice do elemento encontrado
- ou -1 caso não exista
*/
int buscaBinaria(int *vet,
                 int inicio,
                 int fim,
                 int alvo)
{
    chamadas++;

    /*
    Caso base:
    intervalo inválido
    */
    if (inicio > fim)
    {
        return -1;
    }

    int meio = (inicio + fim) / 2;

    /*
    Caso base:
    elemento encontrado
    */
    if (*(vet + meio) == alvo)
    {
        return meio;
    }

    /*
    Caso recursivo:
    busca na metade esquerda
    */
    if (alvo < *(vet + meio))
    {
        return buscaBinaria(vet,
                            inicio,
                            meio - 1,
                            alvo);
    }

    /*
    Busca na metade direita
    */
    return buscaBinaria(vet,
                        meio + 1,
                        fim,
                        alvo);
}

int main(void)
{
    int dados[] =
    {
        2, 5, 8, 12, 16,
        23, 38, 45, 72, 91
    };

    int tamanho =
        sizeof(dados) / sizeof(dados[0]);

    int alvo;
    int resultado;

    /*
    Busca por valor presente
    */
    alvo = 23;

    chamadas = 0;

    resultado = buscaBinaria(dados,
                             0,
                             tamanho - 1,
                             alvo);

    printf("Busca pelo valor %d\n", alvo);

    printf("Resultado: %d\n", resultado);

    printf("Chamadas recursivas: %d\n\n",
           chamadas);

    /*
    Busca por valor ausente
    */
    alvo = 50;

    chamadas = 0;

    resultado = buscaBinaria(dados,
                             0,
                             tamanho - 1,
                             alvo);

    printf("Busca pelo valor %d\n", alvo);

    printf("Resultado: %d\n", resultado);

    printf("Chamadas recursivas: %d\n\n",
           chamadas);

    /*
    Busca pelo primeiro elemento
    */
    alvo = 2;

    chamadas = 0;

    resultado = buscaBinaria(dados,
                             0,
                             tamanho - 1,
                             alvo);

    printf("Busca pelo valor %d\n", alvo);

    printf("Resultado: %d\n", resultado);

    printf("Chamadas recursivas: %d\n\n",
           chamadas);

    return 0;
}
