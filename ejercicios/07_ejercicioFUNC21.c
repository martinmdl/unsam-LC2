/* 21. Construir una función que permita procesar un número desconocido de datos de productos vendidos, e ingresar por cada
uno:
1. identificación del producto (número entero > 0 y menor a 1000), y por cada producto ingresado:
2. precio de costo, ej: 5.30
3. precio de venta, ej: 9.50
4. cantidad vendida, ej: 25
El ciclo finaliza con identificación del producto 0 (cero).
o Calcular y emitir:
a) por cada producto, cuánto dinero le deja de ganancia la venta del mismo. Ej: 9.5 – 5.3 * 25 = 105;
b) La función main debe emitir el total de productos procesados (no la cantidad vendida) y las ganancias
que se obtuvieron por esas ventas. Ej: se procesaron 43 productos, las ganancias obtenidas fueron $2398. */

#include <stdio.h>

void validarID(int*);
float nuevoProducto();

int main()
{

    int id = 1, cont = 0;
    float acum = 0;

    printf("(ID: 0 = fin)");


    while (id != 0) {

        printf("\nID producto: ");
        scanf("%d", &id);
        fflush(stdin);

        validarID(&id);

        if (id == 0)
            break;

        acum += nuevoProducto();
        cont++;
    }

    printf("\n\nSe procesaron %d productos.\nLas ganancias fueron $%.2f", cont, acum);

    getchar();
    return 0;
}

void validarID(int *id) {

    while (*id < 0 || *id > 1000) {

        printf("\nID entre 0 y 1000: ");
        scanf("%d", id);
        fflush(stdin);
    }
}

float nuevoProducto() {

    int cant;
    float pcos, pven, ganancia;

    printf("\nPrecio de costo: $");
    scanf("%f", &pcos);
    printf("\nPrecio de venta: $");
    scanf("%f", &pven);
    printf("\nCantidad vendida: ");
    scanf("%d", &cant);
    fflush(stdin);

    ganancia = (pven - pcos) * cant;

    return ganancia;
}