/* Se ingresa un número de hasta 5 cifras y se indica si es o no capicúa */

#include <stdio.h>

int main()
{
    char num[6];

    printf("Ingrese un n%cmero (max = 5 cifras): ", 163);
    scanf("%s", num);
    fflush(stdin);

    if (num[0] == num[4] && num[1] == num[3]) {
        printf("N%cmero capic%ca", 163, 163);
    } else {
        printf("El n%cmero NO es capic%ca", 163, 163);
    }

    getchar();
    return 0;
}