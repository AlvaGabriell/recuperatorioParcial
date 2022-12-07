/*
 * vehiculo.c
 *
 *  Created on: 7 dic. 2022
 *      Author: Usuario
 */


/*
 * jugador.c
 *
 *  Created on: 25 oct. 2022
 *      Author: Usuario
 */
#include "nexo.h"
#define OCUPADO 0
#define LIBRE 1
/// @brief inicializo array de estrucutras
///
/// @param empleados la estructura a inicializar
/// @param tam tamaño de la estrucutra
/// @return retorno 1 si estuvo salio bien.
int PLAYER_inicializarArray(eVehiculo empleados[], int tam)
{
	int todoOk=0;

	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			empleados[i].isEmpty=LIBRE;
			todoOk=1;
		}
	}
	return todoOk;
}
/// @brief busco un lugar libre en el array de estructuras
///
/// @param empleados estructura donde busco el lugar libre
/// @param tam tamaño de la estrucutra
/// @return retorno una posicion libre si se encontro
int PLAYER_buscarArrayLibre(eVehiculo empleados[],int tam)
{
	int retorno=-1;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==LIBRE)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
/// @brief pido datos para cargar a una estrucutra
///
/// @param id id que cargo desde el main para que sea autoincremental
/// @return retorno la estructura
eVehiculo PLAYER_pedirDatoEmpleado(int id)
{
	eVehiculo aux;
	aux.idVehiculo=id;
	UTN_pedirCadenaSolotexto("\nIngrese descripcion del vehiculo :", aux.descripcion,25);
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese anio modelo del vehiculo :", &aux.idVehiculo, 4, 1900, 2022);
	UTN_pedirCadenaSolotexto("\nIngrese color del vehiculo :", aux.color,25);
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese id del tipo :", &aux.idVehiculo, 1, 1, 3);
	aux.isEmpty=OCUPADO;
	return aux;
}
/// @brief cargo los datos al array de estructura
///
/// @param empleados la estructura donde los cargo
/// @param tam tamaño de la estructura
/// @param id id autoincremental desde el main
/// @return retorno 1 si si salio bien
int PLAYER_altaEmpleados(eVehiculo empleados[],int tam,int id)
{
	int todoOk=0;
	int posicionLibre;
	eVehiculo empleado;

	if(empleados!=NULL&&tam>0)
	{
		posicionLibre=PLAYER_buscarArrayLibre(empleados, tam);
		empleado=PLAYER_pedirDatoEmpleado(id);
		if(posicionLibre!=-1)
		{
			empleados[posicionLibre]=empleado;
			todoOk=1;
		}
	}
	return todoOk;
}
/// @brief muestro una estructura
///
/// @param empleado estructura a mostrar
void PLAYER_mostrarEmpleado(eVehiculo empleado)
{
	printf("\n%3d     %s      %d          %s        %d",
			empleado.idVehiculo,
			empleado.descripcion,
			empleado.anioModelo,
			empleado.color,
			empleado.tipoId);
}
/// @brief muestro el array de estructuras
///
/// @param empleados estructura que muestro
/// @param tam tamaño de la estructura
/// @return retorno 1 si salio bien
int PLAYER_mostrarEmpleados(eVehiculo empleados[],int tam)
{
	int todoOk=0;
	if(empleados!=NULL&&tam>0)
	{
		printf("\n  ID       NOMBRE         POSICION            NUMERO CAMISETA 		ID CONFEDERACION 		SALARIO 		ANIOS CONTRATO");
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO)
			{
				PLAYER_mostrarEmpleado(empleados[i]);
			}
		}
	}

	return todoOk;
}
///@brief busco uno por id en la estructura
///
/// @param empleados estructura donde busco
/// @param tam tamanio de la estrucutra
/// @param id de referencia para buscar en la estructura
/// @return retorno una estructura desde la posicion
eVehiculo PLAYER_buscarUnoPorId(eVehiculo empleados[],int tam,int id)
{
	eVehiculo aux;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].idVehiculo==id)
			{
				aux=empleados[i];
				break;
			}
		}
	}
	return aux;
}
/// @brief busco posicion por id en la estructura
///
/// @param empleados estructura donde busco posicion
/// @param tam tamaño de la estructura
/// @param id indice para buscar en la estructura
/// @return retorno el indice si se encontro
int PLAYER_buscarPosicionPorId(eVehiculo empleados[],int tam,int id)
{
	int aux;
	aux=-1;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO&&empleados[i].idVehiculo==id)
			{
				aux=i;
				break;
			}
		}
	}
	return aux;
}
