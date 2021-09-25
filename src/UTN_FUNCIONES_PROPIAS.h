/*
 * UTN_MATH.h
 *
 *  Created on: Sep 20, 2021
 *      Author: Nazareno Santa Cruz
 *
 * En este pongo los prototipos de las funciones.
 * Acá incluyo las bibliotecas que usé adentro de la función
 */

#ifndef UTN_FUNCIONES_PROPIAS_H_
#define UTN_FUNCIONES_PROPIAS_H_

// No sé si esto va acá
#include <stdio.h>
#include <stdlib.h>

int utn_strlength(char miCadenaDeCaracter[], int* pLargoDelTexto);
int utn_puts(char miCadenaDeCaracter[]);
int utn_strncopy(char dest[],char src[], int lengthToCopyFromSource);
int utn_CadenaNumericaEnInt(char textoNumericoIngresado[], int* textoNumericoEnInt);
int utn_esNumerica(char textoParaComprobarSiNumerico[]);
int utn_sumaDeFloats(float operador1, float operador2, float* resultadoSuma);
int utn_restaDeFloats(float operador1, float operador2, float* resultadoResta);
int utn_multiplicacionDeFloats(float operador1, float operador2, float* resultadoMultiplicacion);
int utn_divisionDeFloats(float operador1, float operador2, float* resultadoDivision);
int utn_calculoFactoriales(float operador1, float operador2, int* resultadoFactorialA, int* resultadoFactorialB);




#endif /* UTN_FUNCIONES_PROPIAS_H_ */
