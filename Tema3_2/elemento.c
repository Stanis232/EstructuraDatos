//
// Created by e.sacristan.2024 on 05/03/2025.
//

#include "elemento.h"
#include "Elemento.h"
int IgualElemento(TElemento e1 , TElemento e2) {
    return e1==e2;
}

void asignarElemento(TElemento *e1 , TElemento e) {
    *e1 = e;
}