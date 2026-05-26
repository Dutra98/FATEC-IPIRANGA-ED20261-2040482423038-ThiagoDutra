/*
Exercicio05-C.c
*/

#include <stdio.h>

/*

ESTRUTURA DA ABB

                50
              /    \
            30      70
           /  \    /  \
         20   40  60   80
        / \     \    \
      10  25    45   65


VERIFICACAO MANUAL

-----------------------------------
NO 50
-----------------------------------
Altura:
3

Profundidade:
0

Grau:
2


-----------------------------------
NO 30
-----------------------------------
Altura:
2

Profundidade:
1

Grau:
2


-----------------------------------
NO 10
-----------------------------------
Altura:
0

Profundidade:
3

Grau:
0


-----------------------------------
NO 70
-----------------------------------
Altura:
2

Profundidade:
1

Grau:
2


-----------------------------------
OBSERVACOES
-----------------------------------

Altura:
Maior caminho do no ate uma folha.

Profundidade:
Distancia da raiz ate o no.

Grau:
Quantidade de filhos diretos.

Folhas:
Nos com grau 0.

Neste caso:
10, 25, 45, 65 e 80.
*/

int main(void)
{
    printf("Verificacao manual da ABB concluida.\n");

    return 0;
}
