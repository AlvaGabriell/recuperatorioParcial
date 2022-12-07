/*
 * servicio.c
 *
 *  Created on: 7 dic. 2022
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
int SERVI_inicializarArray(eServicio empleados[], int tam)
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
int SERVI_buscarArrayLibre(eServicio empleados[],int tam)
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


eServicio SERVI_pedirDatoHoja(int id)
{
	eServicio aux;
	aux.idHoja=id;
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese el id del vehiculo", &aux.vehiculoId, 3, 1, 300);
	UTN_pedirCadena(aux.descipcion, "\nIngrese descripcion : ", "\nError, ingrese descripcion", 20);
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese el precio :", &aux.precioServicio, 6, 1000, 500000);
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese el dia :", &aux.fecha.dia, 2, 1, 31);
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese el mes :", &aux.fecha.mes, 2, 1, 12);
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese el anio :", &aux.fecha.anio, 4, 2020, 2022);
		aux.isEmpty=OCUPADO;

	return aux;
}

int SERVI_altaEmpleados(eServicio empleados[],int tam,int id)
{
	int todoOk=0;
	int posicionLibre;
	eServicio empleado;

	if(empleados!=NULL&&tam>0)
	{
		posicionLibre=SERVI_buscarArrayLibre(empleados, tam);
		empleado=SERVI_pedirDatoHoja(id);
		if(posicionLibre!=-1)
		{
			empleados[posicionLibre]=empleado;
			todoOk=1;
		}
	}
	return todoOk;
}

void SERVI_mostrarEmpleado(eServicio empleado)
{
	printf("\n%3d     %d      %s          %d         %d/%d/%d",empleado.idHoja,empleado.vehiculoId,empleado.descipcion,empleado.precioServicio,
			empleado.fecha.dia,empleado.fecha.mes,empleado.fecha.anio);
}

int SERVI_mostrarEmpleados(eServicio empleados[],int tam)
{
	int todoOk=0;
	if(empleados!=NULL&&tam>0)
	{
		printf("\n  IDHOJA       VEHICULOID         DESCRIPCION            PRECIO 		FECHA");
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO)
			{
				SERVI_mostrarEmpleado(empleados[i]);
			}
		}
	}

	return todoOk;
}

eServicio SERVI_buscarUnoPorId(eServicio empleados[],int tam,int id)
{
	eServicio aux;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].vehiculoId==id)
			{
				aux=empleados[i];
				break;
			}
		}
	}
	return aux;
}


int SERVI_buscarPosicionPorId(eServicio empleados[],int tam,int id)
{
	int aux;
	aux=-1;
	if(empleados!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO&&empleados[i].vehiculoId==id)
			{
				aux=i;
				break;
			}
		}
	}
	return aux;
}
