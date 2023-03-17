#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    printf("%d\n", 10 + rand() % 10); // random del 10 al 19
    printf("%d\n", 10 + rand() % 10);
    printf("%d\n", 10 + rand() % 10);
    printf("%d\n", 10 + rand() % 10);

    return 0;
}