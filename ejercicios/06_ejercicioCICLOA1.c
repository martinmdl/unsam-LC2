#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, w = 0, n;

    while (w != -1) {

        printf("Ingrese N: ");
        scanf("%d", &n);

        printf("%d.\t| ", n);

        for (i = 0; i < n; i++)
            printf("*");

        printf("\n\nIngrese -1 para finalizar: ");
        scanf("%d", &w);
    }

    system("pause");
    return 0;
}