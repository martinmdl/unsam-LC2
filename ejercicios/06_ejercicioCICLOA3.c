#include <stdio.h>

int main()
{
	int i, j;

	for (i = 'Z'; i >= 'A'; i--)
	{
		for (j = i; j >= 'A'; j--)
			printf("%c", j);

		printf("\n");
	}

	return 0;
}
