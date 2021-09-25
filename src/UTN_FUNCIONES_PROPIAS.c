/*
 * UTN_MATH.c
 *
 *  Created on: Sep 20, 2021
 *      Author: naza
 */

// Acá va el desarrollo de las funciones (matemáticas)

#include "UTN_FUNCIONES_PROPIAS.h"

#include <stdio.h>
#include <stdlib.h>

int utn_calculoFactoriales(float operador1, float operador2, int* resultadoFactorialA, int* resultadoFactorialB)
{
	int operadorUnoInt;
	int operadorDosInt;

	int acumuladorFactorialA;
	int acumuladorFactorialB;

	acumuladorFactorialA = 1;
	acumuladorFactorialB = 1;

	operadorUnoInt = (int) operador1;
	operadorDosInt = (int) operador2;

	for (int i = operadorUnoInt; i > 1; i--) // nunca entra acá porque no empieza con i == 1
	{
		acumuladorFactorialA = acumuladorFactorialA * i;
	}

	for (int j = operadorDosInt; j > 1; j--)
	{
		acumuladorFactorialB = acumuladorFactorialB * j;
	}

	*resultadoFactorialA = acumuladorFactorialA;
	*resultadoFactorialB = acumuladorFactorialB;

	return 0;
}



int utn_multiplicacionDeFloats(float operador1, float operador2, float* resultadoMultiplicacion)
{
	*resultadoMultiplicacion = operador1 * operador2;
	return 0;
}

int utn_divisionDeFloats(float operador1, float operador2, float* resultadoDivision)
{
	int estado;
	if (operador2 != 0)
	{
		*resultadoDivision = operador1/operador2;
		estado = 0;
	}
	else
	{
		estado = 1;
	}
	return estado;
}

int utn_restaDeFloats(float operador1, float operador2, float* resultadoResta)
{
	*resultadoResta = operador1 - operador2;
	return 0;
}

int utn_sumaDeFloats(float operador1, float operador2, float* resultadoSuma)
{
	*resultadoSuma = operador1 + operador2;
	return 0;
}


int utn_esNumerica(char textoNumericoIngresado[])
{
	int utn_strlength(char miCadenaDeCaracter[], int* pLargoDelTexto);
	int estado;
	int largoTexto;
	utn_strlength(textoNumericoIngresado,&largoTexto);

	if (textoNumericoIngresado != NULL)
	{
		for(int i = 0; i < largoTexto; i++)
		{
			if ((textoNumericoIngresado[i] >= '0' && textoNumericoIngresado[i] <= '9') || textoNumericoIngresado[i] == '.')
			{
				estado = 0;
			}
			else
			{
				estado = 2; // No es numérico
			}
		}
	}
	else
	{
		estado = 1; // el array es nulo
	}
	return estado;
}

int utn_CadenaNumericaEnInt(char textoNumericoIngresado[], int* textoNumericoEnInt)
{
	int utn_strlength(char miCadenaDeCaracter[], int* pLargoDelTexto);

	int largoTexto;
	int estado;

	utn_strlength(textoNumericoIngresado,&largoTexto);

	for (int i = 0; i < largoTexto; i++)
	{
		if (textoNumericoIngresado[i] > '0' && textoNumericoIngresado[i] < '9')
		{
			estado = 0;
		}
		else
		{
			estado = 1;
		}
	}
	if (estado == 0)
	{
		// Esto es porque en la documentación del atoi, te pide que lo pases a un int, no a un array de int
		*textoNumericoEnInt = atoi(textoNumericoIngresado);
	}
	else
	{
		printf("La cadena contiene caracteres que no son números. Error Nº: ");
	}
	return estado;
}

// Hacer strncpy
/*
 * 1º parametro -> variable de destino
 * 2º parametro -> variable de origen
 * 3º parametro -> tamaño de 2º parametro para agarrar caracteres de 1º parametro
 * veo qué tan larga es dest y, de ahí, copio ese nº de src. No modifico tamaño de dest
 * */

int utn_strncopy(char dest[],char src[], int lengthToCopyFromSource)
{
	// si dest tiene 10 lugares, entonces, voy a agarrar 10 de origen y ponerlos en dest
	int utn_strlength(char miCadenaDeCaracter[], int* pLargoDelTexto);
	int estado;
	int destLength;
	int i;
	int j;

	// tengo que usar strlen porque char dest[] es un pointer, no la cadena per se
	utn_strlength(dest,&destLength); //esto es lo que copio

	if(src != NULL && dest != NULL)
	{

		// tengo que copiar from src solo los que el usuario diga
		for(i = 0; i < lengthToCopyFromSource; i++)
		{
			dest[i] = src[i];
		}
		// El resto deben ser \0
		// j = lengthSrc -> reemplazo por \0 desde que estás ya en la última posición (q siempre es \0)
		for(j = lengthToCopyFromSource; j < destLength; j++)
		{
			dest[j] = '\0';
		}
		estado = 0;
	}
	else
	{
		estado = 1;
	}
	return estado;
}



// Hacer función puts (solo char)


int utn_puts(char miCadenaDeCaracter[])
{
	int estado;
	if(miCadenaDeCaracter != NULL)
	{
		printf("%s", miCadenaDeCaracter);
		printf("\n");
		estado = 0;
	}
	else
	{
		estado = 1;
	}
	return estado;
}

// Hacer la función strlength, largo del texto

int utn_strlength(char miCadenaDeCaracter[], int* pLargoDelTexto)
{
	int i = 0;
	int estado;

	if(miCadenaDeCaracter != NULL)
	{
		while (miCadenaDeCaracter[i] != '\0') // si no entra -> i = 0, si entra, cuenta al menos 1
		{
			i++;
		}
		*pLargoDelTexto = i;
		estado = 0;
	}
	else
	{
		estado = 1; // error
	}
	return estado;
}
