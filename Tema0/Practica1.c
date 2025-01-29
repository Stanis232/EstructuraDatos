#include <stdio.h>
#include <stdlib.h>


void subprogramaArray(int num)
{
    if (num<=0)
    {
        printf("Stack:limite alcanzado");
        return;


    }
    int array[10000];
    printf("Stack: Llamada recursiva %d\n", num);

    subprogramaArray(num-1);


    /*if (num <= 0) {
        printf("Límite alcanzado\n");
        return;
    }

    int *array = (int *)malloc(100000 * sizeof(int)); // Ilimitado cosa que antes se limitaba solo a 8Megas
    if (array == NULL) {
        printf("No se pudo asignar memoria\n");
        return;
    }

    printf("Llamada recursiva %d\n", num);

    subprogramaArray(num - 1);

    free(array); // Libera memoria del heap*/
}

void subprogramaPuntero(int* ptr, int num1)
{
    if (num1<=0)
    {
        printf("Heap: limite alcanzado");
        return;


    }
    ptr = (int *)malloc(100000 * sizeof(int));
    if (ptr==NULL)
    {
        printf("Heap: Memoria agotada en la llamada %d\n", num1);
        return;
    }

    printf("Heap: Llamada %d\n", num1);
    subprogramaPuntero(ptr, num1 - 1);

    // Liberar memoria antes de salir
    free(ptr);


}


int main() {
    int num1;

    printf("Dime un número para Array: ");
    scanf("%d", &num1);
    printf("Se inicia prueba en Stack");
    subprogramaArray(num1);


    printf("Se inicia prueba en heap");
    int *ptr = NULL;
    subprogramaPuntero(ptr,num1);
    return 0;

}

