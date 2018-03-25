#include "listaInt.h"
#include <stdio.h>
#include <stdlib.h>

static int EstaCheia(const tLista *lista){
    return lista->nElementos >= MAX_ELEMENTOS - 1;
}

void IniciaLista(tLista *lista){
    lista->nElementos = 0;
    lista->elementos[0] = 0;
}

int Comprimento(const tLista *lista){
    return lista->nElementos; /* Não há o que calcular */
}

tElemento ObtemElemento(const tLista *lista, int indice){
    if (indice < 0 || indice >= lista->nElementos + 1) {
        printf("\nElemento inexistente\n");
        exit(1);
    }

    return lista->elementos[indice];
}

int InsereElemento(tLista *lista, tElemento item, int indice){
    /* Se a lista estiver cheia, não há */
    /* como inserir mais um elemento    */
    if (EstaCheia(lista)) {
        printf("\nA lista esta cheia\n");
        return 1;
    }
    /* Verifica se o índice é válido */
    if (indice < 0 || indice > lista->nElementos + 1) {
        printf("\nPosicao de insercao inexistente\n");
        return 1;
    }

    /* Abre espaço para o novo elemento */
    int i;
    for (i = lista->nElementos; i >= indice; --i)
        lista->elementos[i + 1] = lista->elementos[i];

    /* Insere o novo elemento */
    lista->elementos[indice] = item;
    lista->nElementos++; /* O tamanho da lista aumentou */
    lista->elementos[0] = lista->nElementos;

    return 0;
}

tElemento RemoveElemento(tLista *lista, int indice){
    if(indice == 0){
        puts("Nao eh permitido alterar o numero de elementos");
        exit(1);
    }

    tElemento itemRemovido;
    /* Verifica se o índice é válido */
    if (indice < 0 || indice >= lista->nElementos + 1) {
        printf("\nPosicao de remocao inexistente\n");
        exit(1);
    }
    itemRemovido = lista->elementos[indice];

    /* Remover um elemento significa mover cada elemento  */
    /* uma posição para trás a partir do próximo elemento */
    /* adiante daquele que será  removido                 */
    int i;
    for (i = indice; i < lista->nElementos; i++)
        lista->elementos[i] = lista->elementos[i + 1];

    --lista->nElementos; /* O tamanho da lista diminuiu */
    lista->elementos[0] = lista->nElementos;
    return itemRemovido;
}

int EstaVazia(const tLista *lista){
    return lista->nElementos == 0;
}

int AcrescentaElemento(tLista *lista, tElemento elemento){
    /* Verifica se é possível acrescentar */
    /* mais um elemento na lista          */
    if (EstaCheia(lista)) {
        return 1; /* A lista está cheia */
    }

    /* Acrescenta um novo elemento ao final da lista */
    lista->elementos[lista->nElementos] = elemento;
    ++lista->nElementos; /* O tamanho da lista aumentou */

    return 0;
}

int BuscaElemento(const tLista *lista, tElemento elemento){
    int i;
    for (i = 1; i < lista->nElementos + 1; ++i) {
        if (lista->elementos[i] == elemento) {
            return i; /* Elemento foi encontrado */
        }
    }

    return -1; /* Elemento não foi encontrado */
}

void ExibeLista(const tLista *lista){
    int i;
    for(i = 0; i < Comprimento(lista) + 1; i++){
        printf("[%d] = %d%s", i, ObtemElemento(lista, i),
                i == Comprimento(lista) ? "\n" : ", ");
    }
}

int InsereEmOrdem(tLista *lista, tElemento elemento){
    int indice;
    /* procura a posicao na lista que o elemento deve estar */
    for (indice = 1; indice <= lista->nElementos; indice++){
        if (lista->elementos[indice] > elemento){
            break;
        }
    }

    /* usa a implementacao de InsereElemento na posicao encontrada */
    return InsereElemento(lista, elemento, indice);
}

int BuscaBinaria(const tLista *lista, tElemento elemento){
    int inf, sup, meio;

    inf = 1;
    sup = Comprimento(lista);

    while(inf <= sup){
        meio = (inf + sup) / 2;
        if (lista->elementos[meio] == elemento){
            return meio; //posicao do elemento encontrado
        }

        if (elemento < lista->elementos[meio]){
            sup = meio - 1;
        }else{
            inf = meio + 1;
        }
    }

    return -1; //elemento nao encontrado
}


