#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define CANT_EQUIPOS 4
#define CANT_MESES 6
#define CANT_TIEMPOS 10
#define LARGO_STR 30

// DECLARACION DE ESTRUCTURAS
typedef struct competidores {
    int idCompetidor;
    char provincia[LARGO_STR];
    float tiempos[CANT_TIEMPOS];
    float promMes;
    float promMax;
} competidores;

typedef struct instructores {
    int idInstructor;
    char nombreCompetidor[LARGO_STR];
    char nombreInstructor[LARGO_STR];
} instructores;

// PROTOTIPOS
void cargaCompetidores(competidores competidor[], instructores instructor[]);
void inicializaciones(competidores competidor[], int arrControl[], float promediosGenerales[][CANT_MESES]);
void promedioMensual(competidores competidor[]); // EJERCICIO 5
void promediosMensualesDestacados(competidores competidor[], float promediosGenerales[][CANT_MESES]); // EJERICIO 6
int promediosMensualesBajos(competidores competidor[], int arrControl[]); // EJERCICIO 7
void emitirEquipos(competidores competidor[], instructores instructor[], int arrControl[], int cont); // EJERCICIO 8
void ordenarProvincias(competidores competidor[]); // EJERCICIO 9

// MAIN
int main() {
    competidores competidor[CANT_EQUIPOS];
    instructores instructor[CANT_EQUIPOS];
    int arrControl[CANT_EQUIPOS];
    float promediosGenerales[CANT_EQUIPOS][CANT_MESES];

    cargaCompetidores(competidor, instructor);
    inicializaciones(competidor, arrControl, promediosGenerales); // REVISAR "promedios[][M]"
    promedioMensual(competidor); // EJERCICIO 5    
    promediosMensualesDestacados(competidor, promediosGenerales); // EJERICIO 6
    int cont = promediosMensualesBajos(competidor, arrControl); // EJERCICIO 7
    emitirEquipos(competidor, instructor, arrControl, cont); // EJERCICIO 8
    ordenarProvincias(competidor); // EJERCICIO 9

    getchar();
    return 0;
}

// CARGA DE COMPETIDORES
void cargaCompetidores(competidores competidor[], instructores instructor[]) {
    srand(time(NULL));
    int i, j;
    for(i = 0; i < CANT_EQUIPOS; i++) {
        printf("COMPETIDOR %d\n", i+1);
        printf("\tID: ");
        scanf("%d", &competidor[i].idCompetidor);
        fflush(stdin);
        instructor[i].idInstructor = competidor[i].idCompetidor;
        printf("\tProvincia: ");
        gets(competidor[i].provincia);
        fflush(stdin);
        printf("\tNombre competidor: ");
        gets(instructor[i].nombreCompetidor);
        fflush(stdin);
        printf("\tNombre instructor: ");
        gets(instructor[i].nombreInstructor);
        fflush(stdin);
        for(j = 0; j < CANT_TIEMPOS; j++) {
            // LLENADO AUTOMATICO
            competidor[i].tiempos[j] = 10 + rand() % 40;
            // LLENADO MANUAL
            // printf("\tTiempo %d: ", j+1);
            // scanf("%f", &competidor[i].tiempos[j]);
            // fflush(stdin);
        }
        system("cls");
    }
}

// INICIALIZACIONES
void inicializaciones(competidores competidor[], int arrControl[], float promediosGenerales[][CANT_MESES]) {
    srand(time(NULL));
    int i, j;
    for(i = 0; i < CANT_EQUIPOS; i++) {
        competidor[i].promMes = 0; // PUNTO 1
        competidor[i].promMax = 0; // PUNTO 1
        arrControl[i] = -1; // PUNTO 3
        for(j = 0; j < CANT_MESES; j++)
            promediosGenerales[i][j] = 100 + rand() % 400; // PUNTO 4
    }
}

// EJERICIO 5
void promedioMensual(competidores competidor[]) {
    int i, j;
    float acum;
    for(i = 0; i < CANT_EQUIPOS; i++) {
        acum = 0;
        for(j = 0; j < CANT_TIEMPOS; j++)
            acum += competidor[i].tiempos[j];
        competidor[i].promMes = acum / CANT_TIEMPOS;
    }
}

// EJERICIO 6
void promediosMensualesDestacados(competidores competidor[], float promediosGenerales[][CANT_MESES]) {
    int i, j;
    float max;
    for(i = 0; i < CANT_EQUIPOS; i++) {
        max = -1;
        for(j = 0; j < CANT_MESES; j++)
            if(promediosGenerales[i][j] > max) {
                max = promediosGenerales[i][j];
                competidor[i].promMax = max;
            }
    }
}

// EJERCICIO 7
int promediosMensualesBajos(competidores competidor[], int arrControl[]) {
    int cont = 0, i;
    for(i = 0; i < CANT_EQUIPOS; i++)
        if(competidor[i].promMax > competidor[i].promMes) {
            arrControl[cont] = i;
            cont++;
        }
    return cont;
}

// EJERCICIO 8
void emitirEquipos(competidores competidor[], instructores instructor[], int arrControl[], int cont) {
    int i;    
    printf("Equipos que no batieron su record pesonal\n");
    for(i = 0; i < cont; i++) {
        printf("\n\tEQUIPO %d\n", arrControl[i]+1);
        printf("\t\tProvincia: %s\n", competidor[arrControl[i]].provincia);
        printf("\t\tInstructor: %s\n", instructor[arrControl[i]].nombreInstructor);
        printf("\t\tCompetidor: %s\n", instructor[arrControl[i]].nombreCompetidor);
    }
    getchar();
    system("cls");
}

// EJERCICIO 9
void ordenarProvincias(competidores competidor[]) {
    int i, j;
    competidores aux;
    for(i = 0; i < (CANT_EQUIPOS - 1); i++)
        for(j = 0; j < (CANT_EQUIPOS - (i+1)); j++)
            if (strcmp(competidor[j].provincia, competidor[j+1].provincia) > 0) {
                aux = competidor[j];
                competidor[j] = competidor[j+1];
                competidor[j+1] = aux;
            }
}



