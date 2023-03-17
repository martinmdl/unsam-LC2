#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define N 2
#define M 6

typedef struct sucursales
{
    int idSucursal;
    char ciudad[30];
    float descuentosMes[3];
    float descuentoMesTotal;
    float promDescuentos;
} sucursales;

typedef struct gerentes
{
    int idSucursalGerente;
    char nombreGerente[30];
} gerentes;

void cargaSucursal(sucursales sucursal[]);
void cargaGerentes(gerentes gerente[]);
void cargaDescuentos(float descuentos[][M]);
void printGerentesYSucursal(gerentes gerente[],sucursales sucursal[]);
void ej1(sucursales sucursal[]);
void ej2(sucursales sucursal[],float descuentos[][M]);
int ej3(sucursales sucursal[], int arrMenosUno[]);
void ej4(sucursales sucursal[], gerentes gerente[], int arrMenosUno[],int cont);
void ej5(sucursales sucursal[]);

int main()
{
    srand(time(NULL));
    int i,cont=0;

    sucursales sucursal[N];
    gerentes gerente[N];
    int arrMenosUno[N] = {-1, -1};

    float descuentos[N][M];

    cargaSucursal(sucursal);
    cargaGerentes(gerente);
    cargaDescuentos(descuentos);
    ej1(sucursal);
    ej2(sucursal, descuentos);
    cont=ej3(sucursal, arrMenosUno);
    ej4(sucursal, gerente, arrMenosUno, cont);
    ej5(sucursal);
    getchar();
    printGerentesYSucursal(gerente,sucursal);

    getchar();
    return 0;
}

void cargaSucursal(sucursales sucursal[])
{
    int i, j;
    for(i = 0; i < N; i++)
    {

        printf("\t SUCURSAL %d\n",i+1);
        printf("-------------------------------------------------------------------------------------------------\n");
        printf("Ingrese ID: \n");
        scanf("%d", &sucursal[i].idSucursal);
        fflush(stdin);
        printf("Ingrese Ciudad: \n");
        gets(sucursal[i].ciudad);
        fflush(stdin);
        printf("Ingrese Descuento: \n");
        for (j = 0; j < 3; j++)
        {
            printf("Nro de descuento %d\n", j+1);
            scanf("%f", &sucursal[i].descuentosMes[j]);
            fflush(stdin);
        }

        sucursal[i].descuentoMesTotal=0;
        sucursal[i].promDescuentos=0;
    }
    system("cls");
}

void cargaGerentes(gerentes gerente[])
{

    for(int i=0; i<N; i++)
    {
        printf("\t GERENTE %d\n",i+1);
        printf("-------------------------------------------------------------------------------------------------\n");
        printf("Ingrese la Id de la sucursal del gerente: \n");
        scanf("%d",&gerente[i].idSucursalGerente);
        fflush(stdin);
        printf("Ingrese el nombre del gerente: \n");
        scanf("%s",gerente[i].nombreGerente);
        fflush(stdin);

    }

    system("cls");
}

void cargaDescuentos(float descuentos[][M])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            descuentos[i][j]=rand()%50;
        }
    }
}

void ej1(sucursales sucursal[])
{
    float acumDesc=0;

    for (int i=0; i<N ; i++)
    {
        acumDesc=0;
        for (int j=0; j<3 ; j++)
        {
            acumDesc+=sucursal[i].descuentosMes[j];
        }
        sucursal[i].descuentoMesTotal=acumDesc;
    }
}

void ej2(sucursales sucursal[],float descuentos[][M])
{
    float acumProm=0;
    for (int i=0; i<N ; i++)
    {
        for (int j=0; j<M ; j++)
        {
            acumProm+=descuentos[i][j];
        }
        sucursal[i].promDescuentos=acumProm/M;
        //printf("Los promedios de los descuentos son: %.2f \n", sucursal[i].promDescuentos);

    }
}

int ej3(sucursales sucursal[], int arrMenosUno[])
{
    int cont=0;

    for(int i=0; i<N; i++)
    {
        if(sucursal[i].descuentoMesTotal > sucursal[i].promDescuentos)
        {
            arrMenosUno[cont]=i;
            cont++;
        }
    }
    return cont;
}

void ej4(sucursales sucursal[], gerentes gerente[], int arrMenosUno[],int cont)
{
    for(int i=0; i<cont; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(sucursal[arrMenosUno[i]].idSucursal == gerente[j].idSucursalGerente)
            {
                printf("Cuidad: %s, y el nombre del gerente es: %s\n", sucursal[j].ciudad, gerente[j].nombreGerente);
            }
        }
    }
}

void ej5(sucursales sucursal[])
{
    int i,j, flag;
    sucursales aux;

    for(i=0; i<N-1; i++)
    {
        flag=0;
        for(j=0; j<N-(i+1); j++)
        {
            if(strcmp(sucursal[j].ciudad, sucursal[j+1].ciudad)>0)
            {
                aux=sucursal[j];
                sucursal[j]=sucursal[j+1];
                sucursal[j+1]=aux;
                flag=1;
            }
        }
    }
}
void printGerentesYSucursal(gerentes gerente[],sucursales sucursal[])
{

    for(int i = 0; i < N; i++)
    {

        printf("--------------------------------------------------------------------------------\n");
        printf("SUCURSAL %d\n",i+1);
        printf("ID: %d \n",sucursal[i].idSucursal);
        printf("Ciudad: %s\n", sucursal[i].ciudad);
        printf("Ingrese Descuento: \n");
        for (int j = 0; j < 3; j++)
        {
            printf("Descuento numero %d, es de: %.2f \n", j+1, sucursal[i].descuentosMes[j]);
        }
        printf("Total acumulado: %.2f\n", sucursal[i].descuentoMesTotal);
        printf("Promedio: %.2f\n", sucursal[i].promDescuentos);

    }

    for(int i=0; i<N; i++)
    {
        printf("--------------------------------------------------------------------------------\n");
        printf("GERENTE %d\n",i+1);
        printf("La Id de la sucursal del gerente es: %d\n", gerente[i].idSucursalGerente);
        printf("El nombre del gerente es: %s\n", gerente[i].nombreGerente);
    }

}
