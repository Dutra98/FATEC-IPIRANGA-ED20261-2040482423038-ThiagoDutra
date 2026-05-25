#include <stdio.h>
#include <stdlib.h>

// ================= STRUCT =================
struct No {
    int valor;
    struct No *esq;
    struct No *dir;
};

// ================= ALTURA =================
int calcularAltura(struct No* n) {
    if (n == NULL) {
        return -1;
    }

    int altura_esq = calcularAltura(n->esq);
    int altura_dir = calcularAltura(n->dir);

    if (altura_esq > altura_dir) {
        return 1 + altura_esq;
    } else {
        return 1 + altura_dir;
    }
}

// ================= FATOR DE BALANCEAMENTO =================
int obterFB(struct No* n) {
    if (n == NULL) return 0;

    int altura_esq = calcularAltura(n->esq);
    int altura_dir = calcularAltura(n->dir);

    return altura_esq - altura_dir;
}

// ================= CRIAR NÓ =================
struct No* criarNo(int valor) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));

    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

// ================= MAIN =================
int main() {

    // Montando a árvore: 20 -> 10 -> 5 -> 2
    struct No* n20 = criarNo(20);
    struct No* n10 = criarNo(10);
    struct No* n5 = criarNo(5);
    struct No* n2 = criarNo(2);

    n20->esq = n10;
    n10->esq = n5;
    n5->esq = n2;

    // Calculando altura
    int altura = calcularAltura(n20);
    printf("Altura da arvore: %d\n", altura);

    // Calculando fator de balanceamento
    int fb = obterFB(n20);
    printf("Fator de Balanceamento da raiz: %d\n", fb);

    return 0;
}