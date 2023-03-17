#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct strings {
    char str1[30];
    char str2[30];
};

int main() {
    srand(time(NULL));

    printf("VALOR = %d\n", (100 + (rand() % 400)) / 10);
    printf("VALOR = %d\n", 100 + (rand() % 400));
    

    return 0;
}