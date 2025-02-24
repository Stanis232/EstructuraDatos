// Created by Stanis on 24/2/25.
//
#include "ListaEstatica.h"

void crearListaVacia(Tlista *l) {
    l->posOcupada = -1;
}

int esListaLlena(Tlista l) {
    return l.posOcupada == DIM - 1;
}

int esListaVacia(Tlista l) {
    return l.posOcupada == -1;
}

void construir(Tlista *l, tElemento elem) {
    if (!esListaLlena(*l)) {
        l->posOcupada++;
        asignarElemento(&l->almacen[l->posOcupada], elem);
    }
}

void restoListaL(Tlista *res, Tlista l) {
    if (!esListaVacia(l)) {  // Falta cerrar paréntesis corregido
        crearListaVacia(res);
        for (int i = 0; i < l.posOcupada; i++) {
            asignarElemento(&res->almacen[i], l.almacen[i]);
        }
        res->posOcupada = l.posOcupada - 1; // Se corrige la asignación
    }
}

void obtenerPrimeraLista(Tlista l, tElemento *elem) {
    if (!esListaVacia(l)) {
        asignarElemento(elem, l.almacen[0]); // Se accede al primer elemento, no al último
    }
}
int eliminarElementoLista(Tlista *l, tElemento elem){
  int i=0;
  if (!esListaVacia(*l)
{
              while(!IgualElemento(elem,l->almacen[i}&&(i<=l->posOcupada)){
    i++;
  }
  desplazarIzquierda(l,i);
  l->posOcupada;
}