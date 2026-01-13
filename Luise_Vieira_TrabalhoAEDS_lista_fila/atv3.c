#include <stdio.h>
#include <stdlib.h>
//3.Implemente uma lista por arranjo ordenada, mantendo os elementos sempre em ordem crescente.

#define MAXTAM 5

typedef struct
{
    int num[MAXTAM]; //Aqui guarda os numeros
    int qtd;//pra saber quantos itens ja estão na lista
}TipoLista;

//função para fazer a fila ficar vazia para não pegar lixo de memoria

void FFVazia(TipoLista *L){
    L->qtd=0;
}

int LisrOrdenada(TipoLista *L){
    if(qtd==MAXTAM){
        printf("Lista cheia!");
        return 0;
    }

    
}




int main(){

    return 0;
}