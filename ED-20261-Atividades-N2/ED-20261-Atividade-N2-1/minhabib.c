#include <stdio.h>
#include <stdlib.h>

#include "minhabib.h"

/* Cria nó */
No *criar_no(int valor)
{
    No *novo = malloc(sizeof(No));

    novo->valor = valor;

    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

/* Inserção BST */
No *inserir(No *raiz,
            int valor)
{
    if (raiz == NULL)
    {
        return criar_no(valor);
    }

    if (valor < raiz->valor)
    {
        raiz->esq =
            inserir(raiz->esq,
                     valor);
    }

    else if (valor > raiz->valor)
    {
        raiz->dir =
            inserir(raiz->dir,
                     valor);
    }

    return raiz;
}

/* Busca nó */
No *buscar_no(No *raiz,
              int valor)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    if (valor == raiz->valor)
    {
        return raiz;
    }

    if (valor < raiz->valor)
    {
        return buscar_no(
            raiz->esq,
            valor
        );
    }

    return buscar_no(
        raiz->dir,
        valor
    );
}

/* Nós internos */
void imprimir_nos_internos(No *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    if (raiz->esq != NULL ||
        raiz->dir != NULL)
    {
        printf("%d ",
               raiz->valor);
    }

    imprimir_nos_internos(
        raiz->esq
    );

    imprimir_nos_internos(
        raiz->dir
    );
}

/* Folhas */
void imprimir_folhas(No *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    if (raiz->esq == NULL &&
        raiz->dir == NULL)
    {
        printf("%d ",
               raiz->valor);
    }

    imprimir_folhas(
        raiz->esq
    );

    imprimir_folhas(
        raiz->dir
    );
}

/* Altura */
int calcular_altura(No *no)
{
    if (no == NULL)
    {
        return -1;
    }

    int esq =
        calcular_altura(no->esq);

    int dir =
        calcular_altura(no->dir);

    if (esq > dir)
    {
        return esq + 1;
    }

    return dir + 1;
}

/* Profundidade */
int calcular_profundidade(No *raiz,
                          int valor,
                          int profundidade_atual)
{
    if (raiz == NULL)
    {
        return -1;
    }

    if (valor == raiz->valor)
    {
        return profundidade_atual;
    }

    if (valor < raiz->valor)
    {
        return calcular_profundidade(
            raiz->esq,
            valor,
            profundidade_atual + 1
        );
    }

    return calcular_profundidade(
        raiz->dir,
        valor,
        profundidade_atual + 1
    );
}

/* Ancestrais */
void imprimir_ancestrais(No *raiz,
                         int valor)
{
    if (raiz == NULL)
    {
        return;
    }

    if (valor < raiz->valor)
    {
        printf("%d ",
               raiz->valor);

        imprimir_ancestrais(
            raiz->esq,
            valor
        );
    }

    else if (valor > raiz->valor)
    {
        printf("%d ",
               raiz->valor);

        imprimir_ancestrais(
            raiz->dir,
            valor
        );
    }
}

/* Descendentes */
void imprimir_descendentes(No *no)
{
    if (no == NULL)
    {
        return;
    }

    imprimir_descendentes(no->esq);

    printf("%d ",
           no->valor);

    imprimir_descendentes(no->dir);
}

/* Impressão da subárvore */
void imprimir_subarvore(No *raiz,
                        int nivel)
{
    if (raiz == NULL)
    {
        return;
    }

    for (int i = 0; i < nivel; i++)
    {
        printf("   ");
    }

    printf("%d\n",
           raiz->valor);

    imprimir_subarvore(
        raiz->esq,
        nivel + 1
    );

    imprimir_subarvore(
        raiz->dir,
        nivel + 1
    );
}

/* Impressão por níveis */
void imprimir_niveis(No *raiz,
                     int nivel_atual)
{
    if (raiz == NULL)
    {
        return;
    }

    printf("No %d -> Nivel %d\n",
           raiz->valor,
           nivel_atual);

    imprimir_niveis(
        raiz->esq,
        nivel_atual + 1
    );

    imprimir_niveis(
        raiz->dir,
        nivel_atual + 1
    );
}

/* Diagnóstico principal */
void analisar_arvore(No *raiz,
                     int valorBusca)
{
    printf("RAIZ: %d\n\n",
           raiz->valor);

    printf("NOS INTERNOS:\n");
    imprimir_nos_internos(raiz);

    printf("\n\nFOLHAS:\n");
    imprimir_folhas(raiz);

    printf("\n\nNIVEIS:\n");
    imprimir_niveis(raiz, 0);

    No *no =
        buscar_no(raiz,
                  valorBusca);

    if (no == NULL)
    {
        printf("\nNo nao encontrado.\n");

        return;
    }

    printf("\nDIAGNOSTICO DO NO %d\n",
           valorBusca);

    int grau = 0;

    if (no->esq != NULL)
    {
        grau++;
    }

    if (no->dir != NULL)
    {
        grau++;
    }

    printf("Grau: %d\n",
           grau);

    printf("Altura: %d\n",
           calcular_altura(no));

    printf("Profundidade: %d\n",
           calcular_profundidade(
               raiz,
               valorBusca,
               0));

    printf("Ancestrais: ");
    imprimir_ancestrais(
        raiz,
        valorBusca);

    printf("\n");

    printf("Descendentes: ");

    imprimir_descendentes(no->esq);

    imprimir_descendentes(no->dir);

    printf("\n\nSUBARVORE:\n");

    imprimir_subarvore(no, 0);
}

/* Libera memória */
void liberar_arvore(No *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    liberar_arvore(raiz->esq);

    liberar_arvore(raiz->dir);

    free(raiz);
}
