/* Dado un entero positivo, muéstrelo con las cifras en orden opuesto. Ej. Entra 7258. Sale 8527 */

#include <stdio.h>

int main()
{
    int num, result = 0;

    printf("Ingrese un entero: ");
    scanf("%d", &num);

    while (num > 0) {
        result *= 10;
        result += num % 10;
        num /= 10;
    }

    printf("Numero invertido: %d", result);

    getchar();
    return 0;
}