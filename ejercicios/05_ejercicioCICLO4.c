/* Dado un entero positivo determine su equivalente en el sistema binario con el siguiente procedimiento:
divida el número para 2 sucesivamente hasta que el cociente sea 0.
Entonces, los residuos que se obtienen son los dígitos del número binario, pero en orden opuesto.
Forme el número con estos residuos mientras los obtiene y muestre su valor.
Modifique el algoritmo anterior para invertir el número obtenido y mostrar el número binario con las cifras en la posición correcta. */

#include <stdio.h>
#include <math.h>

int main()
{
    int resto, i = 0, cociente;
    unsigned long int binario = 0;

    printf("Ingrese un entero positivo: ");
    scanf("%d", &cociente);

    while (cociente > 0) {

        resto = cociente % 2;

        binario += resto * pow(10, i);

        cociente /= 2;
        i++;
    }

    printf("Binario: %d", binario);

    getchar();
    return 0;
}