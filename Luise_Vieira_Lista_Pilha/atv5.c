// 5.	Escreva um algoritmo que forneça o maior, o menor e a média aritmética do campo idade da pilha.

#include <stdio.h>
#include <stdlib.h>

// 4.	Escreva um procedimento para ordenar a pilha pelo campo código, sendo que no final do processamento os elementos da pilha devem estar dispostos em ordem crescente de seus valores no sentindo fundo topo.

#define MAXTAM 6

typedef struct
{
    int idade[MAXTAM];
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
    P->idade[P->topo] = item; // o valor na posição do topo recebe o item
    P->topo++;
}
int desempilha(tipopilha *P, int *item) // int para retornar se deu certo, apenas para mensagem
{
    if (P->topo == 0)
    {
        printf("Pilha vazia!");
        return 0;
    }
    P->topo--; // desce o topo pq retira o elemento
    *item = P->idade[P->topo];
    return 1;
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
        printf("%d ", P->idade[i]);
    }
}

float media(tipopilha *P)
{
    if (P->topo == 0)
    {
        printf("Pilha Vazia!\n");
        return;
    }
    int maior = P->idade[0];
    int menor = P->idade[0];
    float media = 0;
    for (int i = 0; i < P->topo; i++)
    {
        if (maior < P->idade[i])
        {
            maior = P->idade[i];
        }
        if (menor > P->idade[i])
        {
            menor = P->idade[i];
        }
    }
    int soma = 0;
    for (int i = 0; i < P->topo; i++)
    {
        soma = soma + P->idade[i];
    }
    media = (float)soma / P->topo;
    printf("Maior:%d\n", maior);
    printf("Menor:%d\n", menor);
    printf("Media:%f", media);
}

int main()
{
    tipopilha pilha;
    FPvazia(&pilha);

    int idade;

    printf("Digite as idades para pilha (-1 para parar):\n");
    scanf("%d", &idade);

    while (idade != -1 && !cheia(&pilha)) // enquanto valor digitado for diferente de -1 e nao estiver cheia, continua colocando
    {
        empilhar(&pilha, idade);
        scanf("%d", &idade);
    }

    imprimir(&pilha);
    printf("\n");
    media(&pilha);

    return 0;
}
