/*
 * nexo.c
 *
 *  Created on: 6 dic. 2022
 *      Author: Usuario
 */

#include "nexo.h"
/*
 * jugador.c
 *
 *  Created on: 25 oct. 2022
 *      Author: Usuario
 */
#include "nexo.h"
#define OCUPADO 0
#define LIBRE 1

/// @brief pido datos para cargar a una estrucutra
///
/// @param id id que cargo desde el main para que sea autoincremental
/// @return retorno la estructura
eVehiculo NEXO_pedirDatoEmpleado(int id, eTipo tipos[],int tamT)
{
	eVehiculo aux;
	aux.idVehiculo=id;
	UTN_pedirCadenaSolotexto("\nIngrese descripcion o modelo del auto :", aux.descripcion,15);
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese anio modelo :", &aux.anioModelo, 4, 1900, 2022);
	UTN_pedirCadenaSolotexto("\nIngrese color del auto :", aux.color,15);
	TIPO_mostrarEmpleados(tipos, tamT);
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese id del tipo :", &aux.tipoId, 4, 1000, 1002);
	aux.isEmpty=OCUPADO;
	return aux;
}
/// @brief cargo los datos al array de estructura
///
/// @param empleados la estructura donde los cargo
/// @param tam tamaño de la estructura
/// @param id id autoincremental desde el main
/// @return retorno 1 si si salio bien
int NEXO_altaEmpleados(eVehiculo empleados[],int tam,int id,eTipo tipos [], int tamT)
{
	int todoOk=0;
	int posicionLibre;
	eVehiculo empleado;

	if(empleados!=NULL&&tam>0)
	{
		posicionLibre=PLAYER_buscarArrayLibre(empleados, tam);
		empleado=NEXO_pedirDatoEmpleado(id,tipos,tamT);
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
void NEXO_mostrarEmpleado(eVehiculo empleado, eTipo tipos[],int tamT )
{
	eTipo aux;
	int id;
	id=empleado.tipoId;
	aux=TIPO_buscarSecPorId(tipos, tamT, id);
	printf("\n%3d     %s      %d    %s     %s",
			empleado.idVehiculo,
			empleado.descripcion,
			empleado.anioModelo,
			empleado.color,
			aux.descripcion);
}
/// @brief muestro el array de estructuras
///
/// @param empleados estructura que muestro
/// @param tam tamaño de la estructura
/// @return retorno 1 si salio bien
int NEXO_mostrarEmpleados(eVehiculo empleados[],int tam,eTipo tipos[],int tamT)
{
	int todoOk=0;
	if(empleados!=NULL&&tam>0)
	{
		printf("\n  ID       NOMBRE         POSICION            NUMERO CAMISETA 		ID CONFEDERACION 		SALARIO 		ANIOS CONTRATO");
		for(int i=0;i<tam;i++)
		{
			if(empleados[i].isEmpty==OCUPADO)
			{
				NEXO_mostrarEmpleado(empleados[i],tipos,tamT);
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
eVehiculo NEXO_buscarUnoPorId(eVehiculo empleados[],int tam,int id)
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
int NEXO_buscarPosicionPorId(eVehiculo empleados[],int tam,int id)
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

int NEXO_darDebajaEmpleado(eVehiculo empleados[],int tam,eTipo tipos[],int tamT)
{
	int todoOk=-1;
	int id;
	int posicion;
	if(empleados!=NULL&&tam>0&&tipos!=NULL&&tamT>0)
	{
		printf("\n\t\t******BAJA DE EMPLEADOS******");
		NEXO_mostrarEmpleados(empleados, tam, tipos, tamT);
		UTN_pedirCadenaSoloNumRangoINT("\nSeleccione un id : ", &id, 4, 1, 3000);
		posicion=PLAYER_buscarPosicionPorId(empleados, tam, id);
		while(posicion==-1)
		{
			NEXO_mostrarEmpleados(empleados, tam, tipos, tamT);
			UTN_pedirCadenaSoloNumRangoINT("\nId no encontrado, seleccione id : ", &id, 4, 1, 3000);
			posicion=PLAYER_buscarPosicionPorId(empleados, tam, id);
		}
		if(validarSalida("\nSeguro que desea eliminar ? [S/N]", "Letra ingresada incorrecta , vuelva a intentar [S/N]")!='s')
		{
			printf("\nOperacion cancelada...");
		}else
			{
				empleados[posicion].isEmpty=LIBRE;
				printf("\nEliminacion exitosa.!!!");
			}
		todoOk=1;
	}
	return todoOk;
}


int NEXO_modificarVehi(eVehiculo vehiculos[],int tamV,eTipo tipos[],int tamTipo, int id,eServicio servicios[], int tamServicio)
{
	int rta;
	int todoOk=0;
	int idPos;
	int posicion;
	int posicionServi;
	printf("\n\t\t******MODIFICACION DE VEHICULOS******");
	NEXO_mostrarEmpleados(vehiculos, tamV, tipos, tamTipo);
	idPos=UTN_pedirCadenaSoloNumRangoINT("\nIngrese un id: ", &idPos, 4, 1, 3000);

	posicion=PLAYER_buscarPosicionPorId(vehiculos, tamV, idPos);
	posicionServi=SERVI_buscarPosicionPorId(servicios, tamServicio, idPos);
	if(posicion!=-1)
	{
		printf("\nQue desea modificar ? \n1- descripcion\n2- precio");
		scanf("%d",&rta);
		switch(rta)
		{
			case 1:
				UTN_pedirCadenaSolotexto("\nIngrese descripcion o modelo del auto :", tipos[posicion].descripcion,15);
				break;
			case 2:
				UTN_pedirCadenaSoloNumRangoINT("\nIngrese precio ",&servicios[posicionServi].precioServicio , 4, 1000, 500000);
				break;
			default:
				printf("\nOpcion invalida.");
				break;
		}
	}
		todoOk=1;
	return todoOk;
}



int nexo_imprimirTipos(eVehiculo listaVehiculo[], int tam, eTipo tipos[],int tamT)
{
	int todoOk=0;
	int idTipo;
	TIPO_mostrarEmpleados(tipos, tamT);
	UTN_pedirCadenaSoloNumRangoINT("Ingrese id", &idTipo, 4, 2000, 2003);
	for(int i = 0; i < tam; i++)
	{
		if(listaVehiculo[i].tipoId==idTipo&&listaVehiculo[i].isEmpty==OCUPADO)
		{
			NEXO_mostrarEmpleado(listaVehiculo[i], tipos, tamT);
		}
	}
	todoOk = 1;
	return todoOk;
}

int nexo_informes(eVehiculo listaVehiculo[], int tam, eTipo tipos[],int tamT,eServicio servicios[],int tamS)
{
	int todoOk=0;
	switch(mostrarMenuInformes())
	{
	case 1:
		nexo_imprimirTipos(listaVehiculo, tamT, tipos, tamT);
		break;
	case 2:
		nexo_imprimirPorFechaSeleccion(servicios, tamS);
		break;
	case 3:
		nexo_imprimirPorIdAuto(servicios, tamS, listaVehiculo, tam, tipos, tamT);
		break;
	case 4:
		nexo_imprimirAcumPorFecha(servicios, tamS);
		break;
	case 5:
		printf("\nOperacion cancelada.");
		break;
	}

	return todoOk;
}

int nexo_imprimirPorFechaSeleccion(eServicio servicios[], int tamS)
{
	int todoOk=0;
	int dia;
	int mes;
	int anio;

	printf("\nIngrese Fecha");
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese el dia :", &dia, 2, 1, 31);
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese el mes :", &mes, 2, 1, 12);
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese el anio :", &anio, 4, 2020, 2022);
	for(int i = 0; i < tamS; i++)
	{
		if(servicios[i].fecha.dia==dia&&servicios[i].fecha.mes==mes&&servicios[i].fecha.anio==anio)
		{
			SERVI_mostrarEmpleado(servicios[i]);
		}
	}
	todoOk = 1;
	return todoOk;
}


int nexo_imprimirAcumPorFecha(eServicio servicios[], int tamS)
{
	int todoOk=0;
	int dia;
	int mes;
	int anio;
	int acumulador=0;
	printf("\nIngrese Fecha");
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese el dia :", &dia, 2, 1, 31);
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese el mes :", &mes, 2, 1, 12);
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese el anio :", &anio, 4, 2020, 2022);
	for(int i = 0; i < tamS; i++)
	{
		if(servicios[i].fecha.dia==dia&&servicios[i].fecha.mes==mes&&servicios[i].fecha.anio==anio&&servicios[i].isEmpty==OCUPADO)
		{
			acumulador+=servicios[i].precioServicio;
		}
	}
	printf("\nel precio acumulado de la fecha ingresada es : %d",acumulador);
	todoOk = 1;
	return todoOk;
}


int nexo_imprimirPorIdAuto(eServicio servicios[], int tamS,eVehiculo vehiculos[],int tamV,eTipo tipos[],int tamT)
{
	int todoOk=0;
	int id;
	int acum=0;
	NEXO_mostrarEmpleados(vehiculos, tamV, tipos, tamT);
	UTN_pedirCadenaSoloNumRangoINT("\nIngrese el id :", &id, 4, 1, 3000);
	for(int i = 0; i < tamS; i++)
	{
		if(servicios[i].vehiculoId==id&&servicios[i].isEmpty==OCUPADO)
		{
			acum+=servicios[i].precioServicio;
		}
	}
	printf("\nEl precio acumulado por el id ingresado es de %d",acum);
	todoOk = 1;
	return todoOk;
}


