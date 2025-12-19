#include<stdio.h>
#include<stdlib.h>


#define MaxTam 5

typedef int Apontador;

typedef struct
{
    int cod;
} TipoItem;

typedef struct
{
    TipoItem Item[MaxTam];
    Apontador Frente;
    Apontador Tras;
} TipoFila;

TipoFila Fila;
TipoItem x;
int tamanho=0;

void Enfileira(TipoItem x, TipoFila *Fila)
{
    if (tamanho == MaxTam)
    {
        printf("Fila cheia!\n");
        return;
    }

    Fila->Item[Fila->Tras] = x;
    Fila->Tras = (Fila->Tras + 1) % MaxTam;
    tamanho++;
}

int Vazia (TipoFila Fila)
{
    return(Fila.Frente==Fila.Tras);
}

void imprimir(TipoFila Fila)
{
    int i, aux;
    if(tamanho==0)
    {
        printf("Fila vazia!");
        return;
    }
    else
    {
        aux=Fila.Frente;
        for(i=0; i<tamanho; i++)
        {
            printf("Cod: %d\n", Fila.Item[aux].cod);
            aux = aux + 1;
            if (aux==MaxTam)
                aux=0;
        }
    }


}
void procurarelemento(TipoFila Fila,int codigo)
{
    int flag = 0;
    for(int i=0; i<tamanho; i++)
    {
        if(Fila.Item[i].cod == codigo)
        {
            printf("Codigo encontrado: %d",codigo);
            flag = 1;
        }

    }
    if(flag==0)
    {
        printf("Codigo nao encontrado");
    }

}
void desenfileirar(TipoFila *Fila)
{
    if(Vazia(*Fila))
    {
        printf("Nao foi possivel remover pois a fila esta vazia!");
    }
    else
    {
        Fila->Item[Fila->Frente-1];
        Fila->Frente = (Fila->Frente % MaxTam) + 1;
        tamanho--;
    }

}

void verificarTamanho(int tamanho)
{
    printf("Tamanho da fila: %d", tamanho);
}

int main()
{

    int op, codigo;
    do
    {
        printf("\n\nMENU\n\n");
        printf("Digite a opcão desejada:\n");
        printf("1 - Enfileirar\n");
        printf("2 - Imprimir fila\n");
        printf("3 - Procurar elemento na fila\n");
        printf("4 - Desenfileirar\n");
        printf("5 - Verificar o tamanho da fila\n");
        printf("0 - Sair\n");
        scanf("%d", &op);

        switch(op)
        {
        case 0:
        {
            printf("Programa encerrado!");
            break;
        }
        case 1:
        {
            printf("Digite o codigo\n");
            scanf("%d", &x.cod);
            Enfileira(x, &Fila);
            break;
        }
        case 2:
        {
            imprimir(Fila);
            break;
        }
        case 3:
        {

            printf("Digite o codigo que deseja procurar: ");
            scanf("%d",&codigo);
            procurarelemento(Fila,codigo);
            break;
        }
        case 4:
        {
            desenfileirar(&Fila);
            break;
        }
        case 5:
        {
            verificarTamanho(tamanho);
        }
        }
        printf("\n");
        system("pause");
        system("cls");
    }
    while (op!=0);


    return 0;
}
