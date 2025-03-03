//
// Created by Stanis on 24/2/25.
//
#define DIM 10
#include "Elemento.h"
#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H
typedef struct {
    tElemento almacen[DIM];

    int posOcupada;
}TLista;
void asignarElemento(tElemento *dest, tElemento src);

// Constructoras generadoras
void crearListaVacia(TLista *l);
void construir(TLista *l, tElemento elem);
// Observadoras selectoras
void obtenerPrimeroLista(TLista l, tElemento* elem);
void restoListaL (TLista *res, TLista l);
void ultimoLista(tElemento *e, TLista l);
// Observadoras no selectoras
int esListaVacia(TLista l);
int longitudLista (TLista l);
int perteneceLista (tElemento e, TLista l);
// Constructoras no generadoras
void insertarListaFinal(TLista *l, tElemento elem);
void eliminarElementoLista(TLista *l, tElemento elem);
void concatenarLista (TLista *l1, TLista l2);
int igualLista (TLista l1, TLista l2);
void asignarLista (TLista original, TLista *copia);
void destruirLista(TLista *l);
void mostrarLista(TLista l);

#endif //LISTAESTATICA_H
