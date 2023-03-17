#include <stdio.h>

int main()
{
    int a, b, c;
    int primero, segundo, tercero;
    int log;

    primero = a;
    segundo = b;
    tercero = c;

    printf("Ingrese tres caracteres:\n");
    scanf("%c %c %c", &a, &b, &c);

    if (a < c && a < b) {
        primero = a;
        if (b < c) {
            segundo = b;
            tercero = c;
        } else {
            segundo = c;
            tercero = b;
        }
    } else {
        if (b < a && b < c) {
            primero = b;
            if (a < c) {
                segundo = a;
                tercero = c;
            } else {
                segundo = c;
                tercero = a;
            }
        } else {
            if (c < a && c < b) {
                primero = c;
                if (a < b) {
                    segundo = a;
                    tercero = b;
                } else {
                    segundo = b;
                    tercero = a;
                }
            }
        }
    }

    printf("Ordenadas: %c %c %c", primero, segundo, tercero);

    getchar();
    return 0;
}