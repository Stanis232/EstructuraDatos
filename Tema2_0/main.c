#include <stdio.h>
#include "Bitmap.h"
int main()
{
    int i, j;
    int ANCHO = 640;
    int ALTO = 480;
    Bitmap fractal = createBitmap("cmake-build-debug/mandelbrot.bmp", ANCHO, ALTO, 3);

    if (fractal.pixels == NULL) {
        printf("Error: No se pudo asignar memoria para la imagen.\n");
        return 1;
    }


    for(i = 0; i < ANCHO; i++) {
        for(j = 0; j < ALTO; j++) {

putPixelRGB(&fractal, i, j, i % 256, j % 256, (i * j) % 256);
        }
    }
    printf("Guardando imagen en cmake-build-debug/mandelbrot.bmp...\n");
    saveBitmap(&fractal);
    printf("Imagen guardada correctamente.\n");
    return 0;
}