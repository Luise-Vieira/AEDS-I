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
void procurarelemento(TipoFila *Fila, int codigo)
{

}


int main()
{

    int op;
    do
    {
        printf("\n\nMENU\n\n");
        printf("Digite a opcão desejada:\n");
        printf("0 - Sair\n");
        printf("1 - Enfileirar\n");
        printf("2 - Imprimir fila\n");
        printf("3 - Procurar elemento na fila\n");
        printf("4 - Desenfileirar\n");
        printf("5 - Verificar o tamanho da fila\n");
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

        }
    }
    while (op!=0);


    return 0;
}
