/* 24. Nos presentamos en el cajero de un banco el cual tiene únicamente un teclado de 9 dígitos y un botón verde de 
confirmación. Luego de ingresar nuestra clave (esto no lo tendremos en cuenta) nos ofrece 4 opciones que se activan según 
la siguiente tabla
1- Sacar Dinero
2- Depositar Dinero
3- Consultar Saldo
4- Cambiar la clave
Se pide diseñar un programa que permita seleccionar alguna de las 4 opciones y simule la siguiente operatoria:
a. En caso de sacar dinero, el importe deseado.
b. Si se desea depositar dinero el algoritmo deberá solicitar el importe únicamente en pesos 
c. En caso de consulta de Saldo, consultar si quiere ver el de “Caja de ahorro” o “Cuenta Corriente” (opciones 1 y 2 
respectivamente)
d. En caso de cambio de clave, solicitar la vieja clave y la nueva (obviamente son números) y avisar si la misma es 
repetida (o sea la nueva igual a la vieja */

#include <stdio.h>
#include <stdlib.h>

void sacarDinero();
void depositarDinero();
void consultarSaldo();
void cambiarClave();
void tabla(int*);

int main() {

    int opcion = 1;

    while (opcion != 0) {

        tabla(&opcion);

        switch(opcion) {

            case 1:
                sacarDinero();
                break;

            case 2:
                depositarDinero();
                break;

            case 3:
                consultarSaldo();
                break;

            case 4:
                cambiarClave();
                break;

            case 0:        
                return 0;
        }
    }
}

void tabla(int *opcion) {

    printf("\n1- Sacar Dinero\n2- Depositar Dinero\n3- Consultar Saldo\n4- Cambiar la clave\n0- Salir del sistema\n");
    printf("\nOpci%cn: ", 162);
    scanf("%d", opcion);
    fflush(stdin);

    while (*opcion < 0 || *opcion > 4) {
        
        printf("\nIngrese una opci%cn v%clida: ", 162, 160);
        scanf("%d", opcion);
        fflush(stdin);
    }
}


void sacarDinero() {

    float retiro;

    printf("\nIngrese importe a retirar: ");
    scanf("%f", &retiro);    
}

void depositarDinero() {

    float deposito;

    printf("\nIngrese importe a depositar en pesos (ARS): ");
    scanf("%f", &deposito);
}

void consultarSaldo() {

    int seleccion = 0;

    while (seleccion < 1 || seleccion > 2) {

        printf("\nDesea ver:\n1- Caja de ahorro\n2- Cuenta corriente\n");
        printf("\nOpci%cn: ", 162);
        scanf("%d", &seleccion);
        fflush(stdin);
    }
}

void cambiarClave() {

    char pass[21], aux[21];    

    printf("\nIngrese contrase%ca actual: ", 164);
    gets(pass);
    fflush(stdin);

    printf("\nIngrese nueva contrase%ca: ", 164);
    gets(aux);

    if (pass == aux)
        printf("\nContrase%ca repetida! ", 164);
    else {
        pass[21] = aux[21];
        printf("\nContrase%ca cambiada con exito\nNueva contrase%ca: %s", 164, 164, pass);
    }
}
