/*
 ============================================================================
 Name        : SantaCruzTP1.c
 Author      : Nazareno Santa Cruz
 Version     :
 Copyright   : Nazareno Santa Cruz
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "UTN_FUNCIONES_PROPIAS.h"

int main(void) {
	setbuf(stdout, NULL);
	// Al ser un char puedo usar tanto un número (textual) como un mensaje de sin definir.
	char valorDeAChar[100] = {"Valor de A. Sin definir"};
	char valorDeBChar[100] = {"Valor de B. Sin definir"};
	int opcionElegida;

	float valorDeAFloat;
	float valorDeBFloat;
	int operadorUnoCheck;
	int operadorDosCheck;
	int flagOperaciones;
	int estadoDivision;

	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	int resultadoFactorialA;
	int resultadoFactorialB;

	// Inicializo a las variables que verifican si los valores son float/enteros.
	operadorUnoCheck = utn_esNumerica(valorDeAChar); // No sé si la función que hice funciona para floats
	operadorDosCheck = utn_esNumerica(valorDeBChar);
	do
	{
		do
		{
			printf("Elija alguna de las 5 opciones. \n");
			printf("1. Ingresar 1er operando (A=%s). \n",valorDeAChar);
			printf("2. Ingresar 2do operando (B=%s). \n",valorDeBChar);
			printf("3. Calcular todas las operaciones. \n");
			printf("\t a) Calcular la suma (%s+%s)\n", valorDeAChar, valorDeBChar);
			printf("\t b) Calcular la resta (%s-%s)\n", valorDeAChar, valorDeBChar);
			printf("\t c) Calcular la división (%s/%s)\n", valorDeAChar, valorDeBChar);
			printf("\t d) Calcular la multiplicación (%s*%s)\n", valorDeAChar, valorDeBChar);
			printf("\t e) Calcular el factorial (%d! y %d!)\n", atoi(valorDeAChar), atoi(valorDeBChar));
			printf("4. Informar resultados\n");
			// Solo los muestro si eligió la opción 4.
			/* printf("\t a) El resultado de %s+%s es: r\n");
			printf("\t b) El resultado de %s-%s es: r\n");
			printf("\t c) El resultado de %s/%s es: r\n");
			printf("\t d) El resultado de %s*%s es: r\n");
			printf("\t e) El factorial de %s es: %s y El factorial de %s es: %s\n"); */
			printf("5. Salir\n");
			scanf("%d",&opcionElegida);
			fpurge(stdin);
		} while(opcionElegida < 1 || opcionElegida > 5);

		switch(opcionElegida)
		{
			case 1:
				do
				{
				printf("Por favor, escriba el 1º operando.");
				scanf("%s",valorDeAChar);
				fpurge(stdin);
				operadorUnoCheck = utn_esNumerica(valorDeAChar);
				} while (operadorUnoCheck != 0);
				break;
			case 2:
				do
				{
					printf("Por favor, escriba el 2º operando.");
					scanf("%s",valorDeBChar);
					fpurge(stdin);
					operadorDosCheck = utn_esNumerica(valorDeBChar);
				} while (operadorDosCheck != 0);
				break;
			case 3:
				// Calcular operaciones
				// Tengo que verificar que se hayan ingresado los dos números
				if (operadorUnoCheck == 0 && operadorDosCheck == 0)
				{
					// ejecuto operaciones
					valorDeAFloat = atof(valorDeAChar);
					valorDeBFloat = atof(valorDeBChar);

					// Suma

					utn_sumaDeFloats(valorDeAFloat, valorDeBFloat, &resultadoSuma);

					// Resta

					utn_restaDeFloats(valorDeAFloat, valorDeBFloat, &resultadoResta);

					// Multiplicación

					utn_multiplicacionDeFloats(valorDeAFloat, valorDeBFloat, &resultadoMultiplicacion);

					// División

					estadoDivision = utn_divisionDeFloats(valorDeAFloat, valorDeBFloat, &resultadoDivision);

					// Factorial

					utn_calculoFactoriales(valorDeAFloat, valorDeBFloat, &resultadoFactorialA, &resultadoFactorialB);

					flagOperaciones = 0;
				}
				else
				{
					printf("Por favor. Verificar que se hayan ingresado los dos operandos.\n");
				}
			break;
			case 4:
				if (flagOperaciones == 0)
				{
					printf("a) El resultado de %f+%f es: %f\n",valorDeAFloat, valorDeBFloat, resultadoSuma);
					printf("b) El resultado de %f-%f es: %f\n",valorDeAFloat, valorDeBFloat, resultadoResta);
					printf("c) El resultado de %f*%f es: %f\n",valorDeAFloat, valorDeBFloat, resultadoMultiplicacion);

					if (estadoDivision == 0)
					{
						printf("d) El resultado de %f/%f es: %f\n",valorDeAFloat, valorDeBFloat, resultadoDivision);
					}
					else
					{
						printf("d) El 2º operando es un 0. No se puede dividir por 0.\n");
					}

					printf("e) El factorial de %d es: %d y El factorial de %d es: %d\n", atoi(valorDeAChar), resultadoFactorialA, atoi(valorDeBChar), resultadoFactorialB);
				}
				else
				{
					printf("Verificar que se haya elegido la opción 3 (de calcular) previamente.\n");
				}
			break;
			case 5:
			break;
		}
	} while (opcionElegida != 5);
	return EXIT_SUCCESS;
}
