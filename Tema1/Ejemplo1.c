#include <stdio.h>
#include <time.h>
int main() {
    long long n = 100000000; // Aquí metes el valor que quieres probar
    int a = 0;
    clock_t t0 = clock();
    for (long long i = 0; i < n; ++i) {
        a++;
    }
    clock_t t1 = clock();
    double tiempo = (double) (t1-t0)/CLOCKS_PER_SEC;
    printf("Ha tardado %f segundos. \n"
    , tiempo);
    return 0;
}