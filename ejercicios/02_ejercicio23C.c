#include <stdio.h>

int main()
{
    int Atime1, Btime1, Ctime1, Atime2, Btime2, Ctime2, hs = 0, ms = 0, ss = 0;

    printf("Ingrese primer tiempo (hora): ");
    scanf("%d", &Atime1);
    printf("Ingrese primer tiempo (mins): ");
    scanf("%d", &Btime1);
    printf("Ingrese primer tiempo (segs): ");
    scanf("%d", &Ctime1);
    fflush(stdin);

    printf("\nIngrese segundo tiempo (hora): ");
    scanf("%d", &Atime2);
    printf("Ingrese segundo tiempo (mins): ");
    scanf("%d", &Btime2);
    printf("Ingrese segundo tiempo (segs): ");
    scanf("%d", &Ctime2);
    fflush(stdin);

    ss = Ctime1 + Ctime2;

    if (ss > 60)
    {
        ss = ss - 60;
        ms = 1;
    }

    ms += Btime1 + Btime2;

    if (ms > 60)
    {
        ms = ms - 60;
        hs = 1;
    }

    hs += Atime1 + Atime2;

    printf("\n%d:%d:%d + %d:%d:%d = %d:%d:%d", Atime1, Btime1, Ctime1, Atime2, Btime2, Ctime2, hs, ms, ss);

    getchar();
    return 0;
}