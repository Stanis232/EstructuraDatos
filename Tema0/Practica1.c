#include <stdio.h>
#include <stdlib.h>

void subprogramaArray(int num)
{
    if (num <= 0)
    {
        printf("Stack: limite alcanzado\n");
        return;
    }

    printf("Stack: Llamada recursiva %d\n", num);
    subprogramaArray(num - 1);
}

void subprogramaPuntero(int* ptr, int num1)
{
    if (num1 <= 0)
    {
        printf("Heap: limite alcanzado\n");
        return;
    }

    ptr = (int *)malloc(100000 * sizeof(int));
    if (ptr == NULL)
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

    printf("Se inicia prueba en Stack\n");
    subprogramaArray(num1);

    printf("Se inicia prueba en heap\n");
    int *ptr = NULL;
    subprogramaPuntero(ptr, num1);

    return 0;
}
