#include <stdio.h>
#include <stdlib.h>
#include "listaInt.h"

int main()
{
    tLista minhaLista;

    IniciaLista(&minhaLista);

    InsereEmOrdem(&minhaLista, 3);
    InsereEmOrdem(&minhaLista, 2);
    InsereEmOrdem(&minhaLista, 5);
    InsereEmOrdem(&minhaLista, 4);
    InsereEmOrdem(&minhaLista, 1);

    printf("Lista apos insercoes: ");
    ExibeLista(&minhaLista);

    int ind = BuscaBinaria(&minhaLista, 1);
    RemoveElemento(&minhaLista, ind);

    printf("Lista apos remocoes: ");
    ExibeLista(&minhaLista);

    return 0;
}
