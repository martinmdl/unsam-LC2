#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define DIM_NOMBRE 40

typedef struct empleado {
    char nombre[DIM_NOMBRE];
    char sexo;
    int horas;
    float sueldo;
} empleado;

int menu(int opcion);
void cargaEmpleado(empleado*, int, float*, float*, float*, float*);
void procesarEmpleado(int*, int*, float*, float*, empleado*, int, int);
void emitirEmpleado(empleado*, int);

int main() {
    
    const int dim = 4;
    int opcion;
    empleado empleados[dim];

    float acumM = 0, acumF = 0, promM = 0, promF = 0;

    do {
        opcion = menu(opcion);

        switch(opcion) {
            case 1:
                cargaEmpleado(empleados, dim, &acumM, &acumF, &promM, &promF);
                break;
            case 2:
                printf("Total pagos hombres: %.2f\n", acumM);
                printf("Total pagos mujeres: %.2f\n", acumF);
                getchar();
                break;
            case 3:
                printf("Promedio pagos hombres: %.2f\n", promM);
                printf("Promedio pagos mujeres: %.2f\n", promF);
                getchar();
                break;
            case 4:
                
                break;
            case 5:
                exit(1);
        }
        system("cls");
    } while (opcion != 0);

    getchar();
    return 0;
}

int menu(int opcion) {

    printf("\nMAIN EMPLOYEE");
    printf("\n1) Cargar empleados");
    printf("\n2) Total pagos por sexo");
    printf("\n3) Promedio sueldos por sexo");
    printf("\n4) Buscar por nombre");
    printf("\n5) Salir\n");

    scanf("%d", &opcion);
    fflush(stdin);
    system("cls");

    while (opcion < 1 || opcion > 5) {
        printf("\nELIJA OPCION CORRECTA");
        printf("\n1) Cargar empleados");
        printf("\n2) Total pagos por sexo");
        printf("\n3) Promedio sueldos por sexo");
        printf("\n4) Buscar por nombre");
        printf("\n5) Salir\n");

        scanf("%d", &opcion);
        fflush(stdin);
        system("cls");
    }

    return opcion;
}

void cargaEmpleado(empleado empleados[], int dim, float *acumM, float *acumF, float *promM, float *promF) {

    int contM = 0, contF = 0;

    for (int i = 0; i < dim; i++) {

        printf("\nEMPLOYEE %d: ", (i+1));

        // CARGA NOMBRE
        do {
            printf("\n\tIngrese nombre completo: ");
            gets(empleados[i].nombre);
            fflush(stdin);
        } while (strlen(empleados[i].nombre) >= DIM_NOMBRE);
        for (int j = 0; j <= strlen(empleados[i].nombre); j++)
            empleados[i].nombre[j] = toupper(empleados[i].nombre[j]);

        // CARGA SEXO
        do {
            printf("\tIngrese sexo (M/F): ");
            scanf("%c", &empleados[i].sexo);
            fflush(stdin);
            empleados[i].sexo = tolower(empleados[i].sexo);
        } while (empleados[i].sexo != 'm' && empleados[i].sexo != 'f');

        // CARGA HORAS
        do {
            printf("\tIngrese horas trabajadas: ");
            scanf("%d", &empleados[i].horas);
            fflush(stdin);
        } while (empleados[i].horas < 1 || empleados[i].horas > 51);

        // CARGA SUELDO/H
        do {
            printf("\tIngrese sueldo por hora: ");
            scanf("%f", &empleados[i].sueldo);
            fflush(stdin);
        } while (empleados[i].sueldo <= 250.5);

        system("cls");

        procesarEmpleado(&contM, &contF, acumM, acumF, empleados, dim, i);
    }

    // SUELDO PROMEDIO H y M
    (*promM) = (*acumM) / contM;
    (*promF) = (*acumF) / contF;

    emitirEmpleado(empleados, dim);
}

void emitirEmpleado(empleado empleados[], int dim) {

    for (int i = 0; i < dim; i++)
        printf("\nNombre: %s\nSueldo/h: %.2f\n", &empleados[i].nombre, empleados[i].sueldo);

    getchar();
}

void procesarEmpleado(int *contM, int *contF, float *acumM, float *acumF, empleado empleados[], int dim, int i) {

    switch(empleados[i].sexo) {
        case 'm':
            (*contM)++;
            (*acumM) += (empleados[i].horas) * (empleados[i].sueldo);
            break;
        case 'f':
            (*contF)++;
            (*acumF) += (empleados[i].horas) * (empleados[i].sueldo);
            break; 
    }    
}

