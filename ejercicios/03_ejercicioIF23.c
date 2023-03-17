/* Desarrolla un algoritmo que le permita leer un valor cualquiera N y escribir si dicho número es 
común divisor de otros dos valores leídos W y Z. */

#include <stdio.h>

int main()
{
    int n, w, z;

    printf("Ingrese N: ");
    scanf("%d", &n);
    printf("Ingrese W: ");
    scanf("%d", &w);
    printf("Ingrese Z: ");
    scanf("%d", &z);
    fflush(stdin);

    if (w % n == 0 && z % n == 0) {
        printf("\"N\" es com%cn divisor de W y Z", 163);
    } else {
        printf("\"N\" no es com%cn divisor de W y Z", 163);        
    }

    getchar();
    return 0;
}