#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int busquedaSecuencial(int *array, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (array[i] == num) {
            return i;
        }
    }
    return -1;
}

// Función para generar un array aleatorio de tamaño 'tam'
void generarArray(int *array, int tam) {
    for (int i = 0; i < tam; i++) {
        array[i] = rand() % 10000; // Valores entre 0 y 9999
    }
}
int main() {
    /*
    int array[] = {1, 5, 3, 8, 1};
    int size = sizeof(array) / sizeof(array[0]);
    int num = 3;
    int resultado = busquedaSecuencial(array, size, num);
    printf("El resultado es: %d\n", resultado);
    return 0;
    */
    int tam = 100000; // Tamaño del array
    int *array = (int *)malloc(tam * sizeof(int));
    if (array == NULL) {
       printf("Error no se puede asignar memoria.\n");
        return 1;
    }
    generarArray(array, tam); // Llenar el array con valores aleatorios
    int elementoBuscar = array[tam - 1]; // Tomamos el último elemento para el peor caso
    // Medir tiempo de ejecución
    struct timespec inicio, fin;
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    int resultado = busquedaSecuencial(array, tam, elementoBuscar);
    clock_gettime(CLOCK_MONOTONIC,&fin);
    //se muestra el resultado asi
    if (resultado != -1) {
        printf("Elemento %d encontrado en la posicion %d \n",elementoBuscar,resultado);

    }else
        printf("Elemento %d no encontrado en el array\n", elementoBuscar);
    // Calcular y mostrar el tiempo de ejecución
    double tiempo = (fin.tv_sec - inicio.tv_sec) + (fin.tv_nsec - inicio.tv_nsec) / 1E9;
    printf("Tiempo de ejecución: %.9f segundos\n", tiempo);

    free(array); // Liberar memoria
    return 0;

}