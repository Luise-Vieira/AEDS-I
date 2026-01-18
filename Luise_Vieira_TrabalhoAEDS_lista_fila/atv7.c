#include <stdio.h>
#include <stdlib.h>

// 7 Implemente uma fila por arranjo que dobra de tamanho automaticamente quando estiver cheia.

// Sem maxtam pq n tem tamanho maximo
// dobra de tamanho sempre que estiver cheia

typedef struct
{
    int *item; // ponteiro
    int inicio;
    int fim;
    int qtd;
    int capacidade;

} TipoFila;

void FFVazia(TipoFila *F)
{
    F->capacidade = 5;
    F->inicio = 0;
    F->fim = 0;
    F->item = malloc(F->capacidade * sizeof(int));
    F->qtd = 0;
}
void enfileirar(TipoFila *F)
{
    int num=0;

    while (num != -1)
    {
        if (F->qtd == F->capacidade)
        {
            F->capacidade *= 2;
            F->item = realloc(F->item, F->capacidade * sizeof(int));
        }
        printf("Digite o numero (-1 para parar)");
        scanf("%d", &num);

        if (num == -1)
        {
            return;
        }
        F->item[F->fim] = num;
        F->fim++;
        F->qtd++;
    }
}
void imprimir(TipoFila *F)
{
    if (F->qtd == 0)
    {
        printf("Fila vazia!\n");
        return;
    }
    for (int i = F->inicio; i < F->fim; i++)
    {
        printf("%d", F->item[i]);
    }
    printf("\nTamanho atual: %d", F->qtd);
}

int main()
{
    TipoFila fila;
    FFVazia(&fila);
    enfileirar(&fila);
    imprimir(&fila);

    return 0;
}
