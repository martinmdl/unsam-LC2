#include <stdio.h>

int main()
{
    int num, dig1, dig2, dig3, dig4, dig5;

    printf("Ingrese un numero de hasta 5 cifras: ");
    scanf("%d", &num);
    
    dig1 = (num / 10000) % 10;
    dig2 = (num / 1000) % 10;
    dig3 = (num / 100) % 10;
    dig4 = (num / 10) % 10;
    dig5 = (num / 1) % 10;

    if (dig1 == dig5 && dig4 == dig2)
        printf("El numero es capicua");
    else
        printf("El numero no es capicua");

    return 0;
}