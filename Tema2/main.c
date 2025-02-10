#include "complejo.h"



/*int main(void) {
    t_complejo comp;
    crearComplejo(0.9, 2, &comp);
    return 0;
}*/
#include <stdio.h>
#include "circuito.h"

int main() {
    float V0 = 220;      // Voltaje de la fuente en V
    float R = 5000;      // 5 kΩ
    float L = 0.003;     // 3 mH
    float C = 1.2e-6;    // 1.2 µF
    float v = 50;        // 50 Hz

    float w = frecuenciaAngular(v);

    t_complejo ZR = impedanciaR(R);
    t_complejo ZL = impedanciaL(w, L);
    t_complejo ZC = impedanciaC(w, C);
    t_complejo Ztotal = impedanciaTotal(ZR, ZL, ZC);

    t_complejo Vfuente;
    crearComplejo(V0, 0.0, &Vfuente);

    t_complejo I = intensidad(Vfuente, Ztotal);

    t_complejo VR = caidaPotencial(I, ZR);
    t_complejo VL = caidaPotencial(I, ZL);
    t_complejo VC = caidaPotencial(I, ZC);

    printf("Impedancia Total: %.2f + %.2fi\n", Ztotal.real, Ztotal.imag);
    printf("Intensidad: %.2f + %.2fi\n", I.real, I.imag);
    printf("Caída de Potencial en R: %.2f + %.2fi\n", VR.real, VR.imag);
    printf("Caída de Potencial en L: %.2f + %.2fi\n", VL.real, VL.imag);
    printf("Caída de Potencial en C: %.2f + %.2fi\n", VC.real, VC.imag);

    return 0;
}
