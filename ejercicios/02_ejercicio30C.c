#include <stdio.h>
#include <math.h>

int main()
{
    float r, x, a, pi = acos(-1);

    printf("Ingrese el radio: ");
    scanf("%f", &r);

    printf("Ingrese la distancia del centro al segmento: ");
    scanf("%f", &x);

    a = (pi * pow(r, 2)) / 2 - (x * sqrt(pow(r, 2) - pow(x, 2)) + pow(r, 2) * asin(x / r));

    printf("%crea del segmento de c%crculo = %.2f u%c", 181, 161, a, 253);

    getchar();
    return 0;
}