/* De una prueba de nivel realizada a un alumno se conoce la cantidad total de preguntas realizadas y la cantidad de respuestas correctas. Construye un programa que informe el nivel registrado de acuerdo a la siguiente escala
excelente = 100
muy bueno = 99 - 91
bueno = 90 - 60
regular = 59 - 40
malo = < 40 */

#include <stdio.h>

int main()
{
    int cantPreg, cantResp, porcentaje;

    printf("Cantidad total de preguntas: ");
    scanf("%d", &cantPreg);
    printf("Cantidad de respuestas correctas: ");
    scanf("%i", &cantResp);
    fflush(stdin);

    porcentaje = (cantResp * 100) / cantPreg;

    if (porcentaje == 100)
        printf("Excelente");
    else
        if (porcentaje < 100 && porcentaje > 90)
            printf("Muy Bueno");
        else
            if (porcentaje < 91 && porcentaje > 59) 
                printf("Bueno");
            else
                if (porcentaje < 60 && porcentaje > 39) 
                    printf("Regular");
                else 
                    printf("Malo");

    getchar();
    return 0;
}