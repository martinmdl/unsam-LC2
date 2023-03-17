/* Muestre los N primeros números de la secuencia de Fibonacci, siendo n un dato entero */

#include <stdio.h>

int main()
{
    int i, n, anterior = 0, siguiente = 1, resultado;

    printf("Ingrese N: ");
    scanf("%d", &n);
    
    if (n != 0) {

        printf("%d\n%d", anterior, siguiente);

        for (i = 0; i <= n; i++) {

            resultado = anterior + siguiente;

            printf("\n%d", resultado);

            anterior = siguiente;
            siguiente = resultado;
        }
    }

    getchar();
    return 0;
}