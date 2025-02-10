//
// Created by s.yaruchyk.2023 on 10/02/2025.
//

#ifndef CIRCUITO_H
#define CIRCUITO_H
#include "complejo.h"


t_complejo impedanciaL(float w, float l);
t_complejo impedanciaR(float R);
t_complejo impedanciaC(float w, float C);
t_complejo leyOhm(t_complejo Z, float I);
t_complejo impedanciaTotal(t_complejo ZR, t_complejo ZL, t_complejo ZC);

t_complejo intensidad(t_complejo V, t_complejo Z);

t_complejo caidaPotencial(t_complejo I, t_complejo Z);
float frecuenciaAngular(float v);
#endif //CIRCUITO_H
