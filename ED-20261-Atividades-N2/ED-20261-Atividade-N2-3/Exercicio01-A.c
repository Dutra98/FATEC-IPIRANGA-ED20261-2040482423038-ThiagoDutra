/*
Exercicio01-A.c
*/

#include <stdio.h>

/*
Função que troca os valores
usando ponteiros
*/
void trocar(int *a, int *b)
{
    /*
    *a acessa o valor armazenado
    no endereço apontado por a
    */
    *a = *a + *b;

    /*
    Atualiza o valor apontado por b
    */
    *b = *a - *b;

    /*
    Finaliza a troca
    */
    *a = *a - *b;
}

int main(void)
{
    int x = 10;
    int y = 20;

    printf("ANTES DA TROCA\n\n");

    /*
    &x retorna o endereço de memória de x
    */
    printf("Endereco de x: %p\n", (void*)&x);

    /*
    &y retorna o endereço de memória de y
    */
    printf("Endereco de y: %p\n", (void*)&y);

    printf("x = %d\n", x);
    printf("y = %d\n\n", y);

    /*
    Passa os endereços das variáveis
    */
    trocar(&x, &y);

    printf("DEPOIS DA TROCA\n\n");

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}
