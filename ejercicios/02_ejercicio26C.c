#include <stdio.h>

int main()
{
    int input, ss, hs, ms;
    int aux;

    printf("Ingesar una cantidad entera de segundos: ");
    scanf("%d", &input);

    ss = input % 60;
    input = input / 60;
    ms = input % 60;
    hs = input / 60;

    /* ss = input % 60;
    aux = input / 60;
    ms = aux % 60;
    hs = aux / 60; */

    printf("VALOR: %d:%d:%d", hs, ms, ss);

    getchar();
    return 0;
}