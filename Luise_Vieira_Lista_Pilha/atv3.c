#include <stdlib.h>
#include <stdio.h>

// 3.	Faça um procedimento que parte a pilha em duas outras pilhas.

#define MAXTAM 10

typedef struct
{
    int num[MAXTAM];
    int topo; // N precisa de qtd pq ja mostra quantos itens tem!
} tipopilha;

void FPvazia(tipopilha *P)
{
    P->topo = 0;
}

int cheia(tipopilha *P)
{
    return (P->topo == MAXTAM);
}

void empilhar(tipopilha *P, int item)
{
    if (cheia(P))
    {
        printf("Pilha cheia!!");
        return; // return no void para fechar a função caso essa condição seja verdadeira
    }
    // caso contrario coloca o valor no topo
    P->num[P->topo] = item; // o valor na posição do topo recebe o item
    P->topo++;
}

int desempilha(tipopilha *P, int *item) // int para retornar se deu certo, apenas para mensagem
{
    if (P->topo == 0)
    {
        printf("Fila vazia!");
        return 0;
    }
    P->topo--; // desce o topo pq retira o elemento
    *item = P->num[P->topo];
    return 1;
}

void partirPilha(tipopilha *A, tipopilha *B, tipopilha *C)
{
    int metade = A->topo / 2; // n vamos dividir metade para cada pilha, se for impar uma fica com um a mais
    int cont = 0;
    int x; // auxilia pois armazena o valor retirado de uma pilha temporariamente

    while (A->topo != 0) // enquanto a pilha inicial no caso A n estiver vazia
    {
        desempilha(A, &x); // tira do topo de A e guarda em x
        if (cont < metade)
        {
            empilhar(B, x); // primeira metade vai para B
        }
        else
        {
            empilhar(C, x); // resto vai para C
        }
        cont++;
    }
}

void imprimir(tipopilha *P)
{
    if (P->topo == 0)
    {
        printf("Pilha vazia!");
        return;
    }
    for (int i = P->topo - 1; i >= 0; i--) // topo aponta para ultima posição livre, por isso o -1
    {
        printf("%d ", P->num[i]);
    }
}

int main()
{
    tipopilha pilhaA;
    tipopilha pilhaB;
    tipopilha pilhaC;
    FPvazia(&pilhaA);
    FPvazia(&pilhaB);
    FPvazia(&pilhaC);

    int valor;

    printf("Digite valores para a pilha (-1 para parar):\n");
    scanf("%d", &valor);

    while (valor != -1 && !cheia(&pilhaA)) // enquanto valor digitado for diferente de -1 e nao estiver cheia, continua colocando
    {
        empilhar(&pilhaA, valor);
        scanf("%d", &valor);
    }
    printf("\n Pilha A:\n");
    imprimir(&pilhaA);
    printf("\nPilha B:\n");
    partirPilha(&pilhaA, &pilhaB, &pilhaC);
    imprimir(&pilhaB);
    printf("\nPilha C:\n");
    imprimir(&pilhaC);

    return 0;
}
