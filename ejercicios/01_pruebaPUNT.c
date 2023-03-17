#include <stdio.h>
#include <ctype.h>

int main() {

    int num, *pnum;
    char car, *pcar, carmod;

    pcar = &car;
    pnum = &num;

    num = 1;
    car = 'T';

    car = tolower(car); // se debe guardar en una variable para que funcione
    (*pnum)++; // "*pnum++;" no funciona, se deben agregar parentesis

    printf("CHAR = %c", car);

    getchar();
    return 0;
}