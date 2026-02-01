#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
// 2.	Faça um procedimento no programa visto em aula – Pilha.c - que procura um elemento na pilha pelo campo código.

// codigo da aula:

#define MaxTam 5

typedef int Apontador;

typedef struct
{
    int cod;
    int idade;
} TipoItem;

typedef struct
{
    TipoItem Item[MaxTam];
    Apontador Topo;
} TipoPilha;

TipoPilha Pilha;
TipoItem x;

void FPVazia(TipoPilha *Pilha)
{
    Pilha->Topo = 0;
}

int Vazia(TipoPilha Pilha)
{
    return (Pilha.Topo == 0);
}

void Empilha(TipoItem x, TipoPilha *Pilha)
{
    if (Pilha->Topo == MaxTam)
        printf("\n ERRO: pilha esta cheia\n");
    else
    {
        Pilha->Topo = Pilha->Topo + 1;
        Pilha->Item[Pilha->Topo - 1] = x;
    }
}

void ImprimeTopoFundo(TipoPilha Pilha)
{
    int aux;
    if (Vazia(Pilha))
    {
        printf("Pilha esta Vazia\n");
    }
    else
    {
        for (aux = Pilha.Topo - 1; aux >= 0; aux = aux - 1)
        {
            printf("Cod: %d\n Idade: %d\n\n\n", Pilha.Item[aux].cod, Pilha.Item[aux].idade);
        }
    }
}

void ImprimeFundoTopo(TipoPilha Pilha)
{
    int aux;
    if (Vazia(Pilha))
    {
        printf("Pilha esta Vazia\n");
    }
    else
    {
        for (aux = 0; aux <= Pilha.Topo - 1; aux = aux + 1)
        {
            printf("Cod: %d\n Idade: %d\n\n\n", Pilha.Item[aux].cod, Pilha.Item[aux].idade);
        }
    }
}

void Desempilha(TipoPilha *Pilha, TipoItem *x)
{
    if (Vazia(*Pilha))
    {
        printf("ERRO: Pilha esta Vazia\n");
    }
    else
    {
        *x = Pilha->Item[Pilha->Topo - 1];
        printf("O elemento retirado foi o de codigo %d\n", x->cod);
        Pilha->Topo = Pilha->Topo - 1;
    }
}

int Tamanho(TipoPilha Pilha)
{
    return (Pilha.Topo);
}

void procurarcod(TipoPilha *Pilha, int cod)
{
    if (Vazia(*Pilha))
    {
        printf("Pilha vazia!");
    }
    else
    {
        for (int i = Pilha->Topo - 1; i >= 0; i--)
        {
            if (cod == Pilha->Item[i].cod)
            {
                printf("Codigo: %d, elemento(idade): %d", Pilha->Item[i].cod, Pilha->Item[i].idade);
            }
            return
        }
    }
}

int main()
{
    int opcao, resposta, cod;
    setlocale(LC_ALL, ""); // aceitar acentos
    FPVazia(&Pilha);
    do
    {

        printf("\n\nMENU\n\n");
        printf("Digite a opc�o desejada:\n ");
        printf("0 - Sair\n");
        printf("1 - Esvaziar pilha\n");
        printf("2 - Verificar se a pilha esta vazia\n");
        printf("3 - Inserir elemento na pilha\n");
        printf("4 - Imprimir os elementos da pilha no sentido topo fundo \n");
        printf("5 - Imprimir os elementos da pilha no sentido fundo topo \n");
        printf("6 - Desempilhar elemento da pilha\n");
        printf("7 - Tamanho da Pilha\n");
        printf("8 - Procurar elemento pelo codigo");

        scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:
        {
            printf("PROGRAMA ENCERRADO!\n");
            break;
        }
        case 1:
        {
            FPVazia(&Pilha);
            printf("\nA PILHA VAZIA\n");
            break;
        }
        case 2:
        {
            resposta = Vazia(Pilha);
            if (resposta == 1)
                printf("\n PILHA ESTA VAZIA\n");
            else
                printf("\n PILHA N�O ESTA VAZIA\n");
            break;
        }
        case 3:
        {
            printf("Digite o codigo\n");
            scanf("%d", &x.cod);
            printf("Digite a idade\n");
            scanf("%d", &x.idade);
            Empilha(x, &Pilha);
            break;
        }
        case 4:
        {
            ImprimeTopoFundo(Pilha);
            break;
        }
        case 5:
        {
            ImprimeFundoTopo(Pilha);
            break;
        }

        case 6:
        {
            Desempilha(&Pilha, &x);
            break;
        }

        case 7:
        {
            printf("A pilha tem %d elementos\n", Tamanho(Pilha));
            break;
        }
        case 8:
        {
            printf("Digite o codigo que deseja procurar: ");
            scanf("%d", &cod);
            procurarcod(&Pilha, cod);
            break;
        }

        default:
            printf("\n\nOpcao invalida\n\n");
        } // fim do case

        system("cls");
    } while (opcao != 0); // fim do while
    return (0);
}
