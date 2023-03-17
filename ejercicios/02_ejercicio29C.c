#include <stdio.h>
#include <math.h>

int main()
{

    float r, h, area, vol, pi = acos(-1);

    printf("Ingrese radio del cilindro: ");
    scanf("%f", &r);

    printf("Ingrese altura del cilindro: ");
    scanf("%f", &h);

    area = pi * pow(r, 2);

    vol = area * h;

    printf("Area de una cara del cilindro = %.2f u%c\n", area, 253);
    printf("Volumen del cilindro = %.2f u%c\n", vol, 252);

    getchar();
    return 0;
}