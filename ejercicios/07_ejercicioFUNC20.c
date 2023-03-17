#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

void menu();
void userInput(int*);
void cuadrado();
void circulo();
void trapecio();
void rectangulo();
void triangulo();

int main() {
    
    int input;

    printf("\n++ C%cLCULO DE SUPERFICIES ++\n", 181);
    
    userInput(&input);

    switch (input) {

        case 1:
            cuadrado();
            break;

        case 2:
            circulo();
            break;

        case 3:
            rectangulo();
            break;

        case 4:
            trapecio();
            break;

        case 5:
            triangulo();
            break;

        case 0:
            system("pause>nul|set/p =Presione cualquier tecla para salir ...");
            break;
    }

    return 0;
}

void menu() {
    printf("\n1. Cuadrado\n2. C%crculo\n3. Rect%cngulo\n4. Trapecio\n5. Tri%cngulo\n0. Salir del programa\n", 161, 160, 160, 160);
}

void userInput(int *input) {

    menu();

    printf("\nElija una opci%cn: ", 162);
    scanf("%d", input);
    fflush(stdin);

    // VALIDACION
    while (*input < 0 || *input > 5) {

        printf("\nElija una opci%cn v%clida: ", 162, 160);
        scanf("%d", input);
        fflush(stdin);
    }
}

void cuadrado() {

    float lado, area;

    printf("\nLado: ");
    scanf("%f", &lado);
    fflush(stdin);

    area = lado * lado;
    printf("\nArea del cuadrado: %f", area);

    getchar();
}

void circulo() {

    float pi = acos(-1), radio, area;

    printf("\nRadio: ");
    scanf("%f", &radio);
    fflush(stdin);

    area = pi * pow(radio, 2);
    printf("\nArea del ciruclo: %f", area);

    getchar();
}

void rectangulo() {

    float base, altura, area;

    printf("\nBase: ");
    scanf("%f", &base);
    printf("\nAltura: ");
    scanf("%f", &altura);
    fflush(stdin);

    area = base * altura;
    printf("\nArea del rectangulo: %f", area);

    getchar();
}

void trapecio() {

    float base1, base2, altura, area;

    printf("\nBase 1: ");
    scanf("%f", &base1);
    printf("\nBase 2: ");
    scanf("%f", &base2);
    printf("\nAltura: ");
    scanf("%f", &altura);
    fflush(stdin);

    area = (base1 + base2) * altura / 2;
    printf("\nArea del trapecio: %f", area);

    getchar();
}

void triangulo() {

    float base, altura, area;

    printf("\nBase: ");
    scanf("%f", &base);
    printf("\nAltura: ");
    scanf("%f", &altura);
    fflush(stdin);

    area = base * altura / 2;
    printf("\nArea del triangulo: %f", area);

    getchar();
}