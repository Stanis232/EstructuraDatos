// Created by Stanis on 24/2/25.
//
#include "ListaEstatica.h"


/*
void asignarElemento(tElemento *dest, tElemento src) {
    *dest = src;  // Si tElemento es un tipo básico como int o float
}
*/

void crearListaVacia(TLista *l) {
    l->posOcupada = -1;
}

int esListaLlena(TLista l) {
    return l.posOcupada == DIM - 1;
}

int esListaVacia(TLista l) {
    return l.posOcupada == -1;
}

void construir(TLista *l, tElemento elem) {
    if (!esListaLlena(*l)) {
        l->posOcupada++;
        asignarElemento(&l->almacen[l->posOcupada], elem);
    }
}

void restoListaL(TLista *res, TLista l) {
    if (!esListaVacia(l)) {  // Falta cerrar paréntesis corregido
        crearListaVacia(res);
        for (int i = 0; i < l.posOcupada; i++) {
            asignarElemento(&res->almacen[i], l.almacen[i]);
        }
        res->posOcupada = l.posOcupada - 1; // Se corrige la asignación
    }
}

void obtenerPrimeraLista(TLista l, tElemento *elem) {
    if (!esListaVacia(l)) {
        asignarElemento(elem, l.almacen[l.posOcupada]); // Se accede al primer elemento, no al último
    }
}
void desplazarIzquierda(TLista *l, int pos) {
    for (int i = pos; i < l->posOcupada; i++) {
        asignarElemento(&(l->almacen[i]), l->almacen[i + 1]);
}
}
void eliminarElementoLista(TLista *l, tElemento elem){
  int i=0;
  if (!esListaVacia(*l)) {
      while (!IgualElemento(elem, l->almacen[i] && (i < l->posOcupada))) {
          i++;
  }
  desplazarIzquierda(l,i);
  l->posOcupada--;
}
}