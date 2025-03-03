//
// Created by Stanis on 24/2/25.
//
#define DIM 10
#include "Elemento.h"
#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

typedef struct {
    tElemento info;
    struct Nodo *sig;

    int posOcupada;
}TNodo;
typedef TNodo *Tlista;
void asignarElemento(tElemento *dest, tElemento src);

// Constructoras generadoras
void crearListaVacia(Tlista *l);
void construir(Tlista *l, tElemento elem);
// Observadoras selectoras
void obtenerPrimeroLista(Tlista l, tElemento* elem);
void restoListaL (Tlista *res, Tlista l);
void ultimoLista(tElemento *e, Tlista l);
// Observadoras no selectoras
int esListaVacia(Tlista l);
int longitudLista (Tlista l);
int perteneceLista (tElemento e, Tlista l);
// Constructoras no generadoras
void insertarListaFinal(Tlista *l, tElemento elem);
void eliminarElementoLista(Tlista *l, tElemento elem);
void concatenarLista (Tlista *l1, Tlista l2);
int igualLista (Tlista l1, Tlista l2);
void asignarLista (Tlista original, Tlista *copia);
void destruirLista(Tlista *l);
void mostrarLista(Tlista l);

#endif //LISTAESTATICA_H
