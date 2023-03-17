#include <stdio.h>
#include <ctype.h>

// PROTOTIPOS DE FUNCIONES
void funcionGrupos(int*, int*, float*, char*, float*);
void funcionAux(int*, int*, int*, float*, float*, float*);

int main() {

    // PARAMETROS DE "funcionGrupos()"
    int totalClientes = 0, contGrupos = 0;
    float MayorFacturacion = 0, totalFacturado = 0;
    char claseFacturacion;

    funcionGrupos(&totalClientes, &contGrupos, &MayorFacturacion, &claseFacturacion, &totalFacturado);

    // PUNTO 3
        // PUNTO A
    printf("\n\n\n++ RESULTADOS ++\n");
    printf("\nTotal de grupos: %d", contGrupos);
    printf("\nTotal de clientes: %d", totalClientes);

        // PUNTO B
    printf("\nLa clase %c tuvo la mayor facturaci%cn ($%.2f)", claseFacturacion, 162, MayorFacturacion);

        // PUNTO C
    printf("\nEl total facturado fue: $%.2f", totalFacturado);

    getchar();
    return 0;
}

// PUNTO 1
// OUTPUT: facturacion y cantidad de clientes por clase parciales (POR GRUPO)
void funcionGrupos(int *totalClientes, int *contGrupos, float *MayorFacturacion, char *claseFacturacion, float *totalFacturado) {

    // VARIABLES LOCALES
        // PARAMETROS DE "funcionAux()"
    int contX, contY, contZ;
    float acumImporteX, acumImporteY, acumImporteZ;
        // EXCLUSIVAS DE "funcionGrupos()"
    int condicion1, condicion2;
    float acumTotalX = 0, acumTotalY = 0, acumTotalZ = 0;

    // 1 ITERACION POR GRUPO
    do {
        
        // SI HAY GRUPO NUEVO, ENTONCES RESETEO PARA QUE LOS CONTADORES Y ACUMULADORES SEAN PARCIALES
        acumImporteX = 0;
        acumImporteY = 0;
        acumImporteZ = 0;
        contX = 0;
        contY = 0;
        contZ = 0;

        // 1 ITERACION POR CLIENTE
        do {
            
            // MODIFICO CONTADORES Y ACUMULADORES                
            funcionAux(&contX, &contY, &contZ, &acumImporteX, &acumImporteY, &acumImporteZ);

            // FINALIZACION WHILE
            printf("\n\t1 - nuevo cliente\n\t0 - finalizar\n\tOpci%cn: ", 162);
            scanf("%d", &condicion2);
            fflush(stdin);

        } while (condicion2 != 0);

        // INCREMENTO NUMERO DE GRUPO
        (*contGrupos)++;
        
        // MUESTRO CONTADORES Y ACUMULADORES (IMPORTE Y CANTIDAD PARCIAL) DEL WHILE ANTERIOR ANTES DE RESETEAR
        printf("\nGrupo %d - Facturaci%cn:\nX: %.2f, %d clientes\nY: %.2f, %d clientes\nZ: %.2f, %d clientes\n", *contGrupos, 162, acumImporteX, contX, acumImporteY, contY, acumImporteZ, contZ);

        // ACUMULO IMPORTE POR CLASE ANTES DE RESETEAR
        acumTotalX += acumImporteX;
        acumTotalY += acumImporteY;
        acumTotalZ += acumImporteZ;

        // CUENTO CLIENTES TOTALES ANTES DE RESETEAR
        *totalClientes += contX + contY + contZ;
        
        // FINALIZACION WHILE
        printf("\n1 - nuevo grupo\n0 - finalizar\nOpci%cn: ", 162);
        scanf("%d", &condicion1);
        fflush(stdin);

    } while (condicion1 != 0);
    
    // COMPARO IMPORTES TOTALES POR CLASE, ME QUEDO CON EL MAYOR
    if (acumTotalX > acumTotalY && acumTotalX > acumTotalZ) {
        *MayorFacturacion = acumTotalX;
        *claseFacturacion = 'X';

    } else if (acumTotalY > acumTotalX && acumTotalY > acumTotalZ) {
        *MayorFacturacion = acumTotalY;
        *claseFacturacion = 'Y';
    } else {
        *MayorFacturacion = acumTotalZ;
        *claseFacturacion = 'Z';
    }

    // SUMO FACTURACIONES DE CLASES
    *totalFacturado = acumTotalX + acumTotalY + acumTotalZ;
}

// PUNTO 2
// INPUT: clase, importe
// OUTPUT: importe acumulado por clase, cantidad de clientes por clase
void funcionAux(int *contX, int *contY, int *contZ, float *acumImporteX, float *acumImporteY, float *acumImporteZ) {
    
    // VARIABLES LOCALES
        // EXCLUSIVAS DE "funcionAux()"
    char clase = '-';
    float importe = 0;

    // PIDO CLASE E IMPORTE
    printf("\n\t\t> NUEVO CLIENTE\n");
    printf("\t\t  Clase (X, Y, Z) = ");
    scanf("%c", &clase);
    printf("\t\t  Importe = $");
    scanf("%f", &importe);
    fflush(stdin);

    clase = tolower(clase);

    // ACUMULO IMPORTE Y CUENTO CLIENTES POR CLASE
    switch (clase) {
        
        // SI CLASE = X
        case 'x':
            *acumImporteX += importe;
            (*contX)++;
            break;

        // SI CLASE = Y
        case 'y':
            *acumImporteY += importe;
            (*contY)++;
            break;

        // SI CLASE = Z
        case 'z':
            *acumImporteZ += importe;
            (*contZ)++;
            break;
    }    
}