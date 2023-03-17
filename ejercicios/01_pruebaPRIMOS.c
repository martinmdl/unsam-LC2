#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int i, raiz, n, esPrimo, contadorPrimos = 0;

    printf("\n(FIN: N = 0)\nIngrese N:\n");
    scanf("%d", &n);

    while (n > 0)
    {
        esPrimo = 1;
        i = 2;

        raiz = (int)sqrt(n);

        while ((esPrimo == 1) && (i <= raiz))
        {
            if (n % i == 0)
                esPrimo = 0;
            else
                i++;
        }

        if (esPrimo == 1) {
            printf("\nEs primo\n", 163, n);
            contadorPrimos++;
        }
        else
            printf("\nNo es primo\n");

        printf("\n(FIN: N = 0)\nIngrese N:\n");
        scanf("%d", &n);
    }

    printf("\nEl total de n%cmeros primos ingresados es: %d\n", 163, contadorPrimos);
    printf("\n");

    system("pause");
    return 0;
}
