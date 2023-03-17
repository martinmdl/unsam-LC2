#include <stdio.h>

int validacionPos(int, int, int, float*);

int main() {

    int i, j, n, pos, salida;
    float valorx;

    printf("Largo del vector: "); // PIDO DIMENSION DEL VECTOR
    scanf("%d", &n);

    float arr[n]; // DECLARO VECTOR DE DIMENSION "N"
    for (i = 0; i < n; i++)
        arr[i] = 0; // LLENO DEL VECTOR CON CEROS

    do { // 1 ITERACION = 1 VALOR NUEVO PARA EL VECTOR

        do { // 1 ITERACION = PIDO Y VALIDO: VALOR Y POSICION 

            printf("\nValor X: ");
            scanf("%f", &valorx);
            printf("Posici%cn I: ", 162);
            scanf("%d", &pos);
            fflush(stdin);

        // VALIDO <=> validacionPos = 1
        // INVAIDO <=> validacionPos = 0
        } while (validacionPos(pos-1, valorx, n, arr) != 1);

        arr[pos-1] = valorx; // ASIGNO VALOR EN LA POSICION PEDIDA

        salida = 0; // SI "salida" = 0 ENTONCES TERMINA INPUT DE VALORES
        for (i = 0; i < n; i++) 
            if (arr[i] == 0) { // SI ALGUN VALOR ES CERO...
                printf("\nFaltan llenar las posiciones");
                for (j = 0; j < n; j++) // MUESTRO POSICIONES "VACIAS"
                    if (arr[j] == 0)
                        printf(" - %d", (j+1));
                salida = 1; // "salida" = 1 ENTONCES SIGUE INPUT DE VALORES
                break; // CON 1 VALOR QUE FALTE COMPLETAR DEJA DE BUSCAR
            }

    } while (salida != 0);

    // EMITO RESULTADOS
    
    getchar();
    return 0;
}

int validacionPos(int pos, int valorx, int n, float *arr) {

    if (pos > (n - 1) || pos < 0) { // SI LA POSICION ESTA FUERA DE RANGO
        printf("\nPosici%cn fuera de rango\nVuelva a ingresar VALOR y POSICION\n", 162);
        return 0;
    }

    /* for (int i = 0; i < n; i++)
        if (i == pos) // POSICION ACTUAL? */
            if (arr[pos] != 0) { // OCUPADA?
                printf("\nPosici%cn ocupada\nVuelva a ingresar VALOR y POSICION\n", 162);
                return 0;
            } else return 1; // RETORNA 1 SI ESTA LIBRE
}