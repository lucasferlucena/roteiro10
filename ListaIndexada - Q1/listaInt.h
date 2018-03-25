#ifndef LISTAINT_H_INCLUDED
#define LISTAINT_H_INCLUDED

#define MAX_ELEMENTOS 50

typedef int tElemento;

typedef struct {
           int       nElementos; /* Número de elementos */
           tElemento elementos[MAX_ELEMENTOS]; /* Os elementos */
} tLista;

/* operacoes essenciais */
extern void IniciaLista(tLista *lista);
extern int Comprimento(const tLista *lista);
extern tElemento ObtemElemento(const tLista *lista, int indice);
extern int InsereElemento(tLista *lista, tElemento item, int indice);
extern tElemento RemoveElemento(tLista *lista, int indice);

/* operacoes adicionais */
extern int EstaVazia(const tLista *lista);
extern int AcrescentaElemento(tLista *lista, tElemento elemento);
extern int BuscaElemento(const tLista *lista, tElemento elemento);
extern void ExibeLista(const tLista *lista);

/* operacoes de lista ordenada
 * (nao usar InsereElemento ou BuscaElemento se for lista ordenada)
 */
 extern int InsereEmOrdem(tLista *lista, tElemento elemento);
 extern int BuscaBinaria(const tLista *lista, tElemento elemento);

#endif // LISTAINT_H_INCLUDED
