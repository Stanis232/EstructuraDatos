//
// Created by Stanis on 24/2/25.
//
#include "ListaEstatica.h"

#include "Elemento.h"
#include "Elemento.h"
int IgualElemento(tElemento e1, tElemento e2) {
    return e1==e2;
}
void asignarElemento(tElemento *dest, tElemento src) {
    *dest = src; // Si tElemento es un tipo simple, como int o float
}
