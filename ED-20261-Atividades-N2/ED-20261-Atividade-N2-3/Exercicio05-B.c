/*
Exercicio05-B.c
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
Busca um nó
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
Calcula altura do nó
*/
int alturaNo(No *no)
{
    if (no == NULL)
    {
        return -1;
    }

    int esq =
        alturaNo(no->esq);

    int dir =
        alturaNo(no->dir);

    if (esq > dir)
    {
        return esq + 1;
    }

    return dir + 1;
}

/*
Calcula profundidade
*/
int profundidadeNo(No *raiz,
                   int valor,
                   int prof)
{
    if (raiz == NULL)
    {
        return -1;
    }

    if (valor == raiz->dado)
    {
        return prof;
    }

    if (valor < raiz->dado)
    {
        return profundidadeNo(
            raiz->esq,
            valor,
            prof + 1
        );
    }

    return profundidadeNo(
        raiz->dir,
        valor,
        prof + 1
    );
}

/*
Calcula grau do nó
*/
int grauNo(No *no)
{
    int grau = 0;

    if (no->esq != NULL)
    {
        grau++;
    }

    if (no->dir != NULL)
    {
        grau++;
    }

    return grau;
}

/*
Percurso em ordem
mostrando grau dos nós
*/
void imprimirGraus(No *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    imprimirGraus(raiz->esq);

    printf("No %d -> Grau %d\n",
           raiz->dado,
           grauNo(raiz));

    imprimirGraus(raiz->dir);
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

    /*
    Altura dos nós
    */
    int alturas[] =
    {
        50, 30, 70, 20, 10
    };

    printf("ALTURA DOS NOS\n\n");

    for (int i = 0; i < 5; i++)
    {
        No *no =
            buscarNo(raiz,
                     alturas[i]);

        printf("No %d -> Altura %d\n",
               alturas[i],
               alturaNo(no));
    }

    /*
    Profundidade dos nós
    */
    int profundidades[] =
    {
        50, 30, 70, 45, 10
    };

    printf("\nPROFUNDIDADE DOS NOS\n\n");

    for (int i = 0; i < 5; i++)
    {
        printf("No %d -> Profundidade %d\n",
               profundidades[i],
               profundidadeNo(
                   raiz,
                   profundidades[i],
                   0
               ));
    }

    /*
    Graus dos nós
    */
    printf("\nGRAU DOS NOS\n\n");

    imprimirGraus(raiz);

    /*
    Altura total
    */
    printf("\nALTURA TOTAL DA ARVORE: %d\n",
           alturaNo(raiz));

    liberarArvore(raiz);

    return 0;
}
