#include <stdio.h>

#include "minhabib.h"

int main(void)
{
    No *raiz = NULL;

    int valores[] =
    {
        50, 30, 70,
        20, 40, 60,
        80, 10, 25,
        45, 65
    };

    int tamanho =
        sizeof(valores) /
        sizeof(valores[0]);

    for (int i = 0; i < tamanho; i++)
    {
        raiz =
            inserir(raiz,
                     valores[i]);
    }

    analisar_arvore(raiz, 30);

    liberar_arvore(raiz);

    return 0;
}
