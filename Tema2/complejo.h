//
// Created by s.yaruchyk.2023 on 10/02/2025.
//

#ifndef COMPLEJO_H
#define COMPLEJO_H

typedef struct {
    float real;
    float imag;
}t_complejo;

void crearComplejo(float a, float b, t_complejo *c);
float getReal(t_complejo c);
float getImaginaria(t_complejo c);
void escribirComplejo(t_complejo c);
#endif //COMPLEJO_H
