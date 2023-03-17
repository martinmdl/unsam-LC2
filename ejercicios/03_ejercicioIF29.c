/* Ingrese tres números correspondientes a un conjunto y tres números correspondientes a otro conjunto. Emite por pantalla los 
números que corresponden a la intersección de los dos conjuntos. */

#include <stdio.h>

int main()
{   
    int c1[3], c2[3], c3[3], i;

    // LEO CONJUNTO 1
    printf("Ingrese C1:\n");
    scanf("%d", &c1[1]);
    scanf("%d", &c1[2]);
    scanf("%d", &c1[3]);
    fflush(stdin);

    // LEO CONJUNTO 2
    printf("Ingrese C2:\n");
    scanf("%d", &c2[1]);
    scanf("%d", &c2[2]);
    scanf("%d", &c2[3]);
    fflush(stdin);

    // GENERO CONJUNTO 3
    for (i = 1; i < 4; i++) {
        if (c1[i] == c2[i]) {
            c3[i] = c1[i];
        } else {
            c3[i] = 0;
        }
    }

    // MUESTRO CONJUNTO 3
    printf("\nIntersecci%cn:\n", 162);
    for (i = 1; i < 4; i++) {
        if (c3[i] != 0) {
            printf("Valor %d -> %d\n", i, c3[i]);
        } else {
            printf("Valor %d -> NULL\n", i);
        }
    }

    getchar();
    return 0;
}