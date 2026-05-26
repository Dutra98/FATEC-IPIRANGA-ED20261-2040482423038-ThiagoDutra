/*
Exercicio06-B.c
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
Calcula altura
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
Calcula grau
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
Imprime ancestrais
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
Relatório completo do nó
*/
void relatorioNo(No *raiz,
                 int valor)
{
    No *no =
        buscarNo(raiz,
                 valor);

    if (no == NULL)
    {
        printf("No %d nao encontrado.\n",
               valor);

        return;
    }

    printf("+----------------------------------+\n");

    printf("| RELATORIO DO NO: %-14d |\n",
           valor);

    printf("+----------------------------------+\n");

    printf("| Profundidade : %-16d |\n",
           profundidadeNo(
               raiz,
               valor,
               0));

    printf("| Altura       : %-16d |\n",
           alturaNo(no));

    printf("| Grau         : %-16d |\n",
           grauNo(no));

    printf("| Ancestrais   : ");

    imprimirAncestral(
        raiz,
        valor
    );

    printf("\n");

    printf("| Descendentes : ");

    imprimirDescendentes(
        no->esq
    );

    imprimirDescendentes(
        no->dir
    );

    printf("\n");

    printf("| Qtd Descend. : %-16d |\n",
           contarDescendentes(no) - 1);

    printf("+----------------------------------+\n\n");
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
    Testes pedidos
    */
    relatorioNo(raiz, 50);

    relatorioNo(raiz, 30);

    relatorioNo(raiz, 10);

    relatorioNo(raiz, 70);

    liberarArvore(raiz);

    return 0;
}
