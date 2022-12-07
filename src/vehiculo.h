/*
 * vehiculo.h
 *
 *  Created on: 7 dic. 2022
 *      Author: Usuario
 */

#ifndef VEHICULO_H_
#define VEHICULO_H_
typedef struct
{
	int idVehiculo;
	char descripcion[50];
	int anioModelo;
	char color[10];
	int tipoId;
	int isEmpty;
}eVehiculo;

#endif /* VEHICULO_H_ */
int PLAYER_inicializarArray(eVehiculo empleados[], int tam);
int PLAYER_buscarArrayLibre(eVehiculo empleados[],int tam);
eVehiculo PLAYER_pedirDatoEmpleado(int id);
int PLAYER_altaEmpleados(eVehiculo empleados[],int tam,int id);
void PLAYER_mostrarEmpleado(eVehiculo empleado);
int PLAYER_mostrarEmpleados(eVehiculo empleados[],int tam);
eVehiculo PLAYER_buscarUnoPorId(eVehiculo empleados[],int tam,int id);
int PLAYER_buscarPosicionPorId(eVehiculo empleados[],int tam,int id);
