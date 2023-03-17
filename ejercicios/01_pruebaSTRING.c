/*  Construye un programa que permita calificar a un grupo de n alumnos de la escuela secundaria. Por teclado se ingresan el nombre y
10 calificaciones de cada alumno, con nota desde 0 a 10; con esos datos el programa debe calcular e informar el promedio de cada
alumno y decir si está aprobado o no; para aprobar se requiere un promedio de 6 o más y haber obtenido al menos 6 en la última de
las calificaciones. Posteriormente el programa debe informar cuántos alumnos se ingresaron en el programa, cuántos alumnos
aprobaron y cuántos obtuvieron un promedio de al menos 8. */

#include <stdio.h>

int main()
{
    char nombre[20], materia[20];
    int i, j;
    float nota, promedio, totalNota;

    for (i = 1; i <= 2; i++)
    {
        printf("Ingrese el nombre del alumno %d: ", i);
        scanf("%s", nombre); // las cadenas no llevan & porque son punteros (corta el string con espacio)
        fflush(stdin);
        printf("Ingrese el nombre de la materia: ");
        gets(materia); // gets(materia) -> no corta el string por un espacio
        fflush(stdin);
        totalNota = 0;

        for (j = 1; j <= 3; j++)
        {
            printf("Ingrese la nota %d: ", j);
            scanf("%f", &nota);
            totalNota += nota;
        }

        promedio = ((totalNota) / 3);
        printf("El promedio es: %.2f\n\n", promedio);
    }

    return 0;
}
