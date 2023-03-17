#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x ,y ,i ,j;

    printf("X = ");
    scanf("%d", &x);
    printf("Y = ");
    scanf("%d", &y);

    for (i = 1; i <= y; i++) {

        if (i % 2 == 0)
            printf("   ");

        for (j = 1; j <= x; j++) {
            printf(" * ");
        }        

        printf("\n");
    } 

    system("pause");
    return 0;
}