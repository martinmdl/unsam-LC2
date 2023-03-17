/* Dados dos números enteros muestre su MCD y su MCM
Ej
a = 25
b = 20
MCM = 5
MCD = 100

MCD * MCM = a * b.  */

#include <stdio.h>

int main()
{
    int a, b, mcd, mcm, aux, mayor, menor, resto = 1;

    printf("Ingrese A: ");
    scanf("%d", &a);
    printf("Ingrese B: ");
    scanf("%d", &b);
    fflush(stdin);
    
    mayor = (a > b) ? a : b;
    menor = (a < b) ? a : b;

    while (resto != 0) {
        resto = mayor % menor;
        mayor = menor;
        mcd = menor;
        menor = resto;
    }

    mcm = (a * b) / mcd;

    printf("\nMCM = %d", mcm);
    printf("\nMCD = %d", mcd);

    getchar();
    return 0;
}


