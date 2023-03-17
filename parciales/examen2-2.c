#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //para el random

//-----DEFINES-----
#define n 4
#define m 6
#define t 10

//-----STRUCTS-----
struct competidor{
    int idComp;
    char provincia[30];
    float tiempos [t];
    float promTiempos;
    float maxProm;
};
struct instructor{
    int idComp;
    char nomComp[30];
    char nomInst[30];
};

//-----FUNCION DE CARGA DE DATOS DE CADA COMPETIDOR-----
void carga(struct competidor *competidores, struct instructor *instructores){
    for (int i=0;i < n; i++){
        printf("Ingrese id del competidor: ");
        scanf("%d", &competidores[i].idComp);
        fflush(stdin);
        instructores[i].idComp=competidores[i].idComp;
        printf("Ingrese nombre del competidor: ");
        gets(instructores[i].nomComp);
        fflush(stdin);
        printf("Ingrese ciudad del competidor: ");
        gets(competidores[i].provincia);
        fflush(stdin);
        printf("Ingrese nombre del instructor: ");
        gets(instructores[i].nomInst);
        fflush(stdin);
    }
}

//-----REQUERIMIENTO 5-----
void cargatiempos(struct competidor *competidores, struct instructor *instructores){
    float sumador;
    for(int i=0;i<n;i++){
        sumador=0;
        printf("Carga de tiempor competidor id: %d", competidores[i].idComp);
        for(int j=0;j<t;j++){
            printf("Ingrese tiempo %d: ", j+1);
            scanf("%f", &competidores[i].tiempos[j]);
            fflush(stdin);
            sumador=sumador+competidores[i].tiempos[j];
        }
        competidores[i].promTiempos=sumador/t;
        printf("El promedio del competidor es de: %f", competidores[i].promTiempos);
    }
}

//-----REQUERIMIENTO 6-----
void promax(struct competidor *competidores, float promMeses[][m]){
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (promMeses[i][j]>competidores[i].maxProm){
                competidores[i].maxProm=promMeses[i][j];
            }
        }
    }

}

//-----REQUERIMIENTO 7-----
int comparacion(struct competidor *competidores, int *arraid){
    int cont=0;
    for(int i=0;i<n;i++){
        if(competidores[i].promTiempos<=competidores[i].maxProm){
            arraid[i]=i;
            cont=cont+1;
        }
    }
    return cont;
}

//-----REQUERIMIENTO 8-----
void retorno(struct competidor *competidores, struct instructor *instructores, int *arraid, int cantComp){
    int cont=0;
    for (int i=0; i<=n;i++){
        if(arraid[i]!=-1){
            printf("Provincia: %s \n", competidores[i].provincia);
            printf("Competidor: %s \n", instructores[i].nomComp);
            printf("Instructor: %s \n", instructores[i].nomInst);
        }
    }
}

//-----REQUERIMIENTO 9-----
void ordenamiento(struct competidor *competidores, struct instructor *instructores){
    struct competidor aux1;
    struct instructor aux2;
    for(int i=0;i<n-1;i++){
        for(int j=0; j<n-(i+1);j++){
            if (strcmp(competidores[i].provincia,competidores[i+1].provincia)>0){
                //burbujeo para el struct competidores
                aux1=competidores[i+1];
                competidores[i+1]=competidores[i];
                competidores[i]=aux1;
                //burbujeo para struct instructores (asi quedan ambos structs ubicados a la par)
                aux2=instructores[i+1];
                instructores[i+1]=instructores[i];
                instructores[i]=aux2;
            }
        }
    }

}

//-----MAIN-----
int main(){
    int cantComp;
    //Se inicializa el arraid de structs
    struct competidor competidores[n];
    struct instructor instructores[n];

    //se inicializa el arraid y se cargan los "-1"
    int arraid [n];
    for (int i=0;i<n;i++){
        arraid[i]=-1;
    }

    //Se carga la matriz de promedios de competidores
    float promMeses [n][m]={
    {167,150,180,212,158,233},
    {405,245,334,253,201,154},
    {151,209,143,453,154,321},
    {182,193,452,123,183,149}};

    //llamado a funciones
    carga(competidores, instructores); //carga de datos
    cargatiempos(competidores, instructores); //req 5
    promax(competidores,promMeses); //req 6
    cantComp=comparacion(competidores,arraid); //req 7
    retorno(competidores, instructores, arraid,cantComp); //req 8
    ordenamiento(competidores, instructores); //req 9

    return 0;
}
