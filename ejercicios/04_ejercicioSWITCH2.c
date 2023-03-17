/* Construir un programa que ingrese un caracter y determine si es una vocal */
#include <stdio.h>

int main()
{
    char letra;

    printf("Ingrese una letra: ");
    scanf("%c", &letra);

    switch (letra)
    {
    case 'A':
    case 'a':
    case 'E':
    case 'e':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'U':
    case 'u':
        printf("La letra es VOCAL");
        break;
    
    default:
        printf("La letra NO es VOCAL");
        break;
    }

    getchar();
    return 0;
}