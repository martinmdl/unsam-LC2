#include <stdio.h>
#include <math.h>

int main()
{
    float r, a, pi = acos(-1);

    printf("Ingrese el valor del radio (R): ");
    scanf("%f", &r);

    a = pi * pow(r, 2); // pow(numero, potencia)

    printf("Area (A) = %f", a);

    getchar();
    return 0;
}