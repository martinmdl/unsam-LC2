#include <stdio.h>
#include <math.h>

int main()
{
    float cat1, cat2, hip;

    printf("Ingresar valor del Cateto 1 = ");
    scanf("%f", &cat1);
    printf("Ingresar valor del Cateto 2 = ");
    scanf("%f", &cat2);

    hip = sqrt(pow(cat1, 2) + pow(cat2, 2));

    printf("Hipotenusa = %f", hip);

    getchar();
    return 0;
}