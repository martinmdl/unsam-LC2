#include <stdio.h>
#include <math.h>

int main()
{
    float lado1, lado2, lado3, semiP, area;

    printf("Ingrese valor del Lado 1: ");
    scanf("%f", &lado1);

    printf("Ingrese valor del Lado 2: ");
    scanf("%f", &lado2);

    printf("Ingrese valor del Lado 3: ");
    scanf("%f", &lado3);

    fflush(stdin);

    semiP = (lado1 + lado2 + lado3) / 2;

    area = sqrt(semiP * (semiP - lado1) * (semiP - lado2) * (semiP - lado3));

    printf("AREA = %.2f u%c", area, 253);

    getchar();
    return 0;
}