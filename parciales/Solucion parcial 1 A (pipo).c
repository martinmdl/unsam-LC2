#include <stdio.h>
#include <ctype.h>
// PROTOTIPO DE FUNCIONES.
void funcionProceso1(int *, int *, char *, float *);
void funcionProceso2(char, float, int *, int *, float *, float *);

int main()
{

    // PARÁMETROS A PASAR.
    int totalLegajos, añoMaximo;
    char gradoMax;
    float promedioMax;
    // INCIALIZO PARÁMETROS.
    totalLegajos = 0;
    añoMaximo = 0;
    gradoMax = '-';
    promedioMax = 0;

    funcionProceso1(&totalLegajos, &añoMaximo, &gradoMax, &promedioMax);

    printf("El total de legajos procesados es: %d", totalLegajos);

    printf("\nEl mayor promedio fue de %.2f pertenece al grado %c del año %d", promedioMax, gradoMax, añoMaximo);

    return 0;
}
void funcionProceso1(int *totalLegajos, int *añoMaximo, char *gradoMax, float *promedioMax)
{
    int top = 1, legajo, contA, contB, posicionA, posicionB;
    char grado;
    float nota, acumA, acumB, promA, promB, promGenA, promGenB;
    promA = 1;
    promB = 1;
    contA = 0;
    contB = 0;
    acumA = 0;
    acumB = 0;
    promGenA = 0;
    promGenB = 0;

    for (int i = 1; i <= top; i++)
    {

        printf("Usted est%c en el año %d\n", 161, i);

        // RESETEO LOS VALORES PARA LA PROXIMA ITERACIÓN
        promA = 1;
        promB = 1;
        contA = 0;
        contB = 0;
        acumA = 0;
        acumB = 0;

        printf("ingrese un n%cmero de legajo: ", 163);
        scanf("%d", &legajo);

        while (legajo != 0)
        {
            // LLENADO DE DATOS.
            fflush(stdin);
            printf("Ingrese el grado: ");
            scanf("%c", &grado);
            fflush(stdin);
            printf("\nIngrese la nota: ");
            scanf("%f", &nota);

            grado = tolower(grado);
            funcionProceso2(grado, nota, &contA, &contB, &acumA, &acumB);
            printf("ingrese un nuevo numero de legajo, o para finalizar, digite 0: ");
            scanf("%d", &legajo);
            (*totalLegajos)++;
        }

        promA = acumA / contA;
        promB = acumB / contB;
        printf("(*) Grado %d - promedio general: \n", i);
        printf("A = %.2f\n B = %.2f", promA, promB);

        if (promA > promGenA)
        {
            promGenA = promA;
            posicionA = i;
        }
        if (promB > promGenB)
        {
            promGenB = promB;
            posicionB = i;
        }
    }
    if (promGenA > promGenB)
    {
        *promedioMax = promGenA;
        *añoMaximo = posicionA;
        *gradoMax = 'A';
    }
    else
    {
        *promedioMax = promGenB;
        *añoMaximo = posicionB;
        *gradoMax = 'B';
    }
}

void funcionProceso2(char grado, float nota, int *contA, int *contB, float *acumA, float *acumB)
{
    switch (grado)
    {
    case 'a':
        (*contA)++;
        *acumA += nota;
        break;
    case 'b':
        (*contB)++;
        *acumB += nota;
        break;

    default:
        break;
    }
}