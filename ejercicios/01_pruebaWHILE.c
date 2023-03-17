#include <stdio.h>

int main()
{
    int i, n = 5;

    // IMPRIME "HOLA" 5 VECES
    i = 0;
    while (i++ < n) {

        printf("\nHOLA");
    }

    // IMPRIME "HOLA" 4 VECES
    i = 0;
    while (++i < n) {

        printf("\nHOLA");
    }

    return 0;
}