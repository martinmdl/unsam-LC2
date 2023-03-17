/* 14. Una empresa tiene un número no determinado de empleados, que evalúa durante los proyectos en los cuales 
participan en varios ítems. Por cada empleado se lee: 
- El código del empleado (entero)
- Edad del mismo (entero)
- N cantidad de notas (cada nota es un real, N es una constante). 
El último empleado se indica con código = -1, valor que no se procesa. Se desea: 
- Emitir la cantidad de empleados con promedio >=7 que sean menores de 30 años
- Emitir un mensaje indicando si algún empleado obtuvo alguna nota 0 (nota, NO promedio)
- Emitir la edad del mayor y menor empleado. */

#include <stdio.h>

int main()
{
    int i, codigo = 0, edad, cantNotas, empleadosA = 0, menorEdad = 200, mayorEdad = 0, flagCero = 0;
    float valorNota, promedio, acumNotas;

    while (codigo != -1) {

        printf("\nC%cdigo: ", 162);
        scanf("%d", &codigo);

        if (codigo == -1)
            break;

        printf("Edad: ");
        scanf("%d", &edad);

        if (edad > mayorEdad)
            mayorEdad = edad;
        if (edad < menorEdad)
            menorEdad = edad;

        printf("Cantidad de notas: ");
        scanf("%d", &cantNotas);

        acumNotas = 0;
        
        for (i = 1; i <= cantNotas; i++) {


            printf("\tNota %d: ", i);
            scanf("%f", &valorNota);

            if (valorNota == 0)
                flagCero = 1;

            acumNotas += valorNota;
        }

        promedio = acumNotas / cantNotas;

        if (promedio >= 7 && edad < 30)
            empleadosA++;

        fflush(stdin);
    }

    printf("\n\nDatos Procesados:");
    
    printf("\n\tEmpleados A: %d", empleadosA);

    if (flagCero == 1)
        printf("\n\tAlgun empleado obtuvo Nota: 0");
    else
        printf("\n\tNingun empleado obtuvo Nota: 0");

    printf("\n\tEl mayor empleado tiene: %d", mayorEdad);
    printf("\n\tEl menor empleado tiene: %d\n", menorEdad);

    system("pause");
    return 0;
}