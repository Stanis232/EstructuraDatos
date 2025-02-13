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
void mezcla(int* array, int izq, int medio, int der)
{
    int i, j,k;
   int n1 = medio - izq + 1;
    int n2 = der -medio;

    int *I = (int *)malloc(n1 *sizeof(int));
    int *D = (int * )malloc(n2 *sizeof(int));


    // Copiar datos a los subarrays temporales
    for (i = 0; i < n1; i++)
        I[i] = array[izq + i];
    for (j = 0; j < n2; j++)
        D[j] = array[medio + 1 + j];

    // Fusionar los subarrays ordenados
    i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        if (I[i] <= D[j]) {
            array[k] = I[i];
            i++;
        } else {
            array[k] = D[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L y R si los hay
    while (i < n1) {
        array[k] =I[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = D[j];
        j++;
        k++;
    }

    free(I);
    free(D);
}



void ordenacionMezcla(int *array, int izq, int der) {
    if (izq<der)
    {
        int medio = izq + (der - izq) / 2;
        ordenacionMezcla(array, izq, medio);
        ordenacionMezcla(array,medio + 1, der);

        mezcla(array, izq, medio, der);
    }
}

int main() {
    //Apartado D
    int ND = 10;
    int *arrayD = (int *)malloc(ND * sizeof(int));
    if (arrayD == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    generarArray(arrayD, ND);
    struct timespec iniciod, find;
    clock_gettime(CLOCK_MONOTONIC, &iniciod);
    // Mostrar el array original (opcional, descomentar si es necesario)

    printf("Arreglo original:\n");
    for (int i = 0; i < ND; i++) {
        printf("%d ", arrayD[i]);
    }
    printf("\n");

    ordenacionMezcla(arrayD, 0, ND - 1);

    clock_gettime(CLOCK_MONOTONIC, &find);
    double tiempod = (find.tv_sec - iniciod.tv_sec) + (find.tv_nsec - iniciod.tv_nsec) / 1E9;

    printf("Tiempo de ejecución (mezcla): %.9f segundos\n", tiempod);
    // Mostrar el array ordenado (opcional, descomentar si es necesario)

    printf("Arreglo ordenado:\n");
    for (int i = 0; i < ND; i++) {
        printf("%d ", arrayD[i]);
    }
    printf("\n");

    free(arrayD);
    return 0;



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