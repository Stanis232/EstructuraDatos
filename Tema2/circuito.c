//
// Created by s.yaruchyk.2023 on 10/02/2025.
//

#include "circuito.h"
#define PI 3.1416
float frecuenciaAngular(float v) {
    return 2*PI*v;

}
t_complejo impedanciaL(float w, float l) {
    t_complejo imp;
    crearComplejo(0.0,w*l, &imp);
    return imp;
}
t_complejo impedanciaR(float R) {
    t_complejo imp;
    crearComplejo(R, 0.0, &imp);
    return imp;
}

t_complejo impedanciaC(float w, float C) {
    t_complejo imp;
    float omega = w * C;
    crearComplejo(0.0, -1.0/omega, &imp);
    return imp;
}

t_complejo leyOhm(t_complejo Z, float I) {
    t_complejo imp;
    crearComplejo(I * Z.real, I * Z.imag, &imp);
    return imp;
}
t_complejo impedanciaTotal(t_complejo ZR, t_complejo ZL, t_complejo ZC) {
    t_complejo Ztotal;
    crearComplejo(ZR.real + ZL.real + ZC.real, ZR.imag + ZL.imag + ZC.imag, &Ztotal);
    return Ztotal;
}
t_complejo caidaPotencial(t_complejo I, t_complejo Z) {
    t_complejo V;
    crearComplejo(
        I.real * Z.real - I.imag * Z.imag, // Parte real
        I.real * Z.imag + I.imag * Z.real, // Parte imaginaria
        &V
    );
    return V;
}
t_complejo intensidad(t_complejo V, t_complejo Z) {
    t_complejo I;
    float divisor = Z.real * Z.real + Z.imag * Z.imag;
    crearComplejo(
        (V.real * Z.real + V.imag * Z.imag) / divisor,
        (V.imag * Z.real - V.real * Z.imag) / divisor,
        &I
    );
    return I;
}



