#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main() {

    int n, res;

    printf("Ingrese x!\nx = ");
    scanf("%d", &n);

    // OPCION 1 
    /* res = factorial(n);
    printf("%d! = %d", n, res); */

    // OPCION 2
    printf("%d! = %d", n, factorial(n));

    system("pause");
    getchar();
    return 0;
}

int factorial(int a) {

    if (a == 0)
        return 1;
    else
        return (factorial(a - 1) * a);
}