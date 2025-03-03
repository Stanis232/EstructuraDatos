// Created by Stanis on 24/2/25.
//
#include "ListaEnlazada.h"
#include "stdlib.h"

void eliminarElementoLista(Tlista *l, tElemento elem){
    TNodo *act = *l;
    TNodo *anterior = NULL;
    int encontrado = 0;
    while(encontrado == 0 && act != NULL){
      encontrado = IgualElemento(elem, act->info);
      if (encontrado) {
         if (act == NULL) {
           *l = act->sig;
         } else {
           anterior->sig = act->sig;
         }
         free(act);
      } else {
          anterior = act;
          act = act->sig;
      }
  }
}


void insertarListaFinal(Tlista *l, tElemento elem){
  if (!esListaVacia(*l)) {
    construir(l, elem);
  }else{
    TNodo *aux =*l;
    while(aux->sig != NULL){
      aux = aux->sig;
    }
    TNodo *nuevo = (TNodo *) malloc(sizeof(TNodo));
    asignarElemento(&nuevo->info, elem);
    nuevo->sig = NULL;
    aux->sig = nuevo;
  }
}