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
int busquedaBinaria(int *array, int size, int num) {
    int inicio = 0;
    int fin = size - 1;
    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        if (array[medio] == num) {
            return medio;
        } else if (array[medio] < num) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1;
}

void ordenacionDirecta(int *array, int size)
{
for (int i = 0; i < size - 1; i++)
{
    for (int j = 0; j < size - i - 1; j++)
    {
        if (array[j] > array[j + 1])
        {
            int temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
        }
    }

}
}

// Función para generar un array aleatorio de tamaño 'tam'
void generarArray(int *array, int tam) {
    for (int i = 0; i < tam; i++) {
        array[i] = rand() % 10000; // Valores entre 0 y 9999
    }
}
int main() {

    //APARTADO C
    int N = 10;

    int *arrayc = (int *)malloc(N * sizeof(int));
    if (arrayc == NULL) {
        printf("Error al asignar memoria.\n");

        return 1;
    }
        generarArray(arrayc, N);
    //Original
    printf("Arreglo original:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arrayc[i]);
    }
    printf("\n");

    struct timespec inicioc, finc;
    clock_gettime(CLOCK_MONOTONIC, &inicioc);
    ordenacionDirecta(arrayc, N);
    clock_gettime(CLOCK_MONOTONIC,&finc);
    // Calcular y mostrar el tiempo de ejecución
    double tiempoc = (finc.tv_sec - inicioc.tv_sec) + (finc.tv_nsec - inicioc.tv_nsec) / 1E9;
    printf("Tiempo de ejecución: %.9f segundos\n", tiempoc);
    // Mostrar el arreglo ordenado
    printf("Arreglo ordenado:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arrayc[i]);
    }
    printf("\n");

    int interaciones = 0;
    // Contar las iteraciones del bucle
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            interaciones++; // Incrementar la variable de iteraciones
        }
    }

    printf("Número de iteraciones del bucle: %d\n", interaciones);

    free(arrayc);
    return 0;

    //APARTADO B
    int arrayb[] = {1, 2, 3, 4 ,5, 7 , 9  };
    int sizeb = sizeof(arrayb) / sizeof(arrayb[0]);
    int numb = 0;
    int resultadob = busquedaBinaria(arrayb, sizeb, numb);
    if (resultadob != -1) {
        printf("El número %d se encontró en la posición %d del Array.\n", numb, resultadob);
    } else {
        printf("El número %d no se encontró en el Array.\n", numb);
    }
    return 0;

    /*
    int array[] = {1, 5, 3, 8, 1};
    int size = sizeof(array) / sizeof(array[0]);
    int num = 3;
    int resultado = busquedaSecuencial(array, size, num);
    printf("El resultado es: %d\n", resultado);
    return 0;
    */

    //APARTADO A
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