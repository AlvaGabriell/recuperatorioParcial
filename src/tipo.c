/*
 * tipo.c
 *
 *  Created on: 6 dic. 2022
 *      Author: Usuario
 */
#include "nexo.h"
#define OCUPADO 0
#define LIBRE 1
void TIPO_mostrarEmpleado(eTipo empleado)
{
	printf("\n%3d     %s",
			empleado.idTipo,
			empleado.descripcion);
}
/// @brief muestro el array de estructuras
///
/// @param empleados estructura que muestro
/// @param tam tamaño de la estructura
/// @return retorno 1 si salio bien
int TIPO_mostrarEmpleados(eTipo empleados[],int tam)
{
	int todoOk=0;
	if(empleados!=NULL&&tam>0)
	{
		printf("\n  ID       NOMBRE         POSICION            NUMERO CAMISETA 		ID CONFEDERACION 		SALARIO 		ANIOS CONTRATO");
		for(int i=0;i<tam;i++)
		{
			TIPO_mostrarEmpleado(empleados[i]);

		}
	}

	return todoOk;
}



eTipo TIPO_buscarSecPorId(eTipo listaSec[],int tamSec,int id)
{
	eTipo aux;
	for(int i=0;i<tamSec;i++)
	{
		if(listaSec[i].idTipo==id)
		{
			aux=listaSec[i];
			break;
		}
	}
	return aux;
}
