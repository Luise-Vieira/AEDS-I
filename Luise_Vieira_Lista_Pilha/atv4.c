#include <stdio.h>
#include <stdlib.h>

// 4.	Escreva um procedimento para ordenar a pilha pelo campo código, sendo que no final do processamento os elementos da pilha devem estar dispostos em ordem crescente de seus valores no sentindo fundo topo.

#define MAXTAM 6

typedef struct
{
    int cod[MAXTAM];
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
    P->cod[P->topo] = item; // o valor na posição do topo recebe o item
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
    *item = P->cod[P->topo];
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
        printf("%d ", P->cod[i]);
    }
}

int consultatopo(tipopilha *P) // para comparar o topo para usar na pilha auxiliar
{
    return P->cod[P->topo - 1];
}

void ordenar(tipopilha *P)
{
    tipopilha pilhaaux; // criada aq apenas para ordenar A
    FPvazia(&pilhaaux);
    int x, y;

    while (P->topo != 0) // enquanto a pilha n estiver vazia
    {
        desempilha(P, &x);
        while (pilhaaux.topo != 0 && consultatopo(&pilhaaux) > x)

        {
            desempilha(&pilhaaux, &y);
            empilhar(P, y);
        }
        empilhar(&pilhaaux, x);
    }
    while (pilhaaux.topo != 0)
    {
        desempilha(&pilhaaux, &x);
        empilhar(P, x);
    }
}
int main()
{
    tipopilha pilhacod;
    FPvazia(&pilhacod);

    int valor;

    printf("Digite o codigo para pilha (-1 para parar):\n");
    scanf("%d", &valor);

    while (valor != -1 && !cheia(&pilhacod)) // enquanto valor digitado for diferente de -1 e nao estiver cheia, continua colocando
    {
        empilhar(&pilhacod, valor);
        scanf("%d", &valor);
    }

    ordenar(&pilhacod);
    imprimir(&pilhacod);

    return 0;
}
