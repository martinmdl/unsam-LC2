#include<stdio.h>

// int variable = 0; -> variable global (todas las funciones tiene acceso)

float calcpotencia(float, int); 
// "prototipo" de la funcion calcpotencia (escribirlo antes de main si la funcion esta dsp de main)
// si un parametro es puntero -> float calcpotencia(float, int *punt);

int main()
{
	float base, pot; 
	int exp; // variable local -> solo "main" tiene acceso
	printf("Ingrese la base: ");
	scanf("%f", &base);
	printf("Ingrese el exponente: ");
	scanf("%d", &exp);

	pot = calcpotencia(base, exp);
	// pot = retorno + ejecución
	// (base, exp) -> argunmentos actuales (en main)

	printf("La potencia es %.2f", calcpotencia(base, exp));
	// printf no solo llama al retorno sino que ejecuta la funcion
	// printf("La potencia es %.2f", pot);

	return 0;
}


// funciones tipo void = no hay retorno
// una funcion no puede anidar otra (llamarlas si = recursividad)
// anidar = definir funciones dentro de otras
float calcpotencia(float base, int exp) { // tipo de dato de parametros/argumentos = tipo de inputs en main (tiene que coincidir: orden, cantidad, tipo)
										  // (float base, int exp) -> argumentos formales (en la funcion)
										  // se puede pasar parametros por valor o por dirección
										  // por direccion -> argumento formal = *puntero && argumento actual = &direccion

	int ciclo; // variable local -> su nombre puede repetirse sin relacionarse con las anteriores con el mismo nombre
	float pot; 
	pot = base;
	if (exp == 0)
		pot = 1;
	else
		for(ciclo=1;ciclo<exp;ciclo++)
			pot = pot * base;

	printf("\n\nPRUEBA\n\n");

	return pot;
}

