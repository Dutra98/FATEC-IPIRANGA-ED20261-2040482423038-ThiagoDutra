/*
Exercicio05-A.c
*/

#include <stdio.h>
#include <stdlib.h>

/*
Estrutura do nó
da árvore binária
*/
typedef struct No
{
    int dado;

    struct No *esq;
    struct No *dir;

} No;

/*
Cria um novo nó
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
Insere valores na ABB
*/
No *inserir(No *raiz, int valor)
{
    /*
    Caso base:
    posição vazia
    */
    if (raiz == NULL)
    {
        return criarNo(valor);
    }

    /*
    Inserção na esquerda
    */
    if (valor < raiz->dado)
    {
        raiz->esq =
            inserir(raiz->esq,
                     valor);
    }

    /*
    Inserção na direita
    */
    else if (valor > raiz->dado)
    {
        raiz->dir =
            inserir(raiz->dir,
                     valor);
    }

    return raiz;
}

/*
Calcula a altura do nó

Retorna:
-1 para ponteiro nulo
*/
int alturaNo(No *no)
{
    if (no == NULL)
    {
        return -1;
    }

    int alturaEsq =
        alturaNo(no->esq);

    int alturaDir =
        alturaNo(no->dir);

    if (alturaEsq > alturaDir)
    {
        return alturaEsq + 1;
    }

    return alturaDir + 1;
}

/*
Calcula a profundidade
de um valor
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
Calcula o grau do nó
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
Libera toda a árvore
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

    printf("Arvore criada com sucesso.\n");

    liberarArvore(raiz);

    return 0;
}
