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
int main() {
    /*
    int array[] = {1, 5, 3, 8, 1};
    int size = sizeof(array) / sizeof(array[0]);
    int num = 3;
    int resultado = busquedaSecuencial(array, size, num);
    printf("El resultado es: %d\n", resultado);
    return 0;
    */


}