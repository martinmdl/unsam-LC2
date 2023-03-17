#include <stdio.h>

int main()
{
    float num1, num2;

    printf("Ingrese el primer n%cmero: ", 163);
    scanf("%f", &num1);
    printf("Ingrese el segundo n%cmero: ", 163);
    scanf("%f", &num2);
    fflush(stdin);

    printf("\nSuma = %.2f\nResta = %.2f\nMultiplicaci%cn = %.2f\nDivisi%cn = %.2f\nPromedio = %.2f\n2.A - B/2 = %.2f", num1 + num2, num1 - num2, 162, num1 * num2, 162, num1 / num2, (num1 + num2) / 2, num1 * 2 - num2 / 2);

    getchar();
    return 0;
}