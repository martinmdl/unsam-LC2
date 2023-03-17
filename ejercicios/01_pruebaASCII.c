#include <stdio.h>

int main()
{
    int a; // entero

    printf("Ingrese una letra: ");
    scanf("%c", &a); // especificador %c (char)

    printf("Valor en ASCII = %d", a); // especificador %d (entero)

    return 0;
}