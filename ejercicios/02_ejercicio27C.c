#include <stdio.h>

int main()
{
    float cel, far;

    printf("Ingrese grados Celsius: ");
    scanf("%f", &cel);

    far = cel * 9 / 5 + 32;

    printf("%.2f%c Celsius = %.2f%c Fahrenheit", cel, 248, far, 248);

    getchar();
    return 0;
}