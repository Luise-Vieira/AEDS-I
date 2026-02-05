// 6.	Escrever um algoritmo que leia um número indeterminado de valores inteiros (no máximo 12 elementos). Para cada valor lido, determinar se ele é um número par ou ímpar. Se o número for par, então incluí-lo na PILHA PAR; caso contrário, incluí-lo na PILHA ÍMPAR. Estrutura da pilha por arranjo a ser seguida:

#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 12

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

void parimpar(tipopilha *P, tipopilha *Par, tipopilha *Imp)
{
    if (P->topo == 0)
    {
        printf("Pilha vazia!");
        return;
    }
    int x;
    while (P->topo != 0)
    {
        desempilha(P, &x);
        if (x % 2 == 0)
        {
            empilhar(Par, x);
        }
        else
        {
            empilhar(Imp, x);
        }
    }
}

int main()
{
    tipopilha pilha;
    tipopilha pilhaPar;
    tipopilha pilhaimpar;
    FPvazia(&pilha);
    FPvazia(&pilhaPar);
    FPvazia(&pilhaimpar);

    int valor;

    printf("Digite valores para a pilha (-1 para parar):\n");
    scanf("%d", &valor);

    while (valor != -1 && !cheia(&pilha)) // enquanto valor digitado for diferente de -1 e nao estiver cheia, continua colocando
    {
        empilhar(&pilha, valor);
        scanf("%d", &valor);
    }
    parimpar(&pilha, &pilhaPar, &pilhaimpar);
    printf("Pilha par:\n");
    imprimir(&pilhaPar);
    printf("\n");
    printf("Pilha impar:\n");
    imprimir(&pilhaimpar);
}
