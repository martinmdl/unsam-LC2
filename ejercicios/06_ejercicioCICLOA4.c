#include <stdio.h>

int main()
{
    // SUBE
    for (int i = 1; i < 6; i++) {

        for (int j = 1; j < i; j++) {

            printf(" %d ", j);
        }

        printf("\n");
    }

    // BAJA
    for (int y = 4; y > 0; y--) {

        for (int x = 1; x < y; x++) {

            printf(" %d ", x);
        }

        printf("\n");
    }

    return 0;
}
