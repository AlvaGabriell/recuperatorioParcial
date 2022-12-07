/*
 ============================================================================
 Name        : recuperatorio_Parcial1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "nexo.h"
#define TAM_VEHICULOS 3000
#define TAM_TIPOS 3
#define TAM_SERVICIO 3000


int main(void) {
	setbuf(stdout,NULL);
	int id=1;
	int idHoja=2000;
	eTipo tipos[3]={{1000,"SEDAN 3PTAS"},{1001,"SEDAN 5PTAS"},{1002,"CAMIONETA"}};
	eVehiculo jugadores[TAM_VEHICULOS];
	eServicio servicios[TAM_SERVICIO];
	char respuesta='n';

	PLAYER_inicializarArray(jugadores, TAM_VEHICULOS);
	SERVI_inicializarArray(servicios, TAM_SERVICIO);

	while(respuesta=='n')
		{
			switch(mostrarMenuP())
			{
			case 1:
				NEXO_altaEmpleados(jugadores, TAM_VEHICULOS, id, tipos, TAM_TIPOS);
				id++;
				break;
			case 2:
				NEXO_modificarVehi(jugadores, TAM_VEHICULOS, tipos, TAM_TIPOS, id, servicios, TAM_SERVICIO);
				break;
			case 3:
				NEXO_darDebajaEmpleado(jugadores, respuesta, tipos,TAM_TIPOS);
				break;
			case 4:
				NEXO_mostrarEmpleados(jugadores, respuesta, tipos, TAM_TIPOS);
				break;
			case 5:
				TIPO_mostrarEmpleados(tipos, TAM_TIPOS);
				break;
			case 6:
				SERVI_altaEmpleados(servicios, TAM_SERVICIO, idHoja);
				idHoja++;
				break;
			case 7:
				SERVI_mostrarEmpleados(servicios, TAM_SERVICIO);
				break;
			case 8:
				nexo_informes(jugadores, TAM_VEHICULOS, tipos, TAM_TIPOS, servicios, TAM_SERVICIO);
				break;
			case 9:
				respuesta='s';
				break;
			default:
				printf("\nOpcion invalida");
				fflush(stdin);
			}
		}
	return EXIT_SUCCESS;
}
