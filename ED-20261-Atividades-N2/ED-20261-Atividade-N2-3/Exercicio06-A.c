/*
Exercicio06-A.c
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;

    struct No *esq;
    struct No *dir;

} No;

/*
Cria novo nó
*/
No *criarNo(int valor)
{
    No *novo = malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("Erro de alocacao\n");

        exit(1);
    }

    novo->dado = valor;

    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

/*
Inserção na ABB
*/
No *inserir(No *raiz, int valor)
{
    if (raiz == NULL)
    {
        return criarNo(valor);
    }

    if (valor < raiz->dado)
    {
        raiz->esq =
            inserir(raiz->esq,
                     valor);
    }

    else if (valor > raiz->dado)
    {
        raiz->dir =
            inserir(raiz->dir,
                     valor);
    }

    return raiz;
}

/*
Busca nó
*/
No *buscarNo(No *raiz, int valor)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    if (valor == raiz->dado)
    {
        return raiz;
    }

    if (valor < raiz->dado)
    {
        return buscarNo(
            raiz->esq,
            valor
        );
    }

    return buscarNo(
        raiz->dir,
        valor
    );
}

/*
Imprime ancestrais
do pai até a raiz
*/
void imprimirAncestral(No *raiz,
                       int valor)
{
    if (raiz == NULL)
    {
        return;
    }

    if (valor < raiz->dado)
    {
        printf("%d ",
               raiz->dado);

        imprimirAncestral(
            raiz->esq,
            valor
        );
    }

    else if (valor > raiz->dado)
    {
        printf("%d ",
               raiz->dado);

        imprimirAncestral(
            raiz->dir,
            valor
        );
    }
}

/*
Imprime descendentes
em ordem
*/
void imprimirDescendentes(No *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    imprimirDescendentes(
        raiz->esq
    );

    printf("%d ",
           raiz->dado);

    imprimirDescendentes(
        raiz->dir
    );
}

/*
Conta descendentes
*/
int contarDescendentes(No *no)
{
    if (no == NULL)
    {
        return 0;
    }

    return 1
           + contarDescendentes(no->esq)
           + contarDescendentes(no->dir);
}

/*
Libera memória
*/
void liberarArvore(No *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    liberarArvore(raiz->esq);

    liberarArvore(raiz->dir);

    free(raiz);
}

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
        raiz = inserir(
            raiz,
            valores[i]
        );
    }

    int valor = 30;

    No *no =
        buscarNo(raiz,
                 valor);

    if (no != NULL)
    {
        printf("ANCESTRAIS DE %d:\n",
               valor);

        imprimirAncestral(
            raiz,
            valor
        );

        printf("\n\n");

        printf("DESCENDENTES DE %d:\n",
               valor);

        imprimirDescendentes(
            no->esq
        );

        imprimirDescendentes(
            no->dir
        );

        printf("\n\n");

        printf("QUANTIDADE DE DESCENDENTES: %d\n",
               contarDescendentes(no) - 1);
    }

    else
    {
        printf("No nao encontrado.\n");
    }

    liberarArvore(raiz);

    return 0;
}
