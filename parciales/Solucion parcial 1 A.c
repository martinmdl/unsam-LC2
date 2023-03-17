#include <stdio.h>
#include <ctype.h>
#define ULTIMO 2

void procesoNotas(char*, float*, float*, float*, int*, int*);
void inputNotas(int*, float*, char*, int*);

int main() {

    // VARIABLES PARA "inputNotas()"
    char gradoMayProm = 0;
    int añoMayProm = 0, contLegajos = 0;
    float mayorPromedio = 0;

    inputNotas(&contLegajos, &mayorPromedio, &gradoMayProm, &añoMayProm);

    printf("\nTotal de legajos procesados: %d", contLegajos);
    printf("\nMayor promedio: %.2f (%d%c%c)", mayorPromedio, añoMayProm, 167, gradoMayProm);
    
    getchar();
    return 0;
}

void inputNotas(int *contLegajos, float *mayorPromedio, char *gradoMayProm, int *añoMayProm) {

    // VARIABLES PARA "procesoNotas()"
    int contNotasA, contNotasB;
    float acumNotasA, acumNotasB;

    // VARIABLES PARA ESTA FUNCION
    char division;
    int i, legajo;
    float nota, promedioA = 1, promedioB = 1;

    // 7 ITERACIONES
    for (i = 1; i <= ULTIMO; i++) {

        contNotasA = 0; contNotasB = 0; acumNotasA = 0; acumNotasB = 0;

        printf("\n%d%c Grado", i, 167);
        printf("\n\t(FIN = Legajo 0)");

        // CONDICION DE PRIMERA ENTRADA
        printf("\n\tIngrese legajo: ");
        scanf("%d", &legajo);

        while (legajo > 0) {

            fflush(stdin);
            printf("\t\tIngrese divisi%cn: ", 162);
            scanf("%c", &division);
            printf("\t\tIngrese nota: ");
            scanf("%f", &nota);
            fflush(stdin);

            division = toupper(division); // PASO "division" A MAYUSUCULA

            procesoNotas(&division, &nota, &acumNotasA, &acumNotasB, &contNotasA, &contNotasB);

            printf("\n\tIngrese legajo: ");
            scanf("%d", &legajo);
            fflush(stdin);

            (*contLegajos)++;
        }

        // PROMEDIOS AÑO "i" POR DIVISION
        promedioA = acumNotasA / contNotasA;
        promedioB = acumNotasB / contNotasB;
        printf("\nGrado %d - promedio general:\nA = %.2f\nB = %.2f\n", i, promedioA, promedioB);

        // MAYOR PROMEDIO (CON AÑO Y DIVISION)
        if (promedioA > (*mayorPromedio)) {
            (*mayorPromedio) = promedioA;
            (*gradoMayProm) = 'A';
            (*añoMayProm) = i;
            }
        if (promedioB > (*mayorPromedio)) {
            (*mayorPromedio) = promedioB;
            (*gradoMayProm) = 'B';
            (*añoMayProm) = i;
        }
    }
}

void procesoNotas(char *division, float *nota, float *acumNotasA, float *acumNotasB, int *contNotasA, int *contNotasB) {

    switch (*division) {

        case 'A':
            (*contNotasA)++;
            (*acumNotasA) += (*nota);
            break;

        case 'B':
            (*contNotasB)++;
            (*acumNotasB) += (*nota);
            break;
    }
}