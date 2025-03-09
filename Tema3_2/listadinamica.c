//
// Created by e.sacristan.2024 on 05/03/2025.
//

#include "listadinamica.h"
#include "elemento.h"
void crearListaVacia(TLista *l){
    l -> primOcupada = -1;
    l -> prinLibre = 0;
    for(int i = 0 ; i<DIM-1 ; i++){
        l->almacen[i].sig = i+1;
    }
    l->almacen[DIM-1].sig = -1;
}


void construir(TLista *l , TElemento elem) {
    if(l->primLibre!=-1) {
        int aux = l->primLibre;
        l->primLibre = l->almacen[l->primLibre].sig;
        asignarElemento(&l->almacen[aux].info , elem);
        l->almacen[aux].sig = l->primOcupada;
        l->primOcupada = aux;
    }
}