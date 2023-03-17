/* 16. Escribe una función:
void maxmin (int x1, int x2, int * max, int * min);
 que reciba como parámetros de entrada dos números enteros x1 y x2 y devuelva a través de los parámetros de 
salida max y min el máximo y el mínimo, respectivamente, de ambos números.
 Modifica la función anterior para que calcule también el valor medio de ambos números. El nuevo prototipo de la
función será ahora el siguiente: void maxmin (int x1, int x2, int * max, int * min, int * media); */

#include <stdio.h>

void maxmin (int x1, int x2, int * max, int * min) {

// *max = valor
// *min = valor
//  max = direc
//  min = direc

    if (x1 < x2) {
        *max = x2;
        *min = x1;
    } else {
        *max = x1;
        *min = x2;
    }
}

int main() {

    int n1, n2, max, min;

    printf("Ingrese dos n%cmeros: ", 163);
    scanf("%d %d", &n1, &n2);

    maxmin(n1, n2, &max, &min);

    printf("\nEl mayor es: %d\nEl menor es: %d", max, min);

    getchar();
    return 0;
}