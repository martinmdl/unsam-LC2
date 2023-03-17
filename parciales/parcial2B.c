#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 4
#define M 6
#define ARRAYS 30

// ESTRUCTURAS
typedef struct sucursales {
    int idSucursal;
    char ciudad[ARRAYS];
    float descuentosMes[ARRAYS];
    float descuentosTotal;
    float descuentosPromedio;
} sucursales;

typedef struct gerentes {
    int idGerente;
    char nombre[ARRAYS];
} gerentes;

// PROTOTIPOS
void cargaSucursales(sucursales sucursal[]);
void cargaGerentes(gerentes gerente[]);
void randomDescuentosAnteriores(float descuentosAnteriores[][M]);
void proceso_descuentosTotal(sucursales sucursal[]);
void proceso_descuentosPromedio(sucursales sucursal[], float descuentosAnteriores[][M]);
int procesar_mayoresDescuentos(sucursales sucursal[], int enteros[]);
void emitir_mayoresDescuentos(sucursales sucursal[], gerentes gerente[], int enteros[], int cont);
void ordenarCiudades(sucursales sucursal[]);
void emitirResultados(sucursales sucursal[], gerentes gerente[]);

// MAIN
int main() {

    srand(time(NULL));

    sucursales sucursal[N];
    gerentes gerente[N];
    int enteros[N] = {-1, -1, -1, -1};
    float descuentosAnteriores[N][M];

    cargaSucursales(sucursal);
    cargaGerentes(gerente);
    randomDescuentosAnteriores(descuentosAnteriores);
    proceso_descuentosTotal(sucursal); // EJERCICIO 1
    proceso_descuentosPromedio(sucursal, descuentosAnteriores); // EJERCICIO 2
    int cont = procesar_mayoresDescuentos(sucursal, enteros); // EJERCICIO 3
    emitir_mayoresDescuentos(sucursal, gerente, enteros, cont); // EJERCICIO 4
    ordenarCiudades(sucursal); // EJERCICIO 5
    emitirResultados(sucursal, gerente);


    getchar();
    return 0;
}

void cargaSucursales(sucursales sucursal[]) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < N; i++) {
        printf("\n%d%c SUCURSAL\n", i+1, 167);
        printf("\tID: ");
        scanf("%d", &sucursal[i].idSucursal);
        fflush(stdin);
        printf("\tCiudad: ");
        gets(sucursal[i].ciudad);
        fflush(stdin);
        printf("\tDescuentos del mes: \n");
        for (j = 0; j < ARRAYS; j++) {
        // LLENADO MANUAL
            // printf("\t\tDescuentos #%d: ", j+1);
            // scanf("%s", &sucursal[i].descuentosMes[j]);
            // fflush(stdin);
        // LLENADO AUTOMATICO
            // descuentos posibles = {0, 5, 10, 15}
            sucursal[i].descuentosMes[j] = (rand() % 16 / 5) * 5;
        }
        system("cls");
    }
}

void cargaGerentes(gerentes gerente[]) {
    int i, j;
    for (i = 0; i < N; i++) {
        printf("\n%d%c GERENTE\n", i+1, 167);
        printf("\tID: ");
        scanf("%d", &gerente[i].idGerente);
        fflush(stdin);
        printf("\tNombre: ");
        gets(gerente[i].nombre);
        fflush(stdin);
        system("cls");
    }
}

void randomDescuentosAnteriores(float descuentosAnteriores[][M]) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            descuentosAnteriores[i][j] = ((rand() % 16 / 5) * 5) * 30; 
}

// EJERCICIO 1
void proceso_descuentosTotal(sucursales sucursal[]) {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < ARRAYS; j++)
            sucursal[i].descuentosTotal += sucursal[i].descuentosMes[j];
}

// EJERCICIO 2
void proceso_descuentosPromedio(sucursales sucursal[], float descuentosAnteriores[][M]) {
    int i, j;
    float acumProm = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++)
            acumProm += descuentosAnteriores[i][j];
        sucursal[i].descuentosPromedio = acumProm / M;
    }
}

// EJERCICIO 3
int procesar_mayoresDescuentos(sucursales sucursal[], int enteros[]) {
    int i, cont = 0;
    for (i = 0; i < N; i++) {
        if (sucursal[i].descuentosTotal > sucursal[i].descuentosPromedio) {
            enteros[cont] = i;
            cont++;
        }
    }
    return cont;
}

// EJERCICIO 4
void emitir_mayoresDescuentos(sucursales sucursal[], gerentes gerente[], int enteros[], int cont) {
    printf("\n%d sucursale/s superaron el promedio de descuentos:", cont);
    for (int i = 0; i < cont; i++)
        printf("\n\t%d. %s (Gerente: %s)", (enteros[i]+1), sucursal[enteros[i]].ciudad, gerente[enteros[i]].nombre);
}

// EJERCICIO 5
void ordenarCiudades(sucursales sucursal[]) {
    int i, j;
    sucursales aux;
    for (i = 0; i < N-1; i++)
        for (j = 0; j < N-(i+1); j++)
            if (strcmp(sucursal[j].ciudad, sucursal[j+1].ciudad) > 0) {
                aux = sucursal[j];
                sucursal[j] = sucursal[j+1];
                sucursal[j+1] = aux;
            }
}

void emitirResultados(sucursales sucursal[], gerentes gerente[]) {
    int i, j;
    printf("\n\nRESUMEN");
    for (i = 0; i < N; i++) {
        printf("\n\n\t%d%c SUCURSAL", i+1, 167);
        printf("\n\t\tID: %d", sucursal[i].idSucursal);
        printf("\n\t\tCiudad: %s", sucursal[i].ciudad);
        printf("\n\t\tGerente: %s", gerente[i].nombre);
        printf("\n\t\tDescuento total del mes: %.2f", sucursal[i].descuentosTotal);
        printf("\n\t\tDescuento promedio semestral: %.2f", sucursal[i].descuentosPromedio);
    }
}